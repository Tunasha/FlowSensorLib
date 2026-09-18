/*
MIT License

Copyright (c) 2026 Babatunde Adg

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.


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

