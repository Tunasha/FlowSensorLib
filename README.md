
# FlowSensor

Arduino library for hall-effect / pulse-output liquid flow sensors.

## Features

- Non-blocking measurement (uses `millis()`, no `delay()`)
- Reports flow rate (L/min) and accumulated volume (L)
- Only masks the sensor pin's own external interrupt when reading the
  shared counter — `millis()`, Serial, ADC, etc. keep running
- Configurable calibration and measurement window at runtime

## Installation

Arduino IDE → **Sketch → Include Library → Manage Libraries…** →
search **FlowSensor** → Install.
Or download the repo and use **Sketch → Include Library → Add .ZIP Library…**

## Quick start

```cpp

\\\#include <FlowSensor.h>



FlowSensor flow(2, 7.5f);   // pin 2, 7.5 pulses/sec per L/min



void setup() { Serial.begin(9600); flow.begin(); }



void loop() {

 if (flow.update()) {

Serial.print(flow.flow(),   2); Serial.print(" L/min  ");

Serial.print(flow.volume(), 3); Serial.println(" L");

}

}

```

## API

| Method | Description |
|---|---|
| `FlowSensor(pin, pulsesPerLpm)` | Construct. `pulsesPerLpm` is your sensor's K-factor. |
| `bool begin()` | Attach the ISR. Returns `false` if another instance already owns it. |
| `bool update()` | Call in `loop()`. Returns `true` when a new reading is ready. |
| `float flow()` | Last measured flow, L/min. |
| `float volume()` | Accumulated volume, L. |
| `void resetVolume()` | Zero the volume accumulator. |
| `void setWindow(ms)` | Measurement window (default 1000 ms). Longer = smoother. |
| `void setCalibration(k)` | Change K-factor at runtime. |

## Calibration

Common K-factors (pulses per litre, at 1 L/min ≈ K/60 pulses/sec):

| Sensor | K (pulses/L) | `pulsesPerLpm` (= K/60) |
|---|---|---|
| YF-S201 | 450 | 7.5 |
| YF-S401 | 5880 | 98.0 |
| YF-B1   | 660 | 11.0 |
| FS400A  | 450 | 7.5 |

If your sensor datasheet gives **pulses per litre** (K), pass `K / 60.0f`.

## License

MIT — see `LICENSE`.
