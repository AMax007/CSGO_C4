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
git clone https://github.com/AMax007/CSGO_C4.git
```
### 2. Open the project
- In Arduino IDE, open `CSGO_C4.ino`.
- Install the LiquidCrystal library if not already present (Sketch → Include Library → LiquidCrystal).

### 3. Compile and upload
- Select the correct board (Arduino Uno / Nano) and port.
- Click **Upload**.

### 4. Simulate in Proteus (optional)
- Open the provided `CSGO_C4.pdsprj` file (or build your own circuit).
- Load the compiled `.hex` file into the Arduino model.
- Set clock frequency to **16 MHz**.
- Run the simulation and interact with the virtual keypad.

---

## 🕹️ How to Play

1. **Boot** – LCD shows `Puzzle System` for 2 seconds, then enters IDLE mode.

2. **Arm the bomb**  
   - Enter the access code: **`7355608`** (the famous CS:GO code).  
   - Press **`#`** (hash) to confirm.  
   - The timer starts (60 seconds), LED blinks fast, LCD shows a bouncing star with a fading trail.

3. **Defuse the bomb** (before time runs out)  
   - While the timer is running, press **`#`** to enter **defuse mode**.  
   - LCD shows `Enter Defuse:`.  
   - Type the same code **`7355608`** and press **`#`** again.  
   - If correct, the bomb is defused – LED turns off, LCD shows `DEFUSED!`.  
   - If wrong, 5 seconds are added to the timer, and you can try again.

4. **Explosion**  
   - If the timer reaches zero, the bomb explodes – LED turns on solid, LCD shows `EXPLODED!` and an explosion sound plays.

---

## 🛠️ Code Structure

| File | Purpose |
|------|---------|
| `CSGO_C4.ino` | Main entry – `setup()` and `loop()` |
| `Config.h` | All constants (pins, timeouts, code, states) |
| `Controller.cpp/.h` | State machine logic |
| `Display.cpp/.h` | LCD control (messages, animations) |
| `KeypadInput.cpp/.h` | Matrix keypad scanning, debouncing, buffering |
| `Timer.cpp/.h` | Countdown timer with penalty |
| `LED.cpp/.h` | LED control (on/off/blink) |
| `Audio.cpp/.h` | Sound generation via `tone()` |
| `Pins.h` | Centralised pin definitions |
| `Sounds.h` | Sound ID definitions (for future MP3 module) |

---

## 🔧 Customisation

### Change the access code
Edit `ACCESS_CODE` in `Config.h`:
```cpp
constexpr char ACCESS_CODE[] = "7355608";  // your custom code
```
> Note: Max length is `MAX_CODE_LENGTH` (8 by default).

### Adjust the timer duration
```cpp
constexpr unsigned long BOMB_TIMER_DURATION = 60000;  // milliseconds
```

### Set wrong-code penalty
```cpp
constexpr unsigned long WRONG_CODE_PENALTY = 5000;    // milliseconds
```

### Modify the star animation speed
In `Display.cpp`, change the value inside `animateStars()`:
```cpp
if (millis() - previousStarTime < 150) return;  // 150ms per frame
```

---

## 🧪 Testing in Proteus

1. Create a new project in Proteus 8.
2. Place an Arduino (Uno/Nano), LM016L LCD, 4×3 keypad, LED with resistor, and buzzer.
3. Wire everything as per the table above.
4. Double‑click the Arduino, load the generated `.hex` file, set clock to 16 MHz.
5. Run the simulation and interact with the keypad (click buttons).

---

## ❓ Troubleshooting

| Problem | Solution |
|---------|----------|
| LCD shows nothing | Adjust the contrast potentiometer; ensure RW is tied to GND. |
| Keypad not responding | Verify row/column wiring matches `Pins.h`; check debounce time. |
| No sound in Proteus | Proteus audio is unreliable – use a virtual oscilloscope on D13 to verify waveform. |
| Code doesn’t compile | Make sure LiquidCrystal library is installed. |
| Blinking numbers on LCD | The code already implements caching to reduce flicker – if you see flicker, check your `showInput()` implementation. |

---

## 🤝 Contributing

Contributions are welcome!  
Feel free to open issues or submit pull requests for improvements, bug fixes, or new features (e.g., adding an MP3 module for real sound effects).

---

## 📄 License

This project is licensed under the **MIT License** – see the [LICENSE](LICENSE) file for details.

---

## 🎮 Credits

- Inspired by the C4 bomb from *Counter‑Strike: Global Offensive* (Valve Corporation).
- Built with ❤️ using Arduino and Proteus.

---

**Enjoy defusing!** 💣🔧  
*Remember: The code is `7355608`.*
```
