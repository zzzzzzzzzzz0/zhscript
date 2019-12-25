#ifdef ver_glibmmm_
#include "glibmmm.h"

namespace Glib
{

class SourceConnectionNode
{
public:
  explicit inline SourceConnectionNode(const sigc::slot_base& slot);

  static void* notify(void* data);
  static void  destroy_notify_callback(void* data);

  inline void install(GSource* source);
  inline sigc::slot_base* get_slot();

private:
  sigc::slot_base slot_;
  GSource* source_;
};

inline
SourceConnectionNode::SourceConnectionNode(const sigc::slot_base& slot)
:
  slot_ (slot),
  source_ (0)
{
  slot_.set_parent(this, &SourceConnectionNode::notify);
}

void* SourceConnectionNode::notify(void* data)
{
  SourceConnectionNode *const self = static_cast<SourceConnectionNode*>(data);

  // if there is no object, this call was triggered from destroy_notify_handler(),
  // because we set self->source_ to 0 there:
  if (self->source_)
  {
    GSource* s = self->source_;  
    self->source_ = 0;
    g_source_destroy(s);

    // Destroying the object triggers execution of destroy_notify_handler(),
    // eiter immediately or later, so we leave that to do the deletion.
  }

  return 0;
}

// static
void SourceConnectionNode::destroy_notify_callback(void* data)
{
  SourceConnectionNode *const self = static_cast<SourceConnectionNode*>(data);

  if (self)
  {
    // The GLib side is disconnected now, thus the GSource* is no longer valid.
    self->source_ = 0;

    delete self;
  }
}

inline
void SourceConnectionNode::install(GSource* source)
{
  source_ = source;
}

inline
sigc::slot_base* SourceConnectionNode::get_slot()
{
  return &slot_;
}


static gboolean
glibmm_child_watch_callback(GPid pid, gint child_status, void* data)
{
  SourceConnectionNode* const conn_data = static_cast<SourceConnectionNode*>(data);

  /*try
  {
    // Recreate the specific slot from the generic slot node.
    (*static_cast<sigc::slot<void(GPid, int)>*>(conn_data->get_slot()))(pid, child_status);
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }*/
  return 0;
}


sigc::connection SignalIO::connect(const sigc::slot<bool,IOCondition>& slot,
                                   int fd, IOCondition condition)
{
  /*const Glib::RefPtr<IOSource> source = IOSource::create(fd, condition);
  const sigc::connection connection = source->connect(slot);
  g_source_attach(source->gobj(), context_);*/

	//IOSource::connect
	//connect_generic(
	//SourceConnectionNode::get_slot
	const sigc::connection connection ((sigc::slot_base&)slot);

  return connection;
}

sigc::connection SignalChildWatch::connect(const sigc::slot<void, GPid, int>& slot,
                                        GPid pid)
{
  SourceConnectionNode *const conn_node = new SourceConnectionNode(slot);
  const sigc::connection connection(*conn_node->get_slot());
  GSource *const source = g_child_watch_source_new(pid);
  g_source_set_callback(
      source, (GSourceFunc)&glibmm_child_watch_callback, conn_node,
      &SourceConnectionNode::destroy_notify_callback);
  conn_node->install(source);
  //g_source_attach(source, context_);
  g_source_unref(source);

  return connection;
}

SignalIO signal_io()
{
  return SignalIO(/*0*/); // 0 means default context
}
SignalChildWatch signal_child_watch() {
	return SignalChildWatch();
}

}

#endif
