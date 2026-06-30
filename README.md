# 🚀 Mini Shell (C) — By Shigosag

A modern, lightweight terminal shell built in C, designed as a portfolio-grade systems project demonstrating command parsing, history tracking, logging, and basic shell behavior.

![Mini Shell Build](Screenshots/shell.png)
![Mini Shell Terminal](Screenshots/shell2.png)

### 🎥 Mini Shell Demo & Walkthrough

<div align="center">
  <video src="https://github.com/user-attachments/assets/b12300ff-21ee-45ec-9bbf-2180957cbafb" width="100%" controls></video>
</div>

**Timestamps:**
- **0:00** - Shell build
- **0:10** - Shell launch & branding banner
- **0:25** - Command input interface
- **0:40** - GitHub Repository Overview

---

## ✨ Features

- 🖥️ Custom CLI shell interface
- 📜 Command history tracking
- 🧾 Logging system
- ⚙️ Built-in commands:
  - help
  - pwd
  - cd
  - history
  - clear
  - exit
- 🔍 External command execution (system() based)
- 🎨 Modern ASCII branding banner (animated style)
- 🌈 Colored terminal UI (Hot Pink, Pink, Cyan, etc.)
- 🧩 Modular C architecture (parser, executor, logger)

---

## 🗂️ Project Structure

```text
Mini-Shell/
│
├── include/
│   ├── shell.h
│   ├── command.h
│   ├── parser.h
│   ├── history.h
│   ├── logger.h
│   ├── colors.h
│
├── src/
│   ├── main.c
│   ├── shell.c
│   ├── command.c
│   ├── parser.c
│   ├── executor.c
│   ├── history.c
│   ├── logger.c
│
├── build/
├── CMakeLists.txt
└── README.md
```

---

## ⚙️ Prerequisites

- CMake: https://cmake.org/download/
- MSYS2: https://www.msys2.org/
- Windows / Linux / WSL

---

## 🛠️ Installation

### Install toolchain 
Open MSYS2 UCRT64 terminal:

```bash
pacman -Syu
pacman -S --needed mingw-w64-ucrt-x86_64-toolchain mingw-w64-ucrt-x86_64-make mingw-w64-ucrt-x86_64-cmake
```

### Clone Repository

```bash
git clone https://github.com/Shigosag/Mini-Shell.git

cd Mini-Shell
```

---

## 🔨 Build Instructions

```bash
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build .
```

## ▶️ Run

```bash
./minishell.exe
```

---

## 💡 Example Commands

```bash
help
pwd
cd ..
history
clear
exit
```

---

## 🧠 Architecture

```txt
Input → Parser → Executor → System Layer
          ↓
     History + Logger
```

---

## 🚀 Future Improvements

- Pipes (|) real implementation
- Redirection (> <)
- Tab autocomplete
- Arrow key navigation
- Cross-platform fork/exec engine
- Plugin system

---

## 👤 Author & Credits

- **Shigosag**
- Portions of code generated with AI support

Mini Shell — Systems Programming Portfolio Project

---

## 📄 License

MIT License (for educational and portfolio use)

© 2026 Shigosag

---
