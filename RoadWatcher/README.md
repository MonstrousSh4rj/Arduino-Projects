# 🚗 RoadWatcher

> Built for a Digital Logic Design lab project — a real working speed trap using an Arduino Uno, two IR sensors, and a buzzer. Catches overspeeding, logs every car to Excel, and fires a fine notice to your email automatically.

---

## 📸 How It Works
[IR S1]——20cm——[IR S2]
|               |
└───Arduino Uno─┘
|
USB
|
┌──────────────┐
│  🖥️ Laptop   │
│  Dashboard   │
│  Excel Log   │
│  Email Fine  │
└──────────────┘
---

## 🛠️ What You Need

| Component | Details |
|---|---|
| Arduino Uno | Main controller |
| IR Sensor x2 | Speed detection, placed 20cm apart |
| Buzzer | TMB12A05 active buzzer, Pin 11 |
| Breadboard + Wires | For connections |
| USB Cable | Arduino to laptop |

---

## 🔌 Wiring

| Component | Arduino Pin |
|---|---|
| IR Sensor 1 OUT | Digital Pin 2 |
| IR Sensor 2 OUT | Digital Pin 3 |
| Buzzer + leg | Digital Pin 11 |
| All VCC | 5V |
| All GND | GND |

> ⚠️ Sensors must be exactly **20 cm apart**, both facing the same direction.

---

## ✨ Features

- 🖥️ Live speed on laptop dashboard in real time
- 🔔 Buzzer fires instantly when speed exceeds 50 km/h
- 📊 Every car logged to Excel with date, time, speed, status
- 📧 Fine email sent automatically — Rs. 5000 per violation
- 🔴 Overspeed rows highlighted red in Excel
- 📈 Dashboard tracks total cars, fines issued, max speed recorded

---

## 🧠 How Speed Is Calculated
Time  = | timer1 - timer2 | ÷ 1000   → seconds
Speed = (0.2 ÷ Time) × (5.0 ÷ 0.2) × 3.6  → km/h
---

## 📂 Project Structure
RoadWatcher/
├── arduino/
│   └── roadwatcher.ino        ← Upload this to Arduino
├── python/
│   └── speed_monitor.py       ← Run this on laptop
├── docs/
│   └── wiring.md              ← Wiring reference
└── README.md
---

## 🚀 Setup

```bash
pip install pyserial openpyxl
python python/speed_monitor.py
```

> For email: myaccount.google.com → Security → App Passwords → Generate → paste in SENDER_PASSWORD

---

## 📊 Excel Output

| # | Date | Time | Speed (km/h) | Status | Fine (Rs.) | Email Sent |
|---|---|---|---|---|---|---|
| 1 | 2026-05-10 | 14:32:01 | 38.4 | Normal | 0 | — |
| 2 | 2026-05-10 | 14:35:22 | 67.2 | OverSpeed | 5000 | Yes |

---

## 📧 Fine Email
Subject: Traffic Fine Notice — Overspeeding Rs.5000
Dear Car Owner,
Your vehicle has been detected OVERSPEEDING.
━━━━━━━━━━━━━━━━━━━━━━━━━
FINE NOTICE
━━━━━━━━━━━━━━━━━━━━━━━━━
Date        : 2026-05-10
Time        : 14:35:22
Speed       : 67.2 km/h
Speed Limit : 50 km/h
Fine Amount : Rs. 5000
━━━━━━━━━━━━━━━━━━━━━━━━━
Please pay within 7 days.
Regards,
Speed Monitoring System
---

## 📜 License

MIT — use it, break it, improve it.

---

*Built with ❤️ using Arduino Uno, Python, and a buzzer that means business.*
