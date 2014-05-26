#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <libgen.h>
#include <pthread.h>

#ifdef ver_pidgin_lwqq_
#include "lwqq.h"
#include "lwjs.h"
#else
#include "login.h"
#include "logger.h"
#include "info.h"
#include "smemory.h"
#include "msg.h"
#endif

#define bool int
#include "def1.h"
static void* jsq_;
static callback3_2___ cb_;
static callback2_2___ cb2_;
static void* main_qu_;
static char *new_msg_code_ = NULL, *face_code_ = NULL, *vc_code_ = NULL;
void init__(void* jsq, callback3_2___ cb, callback2_2___ cb2, void* main_qu) {
	jsq_ = jsq;
	cb_ = cb;
	cb2_ = cb2;
	main_qu_ = main_qu;
}

static void malloc__(char** p, const char* s) {
    if(*p)
    	free(*p);
    *p = malloc(strlen(s) + 1);
    strcpy(*p, s);
}
static void free__(char** p) { 
    if(*p) {
    	free(*p);
    	*p = NULL;
    }
}

static LwqqClient *lc = NULL;

void list__(int* err, void* shangji, char *user, const char* code)
{
	int argc;
    const char* argv[3];

    LwqqBuddy *buddy;
    LIST_FOREACH(buddy, &lc->friends, entries) {
        if (!buddy->uin) {
            /* BUG */
            continue;
        }
        if (!user || !strcmp(buddy->uin, user)) {
        	argc = 0;
	        argv[argc++] = buddy->uin;
            if (buddy->nick) {
                 argv[argc++] = buddy->nick;
            }
            if (buddy->markname) {
                argv[argc++] = buddy->markname;
            }
            cb_(jsq_, shangji, err, NULL, code, 0, NULL, argc, argv, 0);
            if(*err) {
            	return;
            }
            if(user)
            	break;
        }
    }
}

void qun_list__(int* err, void* shangji, char *user, const char* code)
{
	int argc;
    const char* argv[3];

    LwqqGroup *buddy;
    LIST_FOREACH(buddy, &lc->groups, entries) {
        if (!buddy->gid) {
            continue;
        }
        if (!user || strcmp(buddy->gid, user) == 0) {
        	argc = 0;
	        argv[argc++] = buddy->gid;
            if (buddy->name) {
                 argv[argc++] = buddy->name;
            }
            if (buddy->markname) {
                argv[argc++] = buddy->markname;
            }
            cb_(jsq_, shangji, err, NULL, code, 0, NULL, argc, argv, 0);
            if(*err) {
            	return;
            }
            if(user)
            	break;
        }
    }
}

void send__(char *user, char* msg)
{
    /* argv look like: {"send", "74357485" "hello"} */
#ifdef ver_pidgin_lwqq_
    lwqq_msg_send_simple(lc, LWQQ_MS_BUDDY_MSG, user, msg);
#else
    lwqq_msg_send2(lc, user, msg);
#endif
}

static char *get_vc(char* vc_file)
{
    char vc[128] = {0};
    int vc_len;
    FILE *f;

    if ((f = fopen(vc_file, "r")) == NULL) {
        return NULL;
    }

    if (!fgets(vc, sizeof(vc), f)) {
        fclose(f);
        return NULL;
    }
    
    vc_len = strlen(vc);
    if (vc[vc_len - 1] == '\n') {
        vc[vc_len - 1] = '\0';
    }
    return s_strdup(vc);
}

static char* vc__(char* vc_image) {
	char vc_file[128];
    snprintf(vc_file, sizeof(vc_file), "/tmp/lwqq_%s.txt", lc->username);
    /* Delete old verify image */
    unlink(vc_file);

	int err;
	cb2_(jsq_, main_qu_, &err, NULL, vc_code_, 0, NULL, 2, vc_image, vc_file);

    lwqq_log(LOG_NOTICE, "Need verify code to login, please check "
             "image file %s, and input what you see to file %s\n",
             vc_image, vc_file);
    while (1) {
        if (!access(vc_file, F_OK)) {
            sleep(1);
            break;
        }
        sleep(1);
    }
	return get_vc(vc_file);
}

static LwqqErrorCode cli_login()
{
    LwqqErrorCode err;

#ifdef ver_pidgin_lwqq_
    LWQQ_SYNC_BEGIN(lc);
	lwqq_login(lc, LWQQ_STATUS_ONLINE, &err);
#else
    lwqq_login(lc, &err);
#endif
#ifdef ver_pidgin_lwqq_
#else
    if (err == LWQQ_EC_LOGIN_NEED_VC) {
		char vc_image[128];
		snprintf(vc_image, sizeof(vc_image), "/tmp/lwqq_%s.jpeg", lc->username);
        lc->vc->str = vc__(vc_image);
        if (lc->vc->str) {
		    lwqq_log(LOG_NOTICE, "Get verify code: %s\n", lc->vc->str);
		    lwqq_login(lc, &err);
        }
    }
#endif
#ifdef ver_pidgin_lwqq_
    LWQQ_SYNC_END(lc);
#endif
    return err;
}

