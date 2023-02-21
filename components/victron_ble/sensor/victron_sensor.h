#pragma once

#include "esphome/components/sensor/sensor.h"
#include "esphome/components/victron_ble/victron_ble.h"

namespace esphome {
namespace victron_ble {

enum class VICTRON_SENSOR_TYPE {
  BATTERY_MONITOR_TIME_TO_GO,
  BATTERY_MONITOR_BATTERY_VOLTAGE,
  BATTERY_MONITOR_ALARM_REASON,
  BATTERY_MONITOR_AUX_VOLTAGE,
  BATTERY_MONITOR_MID_VOLTAGE,
  BATTERY_MONITOR_TEMPERATURE,
  BATTERY_MONITOR_BATTERY_CURRENT,
  BATTERY_MONITOR_CONSUMED_AH,
  BATTERY_MONITOR_STATE_OF_CHARGE,

  SOLAR_CHARGER_DEVICE_STATE,
  SOLAR_CHARGER_CHARGER_ERROR,
  SOLAR_CHARGER_BATTERY_VOLTAGE,
  SOLAR_CHARGER_BATTERY_CURRENT,
  SOLAR_CHARGER_YIELD_TODAY,
  SOLAR_CHARGER_PV_POWER,
  SOLAR_CHARGER_LOAD_CURRENT,
};

class VictronSensor : public Component, public sensor::Sensor, public Parented<VictronBle> {
 public:
  void dump_config() override;
  void setup() override;

  void set_type(VICTRON_SENSOR_TYPE val) { this->type_ = val; }

 protected:
  VICTRON_SENSOR_TYPE type_;
};
}  // namespace victron_ble
}  // namespace esphome