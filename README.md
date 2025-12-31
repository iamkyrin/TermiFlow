![MIT License](https://img.shields.io/github/license/tecnolgd/Termiflow?style=flat)
![Static Badge](https://img.shields.io/badge/tools-Open_Source-lightblue)
![Static Badge](https://img.shields.io/badge/interface-CLI-white)
![Static Badge](https://img.shields.io/badge/build-C++-teal)
![Static Badge](https://img.shields.io/badge/release-v.0.1.0-beta)
![GitHub Discussions](https://img.shields.io/github/discussions/tecnolgd/Termiflow)

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
termiflow    # for Linux
#or
termiflow.exe

./termiflow.exe   # for Windows
```

## Usage & Mini-Guide

### Starting TermiFlow
Once launched, TermiFlow operates in a command-driven terminal mode where you can:

### Available Commands (for command - handler mode)

#### Application Launcher
Launch system applications directly from the terminal:
```bash
launch chrome          # Opens Chrome browser
launch code            # Opens VS Code editor
launch [application]   # Launch any registered application
```

#### Custom Shortcuts
Define and use custom shortcuts for frequently used commands:
```bash
shortcut add chrome c          # Add shortcut 'c' for chrome
shortcut list                  # View all shortcuts
shortcut remove c                            # Remove the shortcut 'c' for chrome.
```

#### Command History
View previously executed commands:
```bash
history list                        # Display command history
history clear                       # Clear command history
history goto <index>                # Go to a particular command using the index assigned to it.
```

#### Theme Management
Switch between light and dark themes:
```bash
theme dark                     # Switch to dark theme
theme light                    # Switch to light theme
```

#### System Stats
View system information:
```bash
stats                          # Display CPU (N/A), Memory, Uptime (Windows-focused)
``` 


## Features Overview

| Feature | Description | Status |
|---------|-------------|--------|
| **Command Handler** | Central command parser and dispatcher | ✅ Implemented |
| **Application Launcher** | Launch system applications directly | ✅ Implemented |
| **Custom Shortcuts** | Define your own command shortcuts | ✅ Implemented |
| **Theme Manager** | Light/Dark terminal themes | ✅ Implemented |
| **Command History** | Display previous commands | ✅ Implemented |
| **System Stats** | Display CPU, Memory, Uptime info | ✅ Implemented (Windows only) |

## Troubleshooting

**Application won't start:**
- Ensure all dependencies (g++ compiler) are installed.
- Check file permissions: `chmod +x ./build/main`.
- Verify the build was successful.

**Shortcuts not working:**
- Verify shortcuts were saved correctly with `shortcuts list`.
- Re-add shortcuts if needed: `shortcuts add [app] [shortcut]`.

**System stats display:**
- Currently optimized for Windows systems.
- Cross-platform support coming soon.

## Sample GIF
![Termiflow GIF](assets/termiflow.GIF)

## Documentation

For more details, refer to:
- **Code comments** in source files for implementation details
- **Header files** in `include/` directory for API documentation
- [**Sample GIF**](assets/termiflow.GIF)

*Detailed documentation site coming in future versions*

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

## Roadmap & Future Upgrades

- ✅ **Current:** 
  - C++ core with modular architecture    
  - Currently Windows-optimized. Linux/macOS support coming soon."
- 🔄 **In Progress:** Cross-platform support (Linux, macOS)
- 📋 **Planned:**
  - Plugin system for third-party modules
  - Implemetation of new functionalities
  - Enhanced system stats (CPU, network, etc.)
  - Scripting and automation features
  - Additional themes and customization options
  - Detailed documentation website
  - Performance optimizations
  - cmake for efficient tool build and run

## Author & Version

- **Author:** tecnolgd  
- **Version:** v0.1.0-beta  
- **License:** [MIT License](LICENSE.md)