static void cli_logout(LwqqClient *lc)
{
    LwqqErrorCode err;
    
    lwqq_logout(lc, &err);
    if (err != LWQQ_EC_OK) {
        lwqq_log(LOG_DEBUG, "Logout failed\n");        
    } else {
        lwqq_log(LOG_DEBUG, "Logout sucessfully\n");
    }
}

static unsigned long new_msg_num_;
static void handle_new_msg(LwqqRecvMsg *recvmsg)
{
    int err;
    char buf1[8], buf2[32], buf3[32], buf4[32];
    char* buff1 = NULL;
    const char* argv[16] = {buf4, buf1};
	int argc = 2;
	sprintf(buf4, "%lu", ++new_msg_num_);
	
#ifdef ver_pidgin_lwqq_
	int msg_type = recvmsg->msg->type;
	switch(lwqq_mt_bits(msg_type)) {
	case LWQQ_MT_MESSAGE:
		switch (msg_type) {
		case LWQQ_MS_BUDDY_MSG:
		case LWQQ_MS_GROUP_MSG:
		{
			switch (msg_type) {
            case LWQQ_MS_GROUP_MSG:
            case LWQQ_MS_DISCU_MSG:
			    strcpy(buf1, "qun-msg");
			    break;
            case LWQQ_MS_SESS_MSG:
			    strcpy(buf1, "sess-msg");
			    break;
			default:
			    strcpy(buf1, "msg");
			    break;
			}
		    argv[argc++] = NULL;
		    argv[argc++] = buff1 = malloc(8192);
			argv[argc++] = buf3;
		    argv[argc++] = NULL;
		    LwqqMsgContent *c;
		    LwqqMsgMessage *mmsg = (LwqqMsgMessage*)recvmsg->msg;
		    buff1[0] = 0;
		    TAILQ_FOREACH(c, &mmsg->content, entries) {
		    	if(mmsg->buddy.from->uin)
		        	argv[2] = mmsg->buddy.from->uin;
		        if (c->type == LWQQ_CONTENT_STRING) {
		            strcat(buff1, c->data.str);
		        } else {
		            sprintf (buf2, "%d", c->data.face);
		            strcat(buff1, cb2_(jsq_, main_qu_, &err, NULL, face_code_, 0, NULL, 1, buf2));
		        }
		        sprintf (buf3, "%ld", mmsg->time);
		        if(mmsg->discu.did)
					argv[5] = mmsg->discu.did;
		    }
		    break;
		}
		}
		break;
    case LWQQ_MT_STATUS_CHANGE:
    {
        strcpy(buf1, "status");
        LwqqMsgStatusChange *status = (LwqqMsgStatusChange*)recvmsg->msg;
        argv[argc++] = status->who;
        argv[argc++] = status->status;
        break;
    }
    default:
	    sprintf(buf1, "%d", msg_type);
        strcpy(buf2, "unknow message");
        argv[argc++] = buf2;
        break;
    }
#else
    LwqqMsg *msg = recvmsg->msg;
    
    switch (msg->type) {
    case LWQQ_MT_BUDDY_MSG:
    case LWQQ_MT_GROUP_MSG:
    {
		switch (msg->type) {
		case LWQQ_MT_GROUP_MSG:
	        strcpy(buf1, "qun-msg");
	        break;
		default:
	        strcpy(buf1, "msg");
	        break;
	    }
        argv[argc++] = NULL;
        argv[argc++] = buff1 = malloc(8192);
		argv[argc++] = buf3;
        argv[argc++] = NULL;
        LwqqMsgContent *c;
        LwqqMsgMessage *mmsg = msg->opaque;
        buff1[0] = 0;
        TAILQ_FOREACH(c, &mmsg->content, entries) {
        	if(mmsg->from)
            	argv[2] = mmsg->from;
            if (c->type == LWQQ_CONTENT_STRING) {
                strcat(buff1, c->data.str);
            } else {
                sprintf (buf2, "%d", c->data.face);
                strcat(buff1, cb2_(jsq_, main_qu_, &err, NULL, face_code_, 0, NULL, 1, buf2));
            }
            sprintf (buf3, "%ld", mmsg->time);
            if(mmsg->to)
				argv[5] = mmsg->to;
        }
        break;
    }
    case LWQQ_MT_STATUS_CHANGE:
    {
        strcpy(buf1, "status");
        LwqqMsgStatusChange *status = msg->opaque;
        argv[argc++] = status->who;
        argv[argc++] = status->status;
        break;
    }
    default:
	    sprintf(buf1, "%d", msg->type);
        strcpy(buf2, "unknow message");
        argv[argc++] = buf2;
        break;
    }
#endif
	cb_(jsq_, main_qu_, &err, NULL, new_msg_code_, 0, NULL, argc, argv, 0);
	if(buff1)
		free(buff1);
   
    lwqq_msg_free(recvmsg->msg);
    s_free(recvmsg);
}

