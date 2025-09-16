# Proton-Proton Collision Simulation with Pythia8

This project demonstrates how to use **Pythia8** to simulate proton-proton (pp) collisions.  
The generated events are written to a **CSV file** containing kinematic and particle-level information.  

---

## ⚙️ Simulation Setup

- **Beam particles**: proton (ID 2212)  
- **Energy**: 5 GeV each (fixed target frame)  
- **Processes**: `HardQCD:all = on` (hard-QCD subprocesses enabled)  
- **Events simulated**: 10,000  
- **Output**: `pp_collision.csv`  

---

## 📂 Files

- **`pp_collision.cc`** → Main simulation file using Pythia8.  
- **`pp_collision.csv`** → Event data written in CSV format (after execution).  

---

## 🛠 Requirements

- [Pythia8](http://home.thep.lu.se/Pythia/) (version ≥ 8.3 recommended)  
- C++17 or later  
- CMake (optional, if you prefer building with CMake)  

Install Pythia8 (Ubuntu example):

```bash
sudo apt-get install pythia8
