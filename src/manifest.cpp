#include <pluginlib/class_list_macros.h>

//
#include "templateplugin_point_cloud_transport/templateplugin_publisher.h"
//
#include "templateplugin_point_cloud_transport/templateplugin_subscriber.h"

PLUGINLIB_EXPORT_CLASS( templateplugin_point_cloud_transport::TemplatepluginPublisher, point_cloud_transport::PublisherPlugin)

PLUGINLIB_EXPORT_CLASS( templateplugin_point_cloud_transport::TemplatepluginSubscriber, point_cloud_transport::SubscriberPlugin)
