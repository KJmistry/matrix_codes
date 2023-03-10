# ROS2

## installation

after installation, source setup script to every terminal before using ros2 (source /opt/ros/humble/__setup.bash__)

to avoid sourcing every time, source it to .bashrc file

## understanding node by directly starting example package

    ros2 run [Name of pkg] [Name of Node]

ros2 nodes are organised in packages. node is nothing but a program. (ex. pkg for camera driver,robot nevigation ...)

    ros2 run demo_nodes_cpp talker    

(Node/Program)talker starts running !! publisher

    ros2 run demo_nodes_cpp listener

(Node/Program)listener starts running !! subscriber

## rqt graph tool

The graphical representation of all the nodes running.

    rqt_graph 

refresh once window popup ! (the button at top left corner )

## Turtlesim package

package for experimenting robots in 2D for begineers !

__terminal 1__

    ros2 run turtlesim turtle_node

node for creating GUI of turtle

__terminal 2__ 

    ros2 run turtlesim turtle_teleop_key

node to listen keyboard key press !

__terminal 3__

    rqt_graph

graphical representation of all nodes !

## setuup for creating ros2 workspace

workspace is nothing morethan a folder !

installing build tool - for ros it is colcon

    sudo apt install python3-colcon-common-extensions

after installation source colcon-argcomplete.bash script to .bashrc file  (/usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash)

    //go to home
    mkdir ros2_ws
    
    cd ros2_ws
    mkdir src  
    // in src (source) will write ros2 nodes

    colcon build
    ls
    // will get output of ls command as following 
    // build install log src (3 new folders added along with src !)

build will fetch codes inside src filder that we have created already and build them and as a outcome will get three new folders. It will build first and install nodes inside install folder.

if we do ls inside install folder will find one setup.bash script. we need to source that to make our system use the nodes created. 

inside .bashrc file - ( source ~/ros2_ws/install/setup.bash )

__now using this ros2 work space we are ready to start creating ros2 application !__

## creating ros2 python package

first go to src directory of ros2_ws

    ros2 pkg create my_robot_controller --build-type ament_python --dependencies rclpy

- inside this package will be writing nodes to control the turtle ! (hence named robot controller package) package is one subpart of an application which may contain multiple nodes also package may have internal dependency on eachother.

- will also specify it as python package or c++ package using --build-type option, here in ament_python (which we have specified) ament is a build system (colcon is build tool which will use build system ament)

- will add dependencies (other packages and functionalities will be using in current package). here we have specified rclpy which is a python library for ros2.

after complition will use ls command inside src folder. will find one folder named my_robot_controller. hit code . and open src folder in VS code. 

inside my_robot_controller will find: __my_robot_controller__ , __resource__ , __test__ directories and __package.xml__ , __setup.cfg__ , __setup.py__

- package.xml : Info/Dependency/build_type etc.
- setup.cfg : path - install ros2 node (No need to change)
- steup.py : similar info like package.xml 

One Sub Directory will be having the same name as the package name (__my_robot_controller__ in our case), inside this folder will be creating our ros2 nodes.

go back to ros2_ws directory (current directory: ros2_ws/src/my_robot_controller ) and hit colcon build comand 

    cd ../.. 
    colcon build

if error occures change change setuptool version

every thing inside package is considered to be build after getting success message. Build will install every thing we want to install in our package inside install folder. from install folder we will be able to run our nodes.(ros2 run [node name])

## Writing the first Node (Hello world)

inside my_robot_controller (ros2_ws/src/my_robot_controller/my_robot_controller) initially will find __init__.py file. creat another python file (executable) for your node inside the same folder(my_first_node.py in our case).

python script for Node:

``` python
#! /usr/bin/env python3     
#interpreter line to tell interpreter to use python3 

import rclpy       # python lib for ros2

from rclpy.node import Node

class MyNode(Node):                                     # creating Node using OOP (defining class myNode inherit from Node(rclpy.node))

    def __init__(self):                                 # constructor (self will get functionality of Node class) 
        super().__init__("first_node")                  # calling constructor of upper class, providing Node name that will be using to run Node in the graph 
                                                        # first_node in current code

        self.get_logger().info("Hello from ROS2")       # print
 

def main(args = None):
    rclpy.init(args=args)                               # intit ros2 communications
    node = MyNode()                                     # Creating Node object inside main
    rclpy.spin(node)                                    # continuously running Node (kill using Ctrl+C)
    rclpy.shutdown()                                    # shutdown ros2 comm.  

if __name__ == '__main__':                              #useful when directly running file from terminal
    main()

```
after writing Node, from terminal execute ./file Name 

Now to run Node using ros2 run [Node Name]: goto setup inside my_robot_controller and add it to console scripts as shown below !

``` python
entry_points={
        'console_scripts': [
            "test_node = my_robot_controller.my_first_node:main "
```

save it and execute concon build command inside ros2_ws folder.
after successful build again source bashrc file to use new functionalities we have added.

finally execute ros2 run

    ros2 run my_robot_controller test_node 

[Be careful about three names related to nodes: python file name , node name , ros2 executable name ] // use a common name for future Nodes!

use symlink-install for executing modified Node without building it everytime after small changes in a program.

## Using ros2 timer and callbacks !

