#include <limits>
#include <vector>

//
#include "templateplugin_point_cloud_transport/templateplugin_subscriber.h"
//
#include "templateplugin_point_cloud_transport/templateplugin_common.h"

namespace templateplugin_point_cloud_transport
{

void TemplatepluginSubscriber::subscribeImpl(ros::NodeHandle& nh, const std::string& base_topic, uint32_t queue_size,
                             const Callback& callback, const ros::VoidPtr& tracked_object,
                             const point_cloud_transport::TransportHints& transport_hints)
{
    typedef point_cloud_transport::SimpleSubscriberPlugin<templateplugin_point_cloud_transport::CustomMessage> Base;
    Base::subscribeImpl(nh, base_topic, queue_size, callback, tracked_object, transport_hints);

    // Set up reconfigure server for this topic
    reconfigure_server_ = boost::make_shared<ReconfigureServer>(this->nh());
    ReconfigureServer::CallbackType f = boost::bind(&TemplatepluginSubscriber::configCb, this, _1, _2);
    reconfigure_server_->setCallback(f);
}

void TemplatepluginSubscriber::configCb(Config& config, uint32_t level)
{
    config_ = config;
}

void TemplatepluginSubscriber::shutdown()
{
  reconfigure_server_.reset();
    point_cloud_transport::SimpleSubscriberPlugin<templateplugin_point_cloud_transport::CustomMessage>::shutdown();
}

void TemplatepluginSubscriber::internalCallback(const templateplugin_point_cloud_transport::CustomMessageConstPtr& message,
                                            const Callback& user_cb)

{
    sensor_msgs::PointCloud2Ptr ptr_PC2(new sensor_msgs::PointCloud2);

    // ... Process the CustomMessage into PointCloud2 ... IMPLEMENT YOURSELF


    // Publish message to user callback
    user_cb(ptr_PC2);
}

} //namespace templateplugin_point_cloud_transport
