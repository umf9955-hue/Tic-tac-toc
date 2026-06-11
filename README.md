# Tic-tac-toc
A simple two-player Tic Tac Toe game built with C++ and Raylib. Click to place your mark, first to get three in a row wins. Press R to restart!
# Tic Tac Toe — Raylib (C++)

A simple two-player Tic Tac Toe game built with C++ and [Raylib](https://www.raylib.com/).

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Library](https://img.shields.io/badge/Library-Raylib-orange)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20macOS%20%7C%20Linux-lightgrey)

---

## Screenshot

<img width="592" height="620" alt="Screenshot 2026-06-12 003711" src="https://github.com/user-attachments/assets/31fee078-8139-46e7-9b3d-899c8a579fb6" />


---

## Features

- Classic 3×3 Tic Tac Toe gameplay
- Two-player local mode (Player X vs Player O)
- Win detection for rows, columns, and diagonals
- Draw detection
- Press **R** to restart after a game ends
- Runs at a smooth 60 FPS

---

## Requirements

- [Raylib](https://www.raylib.com/) (v4.x or later recommended)
- A C++ compiler (g++, clang++, or MSVC)
- CMake *(optional, for build system)*

---

## Getting Started

### 1. Clone the repository

```bash
git clone https://github.com/your-username/tic-tac-toe-raylib.git
cd tic-tac-toe-raylib
```

### 2. Install Raylib

Follow the official guide for your platform:  
👉 https://github.com/raysan5/raylib#build-and-installation

### 3. Compile and Run

**Linux / macOS:**
```bash
g++ main.cpp -o tictactoe -lraylib -lm -lpthread -ldl
./tictactoe
```

**Windows (MinGW):**
```bash
g++ main.cpp -o tictactoe.exe -lraylib -lopengl32 -lgdi32 -lwinmm
tictactoe.exe
```

---

## How to Play

| Action | Input |
|---|---|
| Place mark | Left Mouse Click on a cell |
| Restart game | Press **R** (after game ends) |
| Quit | Close the window |

- **Player X** plays first (drawn in Red)
- **Player O** plays second (drawn in Blue)
- The game announces the winner or a draw at the end

---

## Project Structure

```
tic-tac-toe-raylib/
│
├── main.cpp        # All game logic and rendering
└── README.md       # This file
```

---

## License

This project is open source and available under the [MIT License](LICENSE).
