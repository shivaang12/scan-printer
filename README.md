# scan-printer
A simple ros2 package which subscribes scan topic and publishes.

## Build and Running instructions
```
$ cd ~/<$your_ws>/src/
$ git clone https://github.com/shivaang12/scan-printer.git
$ cd ~/<$your_ws>/
$ colcon build
$ source install/setup.bash
$ ros2 run scan_printer scan_printer
```

NOTE: Make sure you start gazebo with turtlebot3 before running this node.
