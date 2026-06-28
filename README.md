## ⚠️ IMPORTANT DISCLAIMER – NOT A REAL BOMB

**This project is a 100% fictional, harmless puzzle game and educational simulation.** 

- It does **NOT** contain, simulate, or interface with any real explosives, detonators, or hazardous materials.
- It is inspired **exclusively** by the virtual C4 bomb from the video game *Counter‑Strike: Global Offensive* (CS:GO).
- The "timer", "defuse", and "explosion" effects are **purely visual and audio feedback** (LCD messages, LED blinking, and buzzer beeps) designed for entertainment and learning purposes.
- The "code" (`7355608`) is the iconic, fictional keypad code from the video game, not a real-world security key.
- This project is intended for **hobbyist electronics education**, **Arduino programming practice**, and **Proteus simulation training**. 

**Do not use this project, its code, or its design for any illegal, malicious, or harmful purposes.** The creator assumes no liability for misuse. Always comply with your local laws and regulations regarding the simulation of security or tactical devices.






# 🧨 CS:GO C4 Bomb Defusal Puzzle

![Arduino](https://img.shields.io/badge/Arduino-Uno%20%7C%20Nano-blue)
![Proteus](https://img.shields.io/badge/Proteus-8%20Simulation-green)
![License](https://img.shields.io/badge/License-MIT-yellow)

A fully functional **bomb defusal puzzle** inspired by the iconic *Counter‑Strike: Global Offensive* C4 bomb. Built with an Arduino (Uno/Nano), a 16×2 LCD, a 4×3 matrix keypad, an LED, and a piezo buzzer.  
The code runs both on real hardware and in **Proteus 8** simulation.

---

## 🎯 Features

- **Realistic interaction** – Enter the access code to arm the bomb, then re‑enter it to defuse.
- **Iconic CS:GO code** – Default code is **`7355608`** (the famous bomb code).
- **Defuse mode** – Press `#` to enter defuse mode, then type the code and press `#` again.
- **Countdown timer** – 60‑second countdown with a bouncing star animation and a fading trail.
- **Wrong code penalty** – Adds 5 seconds for each incorrect attempt.
- **Multi‑state machine** – BOOT → IDLE → ARMING → ARMED → DEFUSED / EXPLODED.
- **Sound effects** – Beeps for keypress, arming, defusing, and explosion.
- **Visual feedback** – LCD messages, LED blinking (fast during arming, solid on explosion).
- **Proteus 8 ready** – Simulate the entire circuit without hardware.

---

## 🖥️ Demo

| State | LCD Display | LED | Buzzer |
|-------|-------------|-----|--------|
| Boot | `Puzzle System` / `Initializing` | Off | Boot beep |
| Idle | `Enter Code:` + input | Off | Key beep |
| Armed (timer running) | Bouncing star with fading trail | Fast blink | Plant sound |
| Defused | `DEFUSED!` / `ACCESS GRANTED` | Off | Success sound |
| Exploded | `EXPLODED!` | On (solid) | Explosion sound |

---

## 🔧 Hardware Requirements

| Component | Quantity | Notes |
|-----------|----------|-------|
| Arduino Uno / Nano | 1 | Any ATmega328P board |
| 16×2 LCD (LM016L) | 1 | With or without backlight |
| 4×3 Matrix Keypad | 1 | 7‑pin membrane or tactile |
| LED (any colour) | 1 | With 220Ω resistor |
| Piezo Buzzer (passive) | 1 | For sound output |
| 10k Potentiometer | 1 | For LCD contrast adjustment |
| Breadboard & Jumper wires | as needed | |

---

## 📐 Wiring Diagram

### LCD → Arduino

| LCD Pin | Label | Arduino Pin |
|---------|-------|-------------|
| 1 | VSS | GND |
| 2 | VDD | 5V |
| 3 | V0 (contrast) | Wiper of 10k pot (outer to 5V & GND) |
| 4 | RS | D12 |
| 5 | RW | GND |
| 6 | EN | D11 |
| 11 | D4 | D5 |
| 12 | D5 | D4 |
| 13 | D6 | D3 |
| 14 | D7 | D2 |

> **Note**: For 14‑pin LCDs, pins 15 & 16 (backlight) are absent – ignore them.

### Keypad → Arduino

| Keypad Pin | Function | Arduino Pin |
|------------|----------|-------------|
| 1 | Row 1 | D6 |
| 2 | Row 2 | D7 |
| 3 | Row 3 | D8 |
| 4 | Row 4 | D9 |
| 5 | Column 1 | A0 |
| 6 | Column 2 | A1 |
| 7 | Column 3 | A2 |

### Other Components

| Component | Pin | Arduino Pin |
|-----------|-----|-------------|
| LED | Anode (via 220Ω) | D10 |
| LED | Cathode | GND |
| Buzzer | Positive | D13 |
| Buzzer | Negative | GND |

---

## 📦 Software & Libraries

- **Arduino IDE** (or PlatformIO)
- **LiquidCrystal** library (built-in)
- No other external libraries required.

---

## 🚀 Getting Started

### 1. Clone or download the repository
```bash
git clone https://github.com/yourusername/csgo-c4-bomb-defusal.git
