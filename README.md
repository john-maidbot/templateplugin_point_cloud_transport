This repository serves as a tutorial on how to create a custom plugin for [<point_cloud_transport>](https://github.com/paplhjak/point_cloud_transport). It assumes that you have already gone through point_cloud_transport [installation](https://github.com/paplhjak/point_cloud_transport#installation).

## 1) Choosing a name
The first step in the process of implementing our new plugin is choosing its name. The name shouldn't be too long and should describe the plugin.

For example: draco_point_cloud_transport is a plugin which uses Google [Draco](https://github.com/google/draco) compression, therefore the name **draco**.

For demonstrative purposes, the plugin which we will be implementing in this tutorial will be called **goblin**.

## 2) Cloning the Template Repository

Over the course of this tutorial, we will modify a **templateplugin** plugin. To download the template to your local machine, enter the following commands in terminal:

~~~~~ bash
$ cd point_cloud_transport_ws/src
$ git clone https://github.com/paplhjak/templateplugin_point_cloud_transport.git
~~~~~

## 3) Replacing Template-Name

This template uses the plugin name **templateplugin**, which is refered to multiple times in the source files. The files and classes implemented within the plugin follow a strict naming convention, inheriting from the name of the plugin. To follow the convention, we will replace each instance of **templateplugin** with the name of our new plugin **goblin**. This can be done quickly using a case-sensitive find and replace tool. Most editors can invoke this tool by pressing CTRL+R. Once you make sure that the find is case-sensitive, go through *all* files in the project, and make the following replacements:

```
1. TEMPLATEPLUGIN -> GOBLIN
2. Templateplugin -> Goblin
3. templateplugin -> goblin
```

![CTRLR](https://github.com/paplhjak/templateplugin_point_cloud_transport/blob/master/tutorial_images/ctrlr1.png)

At the end of the tutorial, we will also rename files within the project to follow the convention.

## 4) Custom Message

Our new plugin will most likely use a custom message format to communicate. We will implement the message in *msg/CustomMessage.msg* file and change name of the file to suit our project. For example to **GobMessage**. Then we go through the following files:

1. *templateplugin_publisher.h*
2. *templateplugin_subscriber.h*
3. *CMakeLists.txt*

and use the find and replace tool to replace the original name of **CustomMessage** with **GobMessage**.
```
CustomMessage -> GobMessage
```

![Renamemessage](https://github.com/paplhjak/templateplugin_point_cloud_transport/blob/master/tutorial_images/messagerename.png)

![CTRLR2](https://github.com/paplhjak/templateplugin_point_cloud_transport/blob/master/tutorial_images/ctrlr2.png)

## 5) Dynamic Reconfiguration

Our plugin's publisher and subscriber can also make use of dynamic reconfiguration. If they do, we edit the ParameterGenerator in the following files:

1. *cfg/Templateplugin_publisher.cfg*
2. *cfg/Templateplugin_subscriber.cfg*

Tutorial on how to use dynamic reconfiguration can be found at the official ROS [wiki](http://wiki.ros.org/dynamic_reconfigure/Tutorials/HowToWriteYourFirstCfgFile).

## 6) Implement Publisher Functionality

Implementation of your publisher should be in *src/templateplugin_publisher.cpp* within function *publish*.
The publish function should take a sensor_msgs::PointCloud2 message, compress it into you custom message format (**GobMessage**), and pass the custom message as an argument to *publish_fn()*.

## 7) Implement Subscriber Functionality

Implementation of your subscriber should be in *src/templateplugin_subscriber.cpp* within function *internalCallback*.
The *internalCallback* function should receive your custom message (**GobMessage**), decompress it into sensor_msgs::PointCloud2 and pass a shared pointer to the point cloud as an argument to *user_cb()*.

## 8) Description of Plugin

template_plugins.xml add description of publisher and subscriber
package.xml add description, author, url, email, etc.

## 9) Update Name of Files

Change names of files:
1) Templateplugin -> Goblin
2) templateplugin -> goblin

