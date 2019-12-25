#include "slave.h"
#include <sys/socket.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

void slave___::start__(const char* filename, const char* args) {
	const char* argv[40];
	argv[0] = filename;
	int i1 = 1;
	if(args) {
		Glib::ustring* s = new Glib::ustring();
		for(int i = 0;; i++) {
			char c = args[i];
			if(!c || c == ' ') {
				argv[i1++] = (*s).c_str();
				if(!c)
					break;
				s = new Glib::ustring();
				continue;
			}
			switch(c) {
			case '"': case '\'':
				for(;;) {
					char c1 = args[++i];
					if(c1 == c)
						break;
					if(!c1)
						return;
					*s += c1;
				}
				continue;
			}
			*s += c;
		}
	}
	argv[i1] = NULL;
	
	if(socketpair(AF_UNIX, SOCK_STREAM, 0, sv_) == -1)
		return;
	if(loop_.empty())
		return;
	in_ = Glib::signal_io().connect(loop_, sv_[0], Glib::IO_IN);

	pid_t pid = fork();
	if (pid == -1)
		return;
	if (pid == 0) {
		struct sigaction act;
		memset(&act, 0, sizeof(act));
		sigfillset(&act.sa_mask);
		act.sa_handler = SIG_IGN;
		sigaction(SIGHUP, &act, NULL);
		sigaction(SIGINT, &act, NULL);
		sigaction(SIGQUIT, &act, NULL);
		sigaction(SIGPIPE, &act, NULL);
		sigaction(SIGTERM, &act, NULL);
		sigaction(SIGBUS, &act, NULL);
		sigaction(SIGFPE, &act, NULL);
		sigaction(SIGILL, &act, NULL);
		sigaction(SIGSEGV, &act, NULL);
		sigaction(SIGSYS, &act, NULL);
		sigaction(SIGXCPU, &act, NULL);
		sigaction(SIGXFSZ, &act, NULL);
		sigaction(SIGHUP, &act, NULL);

		sigset_t set;
		if(sigfillset(&set) == -1)
			return;
		if(sigprocmask(SIG_SETMASK, &set, NULL) == -1)
			return;
		sigemptyset(&set);
		sigprocmask(SIG_SETMASK, &set, NULL);

		close(sv_[0]);
		if(dup2(sv_[1], STDIN_FILENO) == -1)
			return;
		if(dup2(sv_[1], STDOUT_FILENO) == -1)
			return;
		if(dup2(sv_[1], STDERR_FILENO) == -1)
			return;
		close(sv_[1]);
		if(setpgid(0, 0) == -1)
			return;
		if(execvp(argv[0], (char* const*)argv) == -1)
			return;
	} 
	pid_ = pid;

	close(sv_[1]);
	sv_[1] = -1;
	fd_set set;
	FD_ZERO(&set);
	FD_SET(sv_[0], &set);
	if(select(sv_[0] + 1, NULL, &set, NULL, NULL) == -1)
		return;
	fcntl(sv_[0], F_SETFL, fcntl(sv_[0], F_GETFL, 0) | O_NONBLOCK);
	wait_ = Glib::signal_child_watch().connect(sigc::mem_fun(*this, &slave___::wait__), pid);
	is_run_ = true;
}

void slave___::wait__(GPid pid, int) {
	if(pid_ != -1) {
		in_.disconnect();
		waitpid(pid_, NULL, 0);
		pid_ = -1;
		is_run_ = false;
	}
}

void slave___::stop__() {
	if(pid_ != -1) {
		in_.disconnect();
		wait_.disconnect();
		for(;;) {
			kill(-pid_, SIGKILL);
			if(waitpid(-pid_, NULL, WNOHANG) == -1)
				break;
		}
		pid_ = -1;	
	}
	is_run_ = false;
}

void slave___::send__(const char* s) {
	if(!is_run__() || !s)
		return;
	if(write(sv_[0], s, strlen(s)) == -1)
		return;
}

