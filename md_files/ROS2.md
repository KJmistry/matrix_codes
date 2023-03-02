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
    // build install log src (3 new folders added !)

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

inside my_robot_controller will find: __my_robot_controller__ __resource__ __test__ 