#ifdef ver_pidgin_lwqq_
static void received_msg(LwqqRecvMsgList* l)
{
    LwqqRecvMsg *recvmsg;
    recvmsg = TAILQ_FIRST(&l->head);
    while(!TAILQ_EMPTY(&l->head)){
        pthread_mutex_lock(&l->mutex);
        TAILQ_REMOVE(&l->head,recvmsg, entries);
        pthread_mutex_unlock(&l->mutex);
        handle_new_msg(recvmsg);
        fflush(stdout);
    }
}
static void need_verify2(LwqqClient* lc,LwqqVerifyCode** p_code)
{
	LwqqVerifyCode* code = *p_code;
	char vc_image[128];
    snprintf(vc_image,sizeof(vc_image),"/tmp/%s.jpeg",lc->username);

    lwqq_util_save_img(code->data,code->size,vc_image,NULL);

	code->str = vc__(vc_image);
    lwqq_log(LOG_NOTICE, "Verify Code: %s\n", code->str);
	vp_do(code->cmd,NULL);
}
#else
static void *recvmsg_thread(void *list)
{
    LwqqRecvMsgList *l = (LwqqRecvMsgList *)list;

    /* Poll to receive message */
    l->poll_msg(l);

    /* Need to wrap those code so look like more nice */
    while (1) {
        LwqqRecvMsg *recvmsg;
        pthread_mutex_lock(&l->mutex);
        if (SIMPLEQ_EMPTY(&l->head)) {
            /* No message now, wait 100ms */
            pthread_mutex_unlock(&l->mutex);
            usleep(100000);
            continue;
        }
        recvmsg = SIMPLEQ_FIRST(&l->head);
        SIMPLEQ_REMOVE_HEAD(&l->head, entries);
        pthread_mutex_unlock(&l->mutex);
        handle_new_msg(recvmsg);
    }

    pthread_exit(NULL);
}
#endif

void get_friends_info__() {
#ifdef ver_pidgin_lwqq_
    lwqq_info_get_friends_info(lc,NULL,NULL);
#else
    LwqqErrorCode err;
    lwqq_info_get_friends_info(lc, &err);
#endif
}

static void *info_thread(void *lc)
{
#ifdef ver_pidgin_lwqq_
#ifdef WITH_MOZJS
    LwqqHttpRequest* req = lwqq_http_request_new("http://pidginlwqq.sinaapp.com/hash.js");
    req->do_request(req,0,NULL);
    const char* hashjs = req->response;
    lwqq_js_t* js = lwqq_js_init();
    lwqq_js_load_buffer(js,hashjs);
    lwqq_info_get_friends_info(lc,(LwqqHashFunc)lwqq_js_hash,js);
    lwqq_js_close(js);
#else
    lwqq_info_get_friends_info(lc,NULL,NULL);
#endif
    return NULL;
#else
    LwqqErrorCode err;
    lwqq_info_get_friends_info(lc, &err);
//    lwqq_info_get_all_friend_qqnumbers(lc, &err);

    pthread_exit(NULL);
#endif
}

void start__(char* buf, char *qqnumber, char *password, char* vc_code, char* new_msg_code, char* face_code)
{
    LwqqErrorCode err;
    int i;
    pthread_t tid[2];
    pthread_attr_t attr[2];

    malloc__(&vc_code_, vc_code);
#ifdef ver_pidgin_lwqq_
	lwqq_log_set_level(4);
#endif
    lc = lwqq_client_new(qqnumber, password);
#ifdef ver_pidgin_lwqq_
	 lwqq_add_event(lc->events->need_verify,
			 _C_(2p,need_verify2,lc, &lc->args->vf_image));
	 lwqq_add_event(lc->events->poll_msg,
			 _C_(p,received_msg,lc->msg_list));
#endif
    if (!lc) {
        strcpy(buf, "Create lwqq client failed");
        return;
    }

    /* Login to server */
    err = cli_login();
    switch(err) {
    case LWQQ_EC_OK:
    	break;
    default:
    	switch(err) {
    	case LWQQ_EC_LOGIN_NEED_VC:
    		break;
    	default:
    		sprintf(buf, "%d", err);
    		break;
    	}
	    lwqq_client_free(lc);
		return;
    }
    
    new_msg_num_ = 0L;
    malloc__(&new_msg_code_, new_msg_code);
    malloc__(&face_code_, face_code);

#ifdef ver_pidgin_lwqq_
    lwqq_log(LOG_NOTICE, "Login successfully\n");

    /* Create a thread to receive message */
    lwqq_msglist_poll(lc->msg_list,0);
    info_thread(lc);
#else
    /* Initialize thread */
    for (i = 0; i < 2; ++i) {
        pthread_attr_init(&attr[i]);
        pthread_attr_setdetachstate(&attr[i], PTHREAD_CREATE_DETACHED);
    }

    /* Create a thread to receive message */
    pthread_create(&tid[0], &attr[0], recvmsg_thread, lc->msg_list);

    /* Create a thread to update friend info */
    pthread_create(&tid[1], &attr[1], info_thread, lc);
#endif
}

void stop__()
{
    if(lc) {
#ifdef ver_pidgin_lwqq_
		lwqq_msglist_close(lc->msg_list);
#endif
		cli_logout(lc);
		lwqq_client_free(lc);
	}
    free__(&new_msg_code_);
	free__(&face_code_);
	free__(&vc_code_);
}
