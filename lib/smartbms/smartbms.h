#pragma once

#include <comm.h>
#include <ros.h>
#include <status_led.h>
#include <std_msgs/Int32.h>

class BMSHardware : public MbedHardware {
public:
  BMSHardware() : MbedHardware(PA_2, PA_3){};
};

class SmartBMS {
public:
  SmartBMS();
  void run();

private:
  bool ok_;
  StatusLED status_led_;

  // ROS things
  ros::NodeHandle_<BMSHardware> nh_;
  std_msgs::Int32 int_;
  ros::Publisher pub_int_;
};
