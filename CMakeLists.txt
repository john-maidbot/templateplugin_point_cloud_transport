cmake_minimum_required(VERSION 2.8.3)
project(templateplugin_point_cloud_transport)

find_package(catkin REQUIRED
        COMPONENTS
        dynamic_reconfigure
        message_generation
        point_cloud_transport
        sensor_msgs
        std_msgs)


add_message_files(
        FILES
        CustomMessage.msg
)

generate_dynamic_reconfigure_options(cfg/TemplatepluginPublisher.cfg cfg/TemplatepluginSubscriber.cfg)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS dynamic_reconfigure point_cloud_transport sensor_msgs std_msgs message_runtime
)

include_directories(include)

add_library(${PROJECT_NAME}
        src/templateplugin_publisher.cpp
        src/templateplugin_subscriber.cpp
        src/manifest.cpp)

add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}_gencfg templateplugin_point_cloud_transport_generate_messages_cpp)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})

class_loader_hide_library_symbols(${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)
install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
        FILES_MATCHING PATTERN "*.h"
)

# add xml file
install(FILES templateplugin_plugins.xml
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
