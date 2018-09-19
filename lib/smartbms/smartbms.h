#pragma once

#include <comm.h>
#include <ros.h>
#include <sensor_msgs/BatteryState.h>
#include <status_led.h>
#include <tli4970.h>

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

  // IO objects
  SPI spi_;

  // Hardware objects
  StatusLED status_led_;
  TLI4970 tli_;

  // ROS
  ros::NodeHandle_<BMSHardware> nh_;
  sensor_msgs::BatteryState battery_msg_;
  ros::Publisher battery_pub_;
};
