![MIT License](https://img.shields.io/github/license/tecnolgd/TermiFlow?style=flat)
![Static Badge](https://img.shields.io/badge/interface-CLI-white)
![Static Badge](https://img.shields.io/badge/made_with-C++-teal)
![Static Badge](https://img.shields.io/badge/release-v0.1.1-beta)

# TermiFlow
![TermiFlow logo](assets/termiflow_logo.png)

> **A modular, extensible terminal productivity tool written in C++**  
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
- Neatly handles unknown commands

### Application Launcher
- Launches system applications **directly** from the terminal
- **Platform-aware** execution logic (Windows/Linux)

### Custom Shortcuts
- Users can define their **own** shortcuts  
  Example:
  ```bash
  shortcuts add  chrome c
  ```

### Terminal theme management
- Provides *light* and *dark* theme for terminals
- Switch themes with a single command

### Command history 
- Stores every command typed in command-line mode.
- Displays commands up to the most recent command.

### System stats view
- Displays system stats like **CPU usage(N/A)**, **Memory usage** and **Uptime**
- Currently works for windows systems.

## How it works?
- TermiFlow is built around a **modular C++** core.    
- Each feature (launching, shortcuts, history, etc.) is implemented as a separate module, making it easy to extend and maintain.    
- The command handler parses user input and dispatches it to the appropriate module. Command history and themes are managed via simple text files.

## Installation

### Prerequisites
- Linux/Windows OS with g++ compiler
- Basic terminal/command-line knowledge

### Build Instructions

```bash
git clone https://github.com/tecnolgd/termiflow.git
cd termiflow
```

**On Linux:**
```bash
g++ src/main.cpp src/core/*.cpp src/features/*.cpp -o termiflow -I./include
```

**On Windows (MinGW):**
```bash
x86_64-w64-mingw32-g++ src/main.cpp src/core/*.cpp src/features/*.cpp -o termiflow.exe -I./include -static -static-libgcc -static-libstdc++
```

## How to Run
After building, run the application:

```bash
./termiflow    # for Linux

./termiflow.exe   # for Windows
```
## Features Overview

| Feature | Description | Status |
|---------|-------------|--------|
| **Command Handler** | Central command parser and dispatcher | ✅ Implemented |
| **Application Launcher** | Launch system applications directly | ✅ Implemented |
| **Custom Shortcuts** | Define your own command shortcuts | ✅ Implemented |
| **Theme Manager** | Light/Dark terminal themes | ✅ Implemented |
| **Command History** | Display previous commands | ✅ Implemented |
| **System Stats** | Display CPU, Memory, Uptime info | ✅ Implemented (Windows & linux) |
| **Configuration** | Auto-launch previously used theme as default theme | ✅ Implemented |

## Troubleshooting

**Application won't start:**
- Ensure all dependencies (g++ compiler) are installed.
- Check file permissions: `chmod +x ./build/main`.
- Verify the build was successful.

**Shortcuts not working:**
- Verify shortcuts were saved correctly with `shortcuts list`.
- Re-add shortcuts if needed: `shortcuts add [app] [shortcut]`.

**System stats display:**
- Currently optimized for Windows systems with slight linux support.
- Cross-platform support coming soon.

## Sample GIF
![Termiflow GIF](assets/termiflow.GIF)

## Documentation

- [**Commands Reference**](assets/docs/command_reference.md)
- [**Roadmap**](assets/docs/roadmap.md)

For more details, refer to:
- **Code comments** in source files for implementation details
- **Header files** in `include/` directory for function details


## License
[MIT License](LICENSE.md)

## Future Upgrades
- **Cross-platform** support (Linux, macOS)
- Plugin system for third-party modules
- Enhanced system stats (CPU, network, etc.)    
- **Scripting** and **automation** features 
- **Config Management** for tool customisation   
- **More** themes and customization options

## Project Structure

```txt
termiFlow/
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
│   ├── docs/
│   │   ├── architecture.md
│   │   ├── command_reference.md
│   │   ├── roadmap.md
│   ├── banner.txt 
│   |── termiflow.GIF
│── config/
│   ├── termiflow.conf       
├── README.md
├── .gitignore
└── build/
```

## Contributing

Contributions are welcome! Help make TermiFlow better by:
- Reporting bugs
- Suggesting features
- Submitting pull requests
- Improving documentation

## Support This Project

If TermiFlow has positively impacted your workflow, consider:
- ⭐ Starring this repository
- 🍴 Forking the project
- 💬 Sharing feedback and suggestions
- 🤝 Contributing code or documentation


## Author & Version

- **Author:** tecnolgd  
- **Version:** v0.1.1-beta  
- **License:** [MIT License](LICENSE.md)



