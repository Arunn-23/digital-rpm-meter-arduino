# Digital-rpm-meter-arduino
A real-time Digital RPM Meter using Arduino Nano, IR sensor, and 16×2 I2C LCD for non-contact rotational speed measurement.
# ⚙️ Digital RPM Meter Using Arduino Nano

> A compact, low-cost and real-time rotational speed measurement system using Arduino Nano, IR sensor and 16×2 I2C LCD.

## 📌 Overview

The **Digital RPM Meter** is an embedded electronics project designed to measure the rotational speed of a motor or rotating object in **Revolutions Per Minute (RPM)**.

The system uses an **IR sensor** to detect each rotation of a rotating object. The sensor generates digital pulses, which are processed by an **Arduino Nano based on ATmega328P**.

The Arduino counts the pulses within a fixed time interval and calculates the RPM. The measured value is then displayed in real time on a **16×2 LCD through an I2C interface**.

An LED indicator is also used to provide visual feedback during pulse detection.

---

## 🎯 Objectives

- Measure rotational speed in RPM.
- Detect rotation using a non-contact IR sensor.
- Process sensor pulses using Arduino Nano.
- Display RPM in real time.
- Develop a compact and low-cost measurement system.
- Gain practical experience in embedded systems and sensor interfacing.

---

## ✨ Features

- ⚡ Real-time RPM measurement
- 🔍 Non-contact rotation detection
- 📟 16×2 LCD digital display
- 🔗 I2C communication
- 🧠 Arduino Nano based processing
- 💡 LED pulse indication
- 🔋 Low-power operation
- 💰 Cost-effective implementation
- 🛠️ Simple and compact hardware
- 📡 Fast sensor response

---

## 🧩 Components Used

| Component | Purpose |
|---|---|
| Arduino Nano | Main processing and control unit |
| IR Sensor Module | Detects rotational movement |
| 16×2 LCD | Displays RPM |
| I2C LCD Module | Simplifies LCD communication |
| DC Motor | Provides rotational motion |
| Fan Blade | Rotating object for measurement |
| LED | Pulse detection indication |
| Resistor | LED current limiting |
| Switch | Motor ON/OFF control |
| Battery / 5V Supply | Power source |
| Breadboard / PCB | Circuit assembly |
| Jumper Wires | Electrical connections |

The project report identifies Arduino Nano, IR sensor, LCD with I2C, DC motor, fan, LED, switch, battery and interconnecting hardware as the principal components. 

---

## 🔌 Circuit Connections

### IR Sensor → Arduino Nano

| IR Sensor | Arduino Nano |
|---|---|
| VCC | 5V |
| GND | GND |
| OUT | D9* |

### I2C LCD → Arduino Nano

| I2C LCD | Arduino Nano |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

### LED

| LED | Arduino Nano |
|---|---|
| Positive | D13 through resistor |
| Negative | GND |

> **Important:** The project report contains an inconsistency: some sections state that the IR sensor output is connected to **D2**, while the actual source code defines `IR_SENSOR` as **pin 9**. The code and component-connection section use D9. Verify the physical wiring before publishing the final repository.

---

## ⚙️ Working Principle

The system operates using **infrared pulse detection and pulse counting**.

### Working sequence

```text
        ROTATING MOTOR
              │
              ▼
        ┌─────────────┐
        │  IR SENSOR  │
        └──────┬──────┘
               │ Digital Pulses
               ▼
        ┌─────────────┐
        │   ARDUINO   │
        │    NANO     │
        └──────┬──────┘
               │
        RPM Calculation
               │
               ▼
        ┌─────────────┐
        │  I2C MODULE │
        └──────┬──────┘
               │
               ▼
        ┌─────────────┐
        │   16×2 LCD  │
        └─────────────┘
               │
               ▼
          RPM DISPLAY
