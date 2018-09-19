#pragma once

#include <comm.h>
#include <ros.h>
#include <sensor_msgs/BatteryState.h>
#include <status_led.h>

class BMSHardware : public MbedHardware {
public:
  BMSHardware() : MbedHardware(PA_2, PA_3){};
};

class SmartBMS {
public:
  SmartBMS();
  void run();

private:
  // Constants
  static constexpr const char *battery_topic_ = "battery/status";

  // Variables
  bool ok_ = true;
  StatusLED status_led_;

  // ROS
  ros::NodeHandle_<BMSHardware> nh_;
  sensor_msgs::BatteryState battery_msg_;
  ros::Publisher battery_pub_;
};
