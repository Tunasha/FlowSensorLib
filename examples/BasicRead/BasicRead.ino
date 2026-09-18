/*
This example demostrates how to read data from the flow sensor like the flow rate in L/min and Flow Volume.
Author: Tunasha, Babatunde Adg
*/
#include "FlowSensorLib.h"

FlowSensor flow(2);  // pin 2

void setup() {
  Serial.begin(9600);
  flow.setCalibration(4.5);    // Calibration factor (K) of  4.5 pulses/sec per L/min for YF-S210 model,check your model for appropiate K
  if (!flow.begin()) {
    Serial.println("FlowSensor attach failed");
  }
}

void loop() {
  if (flow.update()) {
    Serial.print("flow=");
    Serial.print(flow.flow(), 2);
    Serial.print(" L/min  vol=");
    Serial.println(flow.volume(), 3);
    
  }
  // other non-blocking tasks here
}

