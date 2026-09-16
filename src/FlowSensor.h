#ifndef FLOW_SENSOR_H
#define FLOW_SENSOR_H

#include <Arduino.h>

class FlowSensor {
public:
  // pulsesPerLpm: sensor calibration (pulses/sec per L/min). Common: 7.5, 4.5, 5.5...
  FlowSensor(uint8_t pin);

  // Attach the interrupt. Returns false if another instance already owns the ISR.
  bool begin();

  // Call frequently from loop(). Returns true when a new reading was produced.
  bool update();

  float flow() const {
    return _flow;
  }  // L/min (last window)
  float volume() const {
    return _volume;
  }  // L (accumulated)

  void resetVolume();
  void setWindow(uint32_t ms);
  void setCalibration(float k);

private:
  uint8_t _pin;
  float _cal;
  uint32_t _windowMs;
  uint32_t _windowStart;
  volatile uint32_t _pulseCount;
  float _flow;
  float _volume;

  static FlowSensor* _active;  // single-instance registry

  static void _isr();
  uint32_t _readAndReset();
};

#endif