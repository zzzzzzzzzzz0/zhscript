#ifndef glibmmm_h_
#define glibmmm_h_

#include <glib.h>
#include <sigc++/sigc++.h>
#include <string>

namespace Glib
{

enum IOCondition
{
  IO_IN   = G_IO_IN,
  IO_OUT  = G_IO_OUT,
  IO_PRI  = G_IO_PRI,
  IO_ERR  = G_IO_ERR,
  IO_HUP  = G_IO_HUP,
  IO_NVAL = G_IO_NVAL
};

class ustring : public std::string {
public:
	ustring() : std::string() {}
	ustring(const char* s) : std::string(s) {}
};

class SignalIO
{
public:
  sigc::connection connect(const sigc::slot<bool,IOCondition>& slot, int fd,
                           IOCondition condition);
};

class SignalChildWatch
{
public:
  sigc::connection connect(
    const sigc::slot<void, GPid, int>& slot, GPid pid);
};

SignalIO signal_io();
SignalChildWatch signal_child_watch();

}

#endif
