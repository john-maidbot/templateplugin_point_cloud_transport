#include <boost/make_shared.hpp>
#include <vector>

//
#include "templateplugin_point_cloud_transport/templateplugin_common.h"
//
#include "templateplugin_point_cloud_transport/templateplugin_publisher.h"



namespace templateplugin_point_cloud_transport
{

void TemplatepluginPublisher::advertiseImpl(ros::NodeHandle &nh, const std::string &base_topic, uint32_t queue_size,
                                        const point_cloud_transport::SubscriberStatusCallback &user_connect_cb,
                                        const point_cloud_transport::SubscriberStatusCallback &user_disconnect_cb,
                                        const ros::VoidPtr &tracked_object, bool latch)
{
  typedef point_cloud_transport::SimplePublisherPlugin<templateplugin_point_cloud_transport::CustomMessage> Base;
  Base::advertiseImpl(nh, base_topic, queue_size, user_connect_cb, user_disconnect_cb, tracked_object, latch);

  // Set up reconfigure server for this topic
  reconfigure_server_ = boost::make_shared<ReconfigureServer>(this->nh());
  ReconfigureServer::CallbackType f = boost::bind(&TemplatepluginPublisher::configCb, this, _1, _2);
  reconfigure_server_->setCallback(f);
}

void TemplatepluginPublisher::configCb(Config& config, uint32_t level)
{
  config_ = config;
}

void TemplatepluginPublisher::publish(const sensor_msgs::PointCloud2& message, const PublishFn& publish_fn) const
{
    templateplugin_point_cloud_transport::CustomMessage new_message;

    // ... Process the message into new_message ... IMPLEMENT YOURSELF

    publish_fn(new_message);
}

} //namespace templateplugin_point_cloud_transport
