#ifndef TEMPLATEPLUGIN_POINT_CLOUD_TRANSPORT_TEMPLATEPLUGIN_SUBSCRIBER_H
#define TEMPLATEPLUGIN_POINT_CLOUD_TRANSPORT_TEMPLATEPLUGIN_SUBSCRIBER_H

#include "point_cloud_transport/simple_subscriber_plugin.h"
#include <dynamic_reconfigure/server.h>

//
#include <templateplugin_point_cloud_transport/CustomMessage.h>
//
#include <templateplugin_point_cloud_transport/TemplatepluginSubscriberConfig.h>

//
namespace templateplugin_point_cloud_transport {

//
class TemplatepluginSubscriber : public point_cloud_transport::SimpleSubscriberPlugin<templateplugin_point_cloud_transport::CustomMessage>
{
public:
  //
  virtual ~TemplatepluginSubscriber() {}

  virtual std::string getTransportName() const
  {
    //
    return "templateplugin";
  }

  virtual void shutdown();

protected:
  // Overridden to set up reconfigure server
  virtual void subscribeImpl(ros::NodeHandle& nh, const std::string& base_topic, uint32_t queue_size,
          const Callback& callback, const ros::VoidPtr& tracked_object,
          const point_cloud_transport::TransportHints& transport_hints);

  //
  virtual void internalCallback(const templateplugin_point_cloud_transport::CustomMessageConstPtr& message,
                                const Callback& user_cb);

  //
  typedef templateplugin_point_cloud_transport::TemplatepluginSubscriberConfig Config;
  typedef dynamic_reconfigure::Server<Config> ReconfigureServer;
  boost::shared_ptr<ReconfigureServer> reconfigure_server_;
  Config config_;

  void configCb(Config& config, uint32_t level);
};

} //namespace templateplugin_point_cloud_transport

#endif // TEMPLATEPLUGIN_POINT_CLOUD_TRANSPORT_TEMPLATEPLUGIN_SUBSCRIBER_H