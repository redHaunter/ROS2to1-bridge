# ROS2to1-bridge
ROS1_bridge packages and the required subscriber and publisher nodes are provided for using the SVO_pro code on Deepracer
## bridge_ws

This packages has multiple launch file and nodes to bridge standard and customized topics between ROS distribuitions from ROS2 to ROS1 and vice-versa.

Here we only use the dynamic_bridge node to publish our ROS2 foxy topics in ROS1 noetic. For this matter, you have install both distributions in your ROS-machine whether directly or on a docker image (see similar instructions to install ROS distributions in [Deepracer docs](https://github.com/redHaunter/aws-deepracer/tree/main/docs)).

## dynamic_bridge
First, build the package in using instructions from the pacakge's [github repository](https://github.com/ros2/ros1_bridge).

### ros2_msgs_ws

Here we have provided the required node and configuration for ROS2 foxy to publish our desired topics, in this case cameras data and IMU, properly so we can have access to them in ROS1.

> You have to build the package using colcon build.

### ros1_msgs_ws

In this package, we wrote a node to access our required nodes in ROS1 noetic.

> You have to build the package using catkin build.


## How to use

After building the ros2_msgs_ws and ros1_msgs_ws with colcon and catkin respectfully, you have to use three terminals to bridge you messages from ROS2 foxy to ROS1 noetic.

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