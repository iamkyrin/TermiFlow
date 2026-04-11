# TermiFlow Architecture Documentation

## Project Overview

>- TermiFlow is a **command-driven terminal application** written in C++ that provides a centralized hub for launching applications, managing shortcuts, tracking command history, and viewing system information.      
>-  It operates as a menu-driven CLI tool with modular component architecture.

**Technology Stack:**

- **Language:** C++ (C++11 and later)
- **Compiler:** g++ or MinGW (for Windows)
- **Platform:** Linux/Windows (cross-platform via conditional compilation)
- **Configuration:** Plain text config file (INI-like format)
- **Data Storage:** File-based (shortcuts, history, config)


## Core Design Philosophy

- **Modular architecture** – each feature lives in its own module  
- **C++ first** – performance, control, and systems-level understanding  
- **Extensible by design** – new commands can be added without rewriting core logic  
- **Terminal-native** – works where developers already live


## Component Architecture

### 1. **Entry Point: main.cpp**

**Responsibility:** Application control flow, menu dispatch, user interaction loop

**Key Functions:**
- `showMenu()` - Display main menu options
- `main()` - Infinite loop that:
  - Shows menu to user
  - Validates numeric input
  - Dispatches to appropriate feature handler via switch statement
  - Handles configuration loading and auto-apply theme

**Current Flow:**
```
Application Start
    ↓
Load Config (termiflow.conf)
    ↓
Apply Auto Theme (if enabled)
    ↓
Display Menu Loop (0-9 options)
    ↓
Validate Input
    ↓
Dispatch to Feature Handler
    ↓
Return to Menu
```

### 2. **Core Modules**

#### A. **Config Loader** (config_loader.hpp/cpp)

**Purpose:** Load and parse configuration file

**Key Features:**
- Reads `config/termiflow.conf` file
- Returns `Config` struct containing key-value pairs
- Used for theme settings and behavior configuration

**Data Structure:**
```cpp
struct Config {
    std::unordered_map<std::string, std::string> values;
};
```

**Config Keys:**
- `user_interface.theme` - Current theme (light/dark)
- `behavior.auto_apply_theme` - Auto-apply theme on startup

#### B. **Theme Manager** (theme_manager.hpp/cpp)

**Purpose:** Manage terminal color themes

**Key Functions:**
- `changeTheme(std::string theme)` - Apply named theme
- `changeTheme()` - Interactive theme selection
- `saveThemeToConfig()` - Persist theme preference to config file

**Supported Themes:** Light, Dark (platform-dependent ANSI codes)

**Implementation:** Uses ANSI escape sequences or platform-specific system calls

#### C. **Command Handler** (command_handler.hpp/cpp)

**Purpose:** Parse and execute custom commands

**Key Functions:**
- `cmdHandler()` - Interactive command input and execution

**Scope:** Development-phase module (specific use case not finalized)


### 3. **Feature Modules**

#### A. **Launcher** (launch.hpp/cpp)

**Purpose:** Execute/launch system applications

**Key Functions:**
- `launchApp()` - Interactive app selection and launching
- `launchApp(std::string appName)` - Direct app launch

**Functionality:**
- Presents list of available applications
- User selects application to launch
- Executes application via system/platform-specific calls

**Platform Support:**
- Linux: Uses `execvp()` or similar
- Windows: Uses `CreateProcess()` or `system()` call

#### B. **Shortcuts** (shortcuts.hpp/cpp)

**Purpose:** Define and manage custom command shortcuts

**Architecture:** Class-based with state management

```cpp
class shortcuts {
    // Storage
    std::unordered_map<std::string, std::string> shortMap;
    std::string filepath;
    
    // Methods
    void add(const std::string& key, const std::string& value);
    void remove(const std::string& key);
    void save();
    void list();
    void load();
    bool exists(const std::string& value);
    std::string getValue(const std::string& key);
};
```

**Key Features:**
- In-memory HashMap for quick lookup
- File persistence (unknown format)
- Add/remove/list operations
- Interactive mode (`shortcutInteractive()`)

**Data Flow:**
```
shortcutInteractive()
    ↓
User Input (add/remove/list)
    ↓
shortcuts class instance
    ↓
load() from file
    ↓
Modify in-memory map
    ↓
save() to file
```

#### C. **History** (history.hpp/cpp)

**Purpose:** Track and display command history

**Architecture:** Class-based with vector storage

```cpp
class history {
    std::string filePath;
    std::vector<std::string> cmdEntries;
    
    void load();
    void save();
    void add(const std::string& cmd);
    void list();
    std::string get(int index);
    void historyClear();
};
```

**Key Features:**
- In-memory vector storage
- File persistence
- Add/list/clear operations
- Interactive mode (`historyInteractive()`)

#### D. **Session Manager** (session_manager.hpp/cpp)

**Purpose:** Manage sessions and running tasks

**Status:** Not fully implemented (marked N/A in main.cpp)

#### E. **System Stats** (system_stats.hpp/cpp)

**Purpose:** Display system information

**Key Functions:**
- `statsInteractive()` - Display system statistics

**Status:** Partially implemented (marked "Partially N/A" in README)


## Data Flow Diagrams

### Application Launch Flow
```
User selects "1. Launch an application"
    ↓
launchApp() called
    ↓
Display available apps list
    ↓
User selects application
    ↓
Execute via system/CreateProcess
    ↓
User returns to main menu
```

### Shortcuts Management Flow
```
User selects "2. Manage shortcuts"
    ↓
shortcutInteractive() called
    ↓
User chooses: add/remove/list
    ↓
If add/remove:
    ├─ Modify in-memory HashMap
    └─ save() to file
    ↓
If list:
    └─ Display all shortcuts from HashMap
    ↓
Return to main menu
```

### Theme Application Flow

```
Config loaded from termiflow.conf
    ↓
Check if auto_apply_theme == "true"
    ↓
If yes: Apply theme via ANSI codes or system calls
    ↓
User selects "4. Change theme"
    ↓
changeTheme() displays options
    ↓
Apply theme to current terminal
    ↓
saveThemeToConfig() persists preference
```

## Known Issues & Improvements

For a comprehensive list of known limitations, ongoing issues, and opportunities to contribute, please refer to the [GitHub Issues](https://github.com/tecnolgd/TermiFlow/issues) tab.    
Each issue is categorized and tracked for priority and difficulty level.

## Conclusion

TermiFlow is a **modular, feature-rich terminal launcher** with a solid foundation for basic use cases. The architecture is straightforward and easy to understand, making it accessible for contributors. However, the project would benefit significantly from improved error handling, proper separation of concerns, automated testing, and a clearer abstraction layer for platform differences.

The current implementation prioritizes functionality and simplicity over robustness and extensibility, which is appropriate for a beta-stage project (v0.1.1).