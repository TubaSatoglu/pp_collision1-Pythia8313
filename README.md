# Proton-Proton Collision Simulation with Pythia8.313

This project demonstrates how to use **Pythia8.313** to simulate proton-proton (pp) collisions.  
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

- **`pp_collision.cc`** → Main simulation file using Pythia8.313.  
- **`pp_collision.csv`** → Event data written in CSV format (after execution).  

---

## 🛠 Requirements

- [Pythia8.313](http://home.thep.lu.se/Pythia/) (or later)  
- C++17 or later  
- CMake (optional, if you prefer building with CMake)  

### Install Pythia8.313 (Ubuntu example):

```bash
wget http://home.thep.lu.se/download/pythia8/pythia8313.tgz
tar -xvzf pythia8313.tgz
cd pythia8313
./configure --enable-shared
make -j4
sudo make install
