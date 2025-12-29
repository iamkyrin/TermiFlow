![MIT License](https://img.shields.io/github/license/tecnolgd/termiflow?style=flat)
![Static Badge](https://img.shields.io/badge/tools-Open_Source-lightblue)
![Static Badge](https://img.shields.io/badge/interface-CLI-white)
![Static Badge](https://img.shields.io/badge/build-C++-teal)
![Static Badge](https://img.shields.io/badge/release-v.0.1.0-beta)
![GitHub Discussions](https://img.shields.io/github/discussions/tecnolgd/termiflow)

# TermiFlow

> **A modular, extensible terminal productivity launcher written in C++**  
> Built to reduce friction between intent and execution.

## What is TermiFlow?

**TermiFlow** is a command-driven terminal tool that lets users **launch applications, execute shortcuts, track command history**, and **much more** — all from a single, fast, keyboard-centric interface.

Think of it as:
- a ***minimal launcher***
- a ***command hub***
- a ***foundation for terminal automation***

*No GUI. No fluff. Just flow.*

## Why TermiFlow?

Modern systems are powerful but fragmented.  
TermiFlow exists to answer one question:

> *“Why should I leave the terminal to do simple things?”*

It’s designed for:
- developers
- power users
- anyone who prefers speed over clicks

## Core Design Philosophy

- **Modular architecture** – each feature lives in its own module  
- **C++ first** – performance, control, and systems-level understanding  
- **Extensible by design** – new commands can be added without rewriting core logic  
- **Terminal-native** – works where developers already live

## Features Implemented (Current)

### Command Handler
- Central command parser and dispatcher
- Routes user input to appropriate modules
- Gracefully handles unknown commands

### Application Launcher
- Launches system applications **directly** from the terminal
- **Platform-aware** execution logic (Windows-focused for now)

### Custom Shortcuts
- Users can define their **own** shortcuts  
  Example:
  ```bash
  shortcuts add  chrome c
  ```

### Terminal theme management
* Provides *light* and *dark* theme for terminals
* **One command** action

### Command history 
* Stores every command typed in command-line mode.
* Displays commands upto thr most recent command.

### System stats view
* Displays system stats like **CPU usage(N/A)**, **Memory usage** and **Uptime**
* Currently works for windows systems.

## How it works?
* TermiFlow is built around a **modular C++** core.    
* Each feature (launching, shortcuts, history, etc.) is implemented as a separate module, making it easy to extend and maintain.    
* The command handler parses user input and dispatches it to the appropriate module. Configuration and themes are managed via simple text files.

## How to run? 

## Sample Outputs
## Documentation

## Future Upgrades
**Cross-platform** support (Linux, macOS)
Plugin system for third-party modules
Enhanced system stats (CPU, network, etc.)    
**Scripting** and **automation** features    
**More** themes and customization options



## Project Structure

```txt
TermiFlow/
├── src/
│   ├── main.cpp
│   ├── core/
│   │    ├── command_handler.cpp
│   │    ├── theme_manager.cpp
│   │    ├── system_stats.cpp
│   │    ├── config_loader.cpp 
│   │    ├── task_manager.cpp
│   ├── features/
│        ├── launch.cpp
│        ├── shortcuts.cpp
│        ├── history.cpp
│        ├── session_manager.cpp
├── include/
│   ├── command_handler.hpp
│   ├── launch.hpp
│   ├── shortcuts.hpp
│   ├── history.hpp
│   ├── theme_manager.hpp
│   ├── system_stats.hpp
│   ├── session_manager.hpp
│   ├── config_loader.hpp
│   ├── task_manager.hpp
├── assets/
│   ├── banner.txt   
├── config/
│   ├── termi_flow.conf       
├── README.md
├── .gitignore
└── build/
```

## Manual command build
```cmd
x86_64-w64-mingw32-g++ src/main.cpp src/core/*.cpp src/features/*.cpp -o termiflow.exe -static -static-libgcc -static-libstdc++
```
### Value this repo ?
* If you feel this repository has impacted positively to your dev flow, consider dropping a star or hitting fork.
* Contributions are welcome to make this tool to the best of its abilities.

### Author
tecnolgd

### Version
v0.1.0-beta
