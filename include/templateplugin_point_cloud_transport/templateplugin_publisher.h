#ifndef TEMPLATEPLUGIN_POINT_CLOUD_TRANSPORT_TEMPLATEPLUGIN_PUBLISHER_H
#define TEMPLATEPLUGIN_POINT_CLOUD_TRANSPORT_TEMPLATEPLUGIN_PUBLISHER_H


#include "point_cloud_transport/simple_publisher_plugin.h"
#include <sensor_msgs/PointCloud2.h>
#include <dynamic_reconfigure/server.h>

#include <templateplugin_point_cloud_transport/TemplatepluginPublisherConfig.h>
#include "templateplugin_point_cloud_transport/CustomMessage.h"

namespace templateplugin_point_cloud_transport {

class TemplatepluginPublisher : public point_cloud_transport::SimplePublisherPlugin<templateplugin_point_cloud_transport::CustomMessage>
{
public:

  virtual ~TemplatepluginPublisher() {}

  virtual std::string getTransportName() const
  {
    return "templateplugin";
  }

protected:
  // Overridden to set up reconfigure server
  virtual void advertiseImpl(ros::NodeHandle &nh, const std::string &base_topic, uint32_t queue_size,
                             const point_cloud_transport::SubscriberStatusCallback  &user_connect_cb,
                             const point_cloud_transport::SubscriberStatusCallback  &user_disconnect_cb,
                             const ros::VoidPtr &tracked_object, bool latch);
  
  virtual void publish(const sensor_msgs::PointCloud2& message,
                       const PublishFn& publish_fn) const;

  typedef templateplugin_point_cloud_transport::TemplatepluginPublisherConfig Config;

  typedef dynamic_reconfigure::Server<Config> ReconfigureServer;

  boost::shared_ptr<ReconfigureServer> reconfigure_server_;

  Config config_;

  void configCb(Config& config, uint32_t level);
};

} //namespace templateplugin_point_cloud_transport

#endif // TEMPLATEPLUGIN_POINT_CLOUD_TRANSPORT_TEMPLATEPLUGIN_PUBLISHER_H