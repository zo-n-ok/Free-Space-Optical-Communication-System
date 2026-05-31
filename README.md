# 📡 FiberLink

A simple optical fiber communication project that transmits text between two computers using a laser, plastic optical fiber, and Arduino.

Instead of traditional UART communication, this project uses Morse-code-based On-Off Keying (OOK) modulation because the LDR receiver is too slow for reliable high-speed serial communication.

---

## ✨ Features

* Text transmission through optical fiber
* Arduino-based transmitter and receiver
* Laser-to-fiber optical coupling
* Morse code encoding and decoding
* Real-time character display on serial monitor
* Low-cost components

---

## 🧰 Hardware

| Component                 | Quantity |
| ------------------------- | -------- |
| Arduino Uno               | 2        |
| 650nm Laser Module        | 1        |
| LDR Sensor Module (LM393) | 1        |
| Plastic Optical Fiber     | 1        |
| USB Cable                 | 2        |
| Jumper Wires              | Several  |

---

## 🔌 Wiring

### Transmitter

| Arduino Pin | Connection       |
| ----------- | ---------------- |
| D13         | Laser Signal Pin |
| 5V          | Laser VCC        |
| GND         | Laser GND        |

### Receiver

| Arduino Pin | Connection              |
| ----------- | ----------------------- |
| D2          | LDR Digital Output (DO) |
| 5V          | LDR VCC                 |
| GND         | LDR GND                 |

---

## 📐 Circuit Diagram

```text
TRANSMITTER

+------------------+
|    Arduino Uno   |
|                  |
| D13 --------> Laser Signal
| 5V  --------> Laser VCC
| GND --------> Laser GND
+------------------+

            ||
            || Plastic Optical Fiber
            \/

+------------------+
|    LDR Module    |
|                  |
| DO ----------> D2
| VCC ---------> 5V
| GND ---------> GND
+------------------+

       RECEIVER
       Arduino Uno
```

---

## 💻 Software

### Required Applications

* Arduino IDE
* Serial Monitor (Built into Arduino IDE)

### Required Libraries

No external libraries required.

Uses:

* Serial.h
* millis()
* digitalRead()
* digitalWrite()

---

## 🚀 How It Works

1. Type a character in the transmitter serial monitor.
2. Arduino converts it to Morse code.
3. Laser transmits the Morse sequence through the optical fiber.
4. LDR detects incoming light pulses.
5. Receiver decodes Morse code back into text.
6. Character appears on the receiver serial monitor.

---

---
> [!NOTE]
> 
> * Keep the laser aligned with the fiber.
> * Shield the receiver from ambient light.
> * Adjust the LM393 potentiometer before transmission.
> * Communication speed depends on Morse timing settings.

---

## 🔮 Future Upgrades

* Replace LDR with photodiode
* Support true UART communication
* Higher data rates
* Error detection
* Manchester encoding
* Multi-character buffering

---

## 📜 License

MIT License
