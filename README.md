Work in progress ...

## 1) Choosing a name
The first step in the process of implementing your own plugin is choosing its name. The name shouldn't be too long and should describe the plugin.

For example: draco_point_cloud_transport is a plugin which uses Google [Draco](https://github.com/google/draco) compression, therefore the name **draco**.

For demonstrative purposes of this tutorial, assume that the plugin which we are implementing is called **goblin**.

## 2) Cloning the Template Repository

~~~~~ bash
$ cd point_cloud_transport_ws/src
$ git clone https://github.com/paplhjak/templateplugin_point_cloud_transport.git
~~~~~

## 3) Replacing Template-Name

This template uses plugin name **teplateplugin**. To quickly replace it with the name of you own plugin (**goblin** in this tutorial), you can use a case-sensitive find and replace tool. Most editors can invoke this tool by pressing CTRL+R. Once you make sure that the find is case-sensitive, go through *all* files in the project, and make the following replacements:
```
1. TEMPLATEPLUGIN -> GOBLIN
2. Templateplugin -> Goblin
3. templateplugin -> goblin
```

## 4) Custom Message

Your plugin will most likely use a custom message format to communicate. Implement such format in the *msg/CustomMessage.msg* file. 
Change name of the file to suit your project, for example to **GobMessage**, go through the following files:

1. *templateplugin_publisher.h*
2. *templateplugin_subscriber.h*
3. *CMakeLists.txt*

and use the find and replace tool to replace **CustomMessage** with **GobMessage**.
```
CustomMessage -> GobMessage
```
## 5) Dynamic Reconfiguration

If your plugin's publisher and subscriber make use of dynamic reconfiguration, edit the following files accordingly:

1. *cfg/Templateplugin_publisher.cfg*
2. *cfg/Templateplugin_subscriber.cfg*

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

