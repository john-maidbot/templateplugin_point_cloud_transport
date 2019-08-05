# Custom point_cloud_transport Plugins tutorial

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

![CTRLR](https://github.com/paplhjak/templateplugin_point_cloud_transport/blob/master/tutorial_images/goblin.png)

At the end of the tutorial, we will also rename files within the project to follow the convention.

## 4) Custom Message

Our new plugin will most likely use a custom message format to communicate. We will implement the message in *msg/CustomMessage.msg* file and change name of the file to suit our project. For example to **GobMessage**. Then we go through the following files:

1. *templateplugin_publisher.h*
2. *templateplugin_subscriber.h*
3. *CMakeLists.txt*
4. *templateplugin_publisher.cpp*
5. *templateplugin_subscriber.cpp*

and use the find and replace tool to replace the original name of **CustomMessage** with **GobMessage**.

```
CustomMessage -> GobMessage
```

![Renamemessage](https://github.com/paplhjak/templateplugin_point_cloud_transport/blob/master/tutorial_images/messagerename.png)

![CTRLR2](https://github.com/paplhjak/templateplugin_point_cloud_transport/blob/master/tutorial_images/gobmessage.png)

## 5) Dynamic Reconfiguration

Our plugin's publisher and subscriber can also make use of dynamic reconfiguration. If they do, we edit the ParameterGenerator appropriatelly in the following files:

1. *cfg/Templateplugin_publisher.cfg*
2. *cfg/Templateplugin_subscriber.cfg*

We can make use of the dynamic reconfiguration [tutorial](http://wiki.ros.org/dynamic_reconfigure/Tutorials/HowToWriteYourFirstCfgFile) if necessary.

## 6) Implementing Publisher Functionality

Implementation of the publisher can be located in *src/templateplugin_publisher.cpp* within function *publish*.

The publish function takes in a sensor_msgs::PointCloud2 message, which should be compressed and converted into our custom message format **GobMessage**. Once the message is ready, we pass it as an argument to *publish_fn*.

![publish](https://github.com/paplhjak/templateplugin_point_cloud_transport/blob/master/tutorial_images/publish.png)

## 7) Implementing Subscriber Functionality

Implementation of the subscriber can be located in *src/templateplugin_subscriber.cpp* within function *internalCallback*.

The *internalCallback* function takes in our custom message format **GobMessage**, which should be decompressed and converted into sensor_msgs::PointCloud2. Once the point cloud message is ready, we pass a shared pointer to it as an argument to *user_cb*.

![internalcallback](https://github.com/paplhjak/templateplugin_point_cloud_transport/blob/master/tutorial_images/internalcallback.png)

## 8) Description of Plugin

Before we distribute our plugin, it is important that we fill in all the necessary information about it. 

In template_plugins.xml, make sure to provide brief description of both the publisher and subscriber our plugin uses.

In package.xml, first change the description tag and maintainer tags. These are required and important tags because they let others know who to contact about the package. 

At least one maintainer is required, but you can have many if you like. The name of the maintainer goes into the body of the tag, but there is also an email attribute that should be filled out.

Next fill in the license tag, which is also required. Finally fill in the dependencies tags.

## 9) Update Names of Files

The last required step is to rename files in the project. For this, replace any instances of **Templateplugin** with **Goblin** etc.

For example templateplugin_subscriber.cpp should be renamed to goblin_subscriber.cpp amd TemplatepluginPublisher.cfg should be renamed to Goblin.cfg .

At this point your plugin should be able to succesfully compile, build and be recognized by point_cloud_transport.

To see all plugins currently available at your system, enter command:

~~~~~ bash
rosrun point_cloud_transport list_transports
~~~~~



