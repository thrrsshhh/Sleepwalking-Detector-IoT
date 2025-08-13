# Sleepwalking-Detector-IoT
# 🌙 Sleepwalking Detector & Preventor

> *Because even dreamers need a safe path…*

An **IoT-based wearable device** that detects and prevents sleepwalking by tracking movement patterns, gently waking the sleeper, and alerting a guardian.  
This is **not just a project**, it's a step towards safer nights. 🛌✨

---

## 📖 Overview
Sleepwalking can be risky — from bumping into furniture to wandering outdoors.  
Our solution: a **wearable ESP32-based gadget** shaped like a wristwatch that detects unusual nighttime movement and responds in two ways:
1. **Wakes the user** with a mild electric stimulus  
2. **Alerts the guardian** via Bluetooth buzzer notification

💡 *Think of it as a smart nightwatchman who never sleeps.*

---

## ✨ Features
- 📡 **Real-time step monitoring** using the **BMA456** pedometer sensor  
- ⚡ **Mild shock module** to gently wake the sleeper  
- 🖲️ **Push button** to pause or reset alerts  
- 🔊 **Guardian buzzer alert** via **ESP-NOW** wireless protocol  
- 🔋 Battery-powered & wearable-friendly  
- 🌐 Potential for **mobile app integration**  

---

## 🛠️ Hardware Components
| Component | Quantity | Purpose |
|-----------|----------|---------|
| ESP32 Microcontroller | 2 | One for walker, one for guardian |
| BMA456 Step Counter | 1 | Detects motion |
| Shock Module | 1 | Wakes the sleeper |
| Push Button | 1 | Manual override |
| Wired Buzzer | 1 | Alerts the guardian |
| Rechargeable Battery | 1 | Portable power |
| Jumper Wires | — | Connections |

---

## 💻 Software Requirements
- Arduino IDE  
- ESP32 Board Package  
- BMA456 Sensor Library  
- ESP-NOW Communication Library  

---

## 🏗️ System Architecture
**Walker Module**  
- Tracks steps → triggers LED/shock if threshold is crossed  
- Sends alert to guardian

**Guardian Module**  
- Receives alert via ESP-NOW  
- Activates buzzer to wake guardian

---

## 🔌 Circuit Overview
- **Walker**: ESP32 + BMA456 + LED + Shock Module + Push Button  
- **Guardian**: ESP32 + Buzzer  

---

## 📜 How It Works
1. Wearer puts on the device before sleep  
2. ESP32 + BMA456 monitor step count  
3. If count exceeds **threshold** → LED + shock activate  
4. ESP-NOW sends alert to guardian ESP32  
5. Guardian buzzer sounds  
6. Pressing button resets both devices

---

## 📸 Results
- ✅ Accurate detection of step count thresholds  
- ✅ Guardian alerted instantly via buzzer  
- ✅ Manual override works reliably  

---

## 🚀 Future Enhancements
- 📱 Mobile app for live monitoring  
- 📡 BLE/LoRa for long-range communication  
- 📊 Sleep pattern data logging  
- 🤖 Machine learning prediction of episodes  
- 🔋 Smarter battery management  

---

## 👩‍💻 Contributors
- **Dhanya T Kunder** (NNM22CC015)  
- **K.P Bhoomika Rai** (NNM22CC026)  
- **Thrisha J Shetty** (NNM22CC064)  

Guided by:  
**Mr. Krishna Prasad D S** — Assistant Professor, Department of Computer and Communication Engineering  

---

## 📄 License
This project is licensed under the [MIT License](LICENSE).

---

> *"Night is a time of dreams. Let's make sure they're safe ones."* 🌌

