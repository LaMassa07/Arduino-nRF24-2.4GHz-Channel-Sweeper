# Arduino-nRF24-2.4GHz-Channel-Sweeper  <img src="https://img.shields.io/badge/ARDUINO-Nano-blue?logo=arduino&logoColor=white"/> <img src="https://img.shields.io/badge/status-completed-brightgreen?logo=checkmarx"/>
Arduino project using an nRF24L01 to generate a constant carrier and perform a 2.4 GHz channel sweep for RF testing and experimentation purposes.

<br>

## 📌 Features
- **Generate** a constant RF carrier using nRF24L01
- **Sweep** across 2.4 GHz channels
- **Target** BLE advertising and data channels
- **Button‑controlled** transmission with LED status indicator
- **Configurable** channel timing and power level

<br>

## ⚙️ Setup
- First, be sure to have the <a href="https://www.arduino.cc/en/software/">Arduino IDE</a> at the last version

### Libraries
Go to `Sketch` → `Include Library` → `Add .ZIP Library` and install:
- **RF24** by *TMRh20* from <a href="https://github.com/tmrh20/RF24">here</a>

<br>

## 🛠️ Installing the code
Open the *code.ino* file with the IDE.
Before uploading it, you can edit the button and led pins.


When you are ready, click **Upload**


<br>

## 🔌 Build the circuit
### Materials:
- ARDUINO board *(I used ARDUINO Nano, but you can choose your ARDUINO, but be sure to use the right SPI pins)*
- 1 x buttons
- 1 x 220Ω resistors
- 1 x led
- 1 x nRF24l01+PA+LNA rf module
- 1 x 47uF capacitor


### Schematic
<img width="1099" height="686" alt="image" src="https://github.com/user-attachments/assets/affb289a-d9b4-4b66-8edd-0574775c119a" />


<br>
<br>

## 🖥️ Use
> ⚠️ **USE THIS ONLY IN A CONTROLLED ENVIRONMENT.**  
> This project is intended purely for *RF experimentation, learning, and demonstration purposes*.  
> Do not use near critical devices, production Wi-Fi, or Bluetooth networks.

<br>
<br>
<br>

## 📄 License

This project is released under the **MIT License**.  
See [LICENSE](./LICENSE) for details.

<br>

## 🙌 Credits
Inspired by the work of <a href="https://github.com/SecureTechware">**@SecureTechware**</a>, so consider taking a look at his original project.
<br>
<br>

Find Me on:
[![Github](https://img.shields.io/badge/Github-LaMassa07-purple?style=for-the-badge&logo=github)](https://github.com/LaMassa07)




