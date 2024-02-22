# ROS2to1-bridge
ROS1_bridge packages and the required subscriber and publisher nodes are provided for using the SVO_pro code on Deepracer
## bridge_ws

The package has multiple launch files and nodes to bridge standard and customized messages between ROS distributions from ROS2 to ROS1 and vice-versa.

To publish our ROS2 foxy topics in ROS1 noetic, we use only the dynamic_bridge node. To accomplish this, you need to have both distributions installed on your ROS machine, either directly or on a Docker image. You can refer to the installation instructions for ROS distributions in [Deepracer docs](https://github.com/redHaunter/aws-deepracer/tree/main/docs) for similar guidance.

## dynamic_bridge
To begin, follow the instructions provided on the [Github repository](https://github.com/ros2/ros1_bridge) of the package in order to build it.

### ros2_msgs_ws

Here, we have provided the necessary node and configuration for ROS2 foxy to correctly publish camera data and IMU topics so that we can access them in ROS1.

> You have to build the package using colcon build.

### ros1_msgs_ws

In this package, we wrote a node to access our required nodes in ROS1 noetic.

> You have to build the package using catkin build.


## How to use

After building the ros2_msgs_ws and ros1_msgs_ws with Colcon and Catkin, respectively, you have to use three terminals to bridge your messages from ROS2 Foxy to ROS1 Noetic.

> note that you need a roscore for running ROS1 noetic nodes.

### First Terminal

```
source /opt/ros/noetic/setup.bash
cd path_to_repo/ros1_msgs_ws
source devel/setup.bash
rosrun noetic_subscriber subscriber_node
```

### Second Terminal

```
source /opt/ros/foxy/setup.bash
cd path_to_repo/ros2_msgs_ws
source install/setup.bash
ros2 run foxy_publisher publisher_node
```

### Third Terminal

```
source /opt/ros/noetic/setup.bash
source /opt/ros/foxy/setup.bash
cd path_to_repo/bridge_ws
source install/setup.bash
ros2 run ros1_bridge dynamic_bridge
```
