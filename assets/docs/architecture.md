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

**Limitations:**
- No validation of config values
- No error handling for missing files
- No type system (all values are strings)


#### B. **Theme Manager** (theme_manager.hpp/cpp)

**Purpose:** Manage terminal color themes

**Key Functions:**
- `changeTheme(std::string theme)` - Apply named theme
- `changeTheme()` - Interactive theme selection
- `saveThemeToConfig()` - Persist theme preference to config file

**Supported Themes:** Light, Dark (platform-dependent ANSI codes)

**Implementation:** Uses ANSI escape sequences or platform-specific system calls

**Limitations:**
- Limited theme selection
- No custom theme support
- Theme changes are terminal-session only (not persistent across new terminals)


#### C. **Command Handler** (command_handler.hpp/cpp)

**Purpose:** Parse and execute custom commands

**Key Functions:**
- `cmdHandler()` - Interactive command input and execution

**Scope:** Development-phase module (specific use case not finalized)

**Limitations:**
- Basic implementation
- Limited command set


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

**Limitations:**
- Application list is hardcoded or application discovery is basic
- No error handling for missing applications
- No process tracking
- Blocking calls (application takeover)


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

**Limitations:**
- Windows-only (shortcuts for Windows apps, mentioned in README)
- No conflict detection
- Single thread, blocking I/O
- Unknown file format makes recovery difficult
- No undo functionality


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

**Limitations:**
- No timestamp tracking
- No categorization (all commands mixed)
- No search/filter functionality
- Unbounded growth (no cleanup policy)
- No command execution from history


#### D. **Session Manager** (session_manager.hpp/cpp)

**Purpose:** Manage sessions and running tasks

**Status:** Not fully implemented (marked N/A in main.cpp)

**Limitations:**
- Current state is placeholder
- No process tracking
- No session persistence


#### E. **System Stats** (system_stats.hpp/cpp)

**Purpose:** Display system information

**Key Functions:**
- `statsInteractive()` - Display system statistics

**Status:** Partially implemented (marked "Partially N/A" in README)

**Limitations:**
- Limited metrics available
- No real-time monitoring
- Basic implementation


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

## Current Limitations & Architectural Issues

### **Critical Limitations**

#### 1. **No Dependency Injection or Configuration**
- Configuration is global and hardcoded file paths
- No way to change data directories
- Testing is difficult due to tight coupling

#### 2. **File-Based Storage Without Proper Format**
- Shortcuts and history use unknown file formats
- No schema versioning
- No migration path for future format changes
- Data corruption risk without validation

#### 3. **Single-Threaded, Blocking Architecture**
- Menu loop blocks on user input
- Application launches block entire program
- History/shortcuts I/O is synchronous
- No concurrent task execution

#### 4. **No Error Handling**
- Missing try-catch blocks
- File I/O errors are silently ignored or cause crashes
- Invalid user input not fully validated
- No error recovery mechanisms

#### 5. **Platform-Specific Code Not Well Abstracted**
- Windows-specific paths and APIs mixed with Linux
- No abstraction layer for platform differences
- Difficult to maintain cross-platform compatibility
- Windows app shortcuts hardcoded in features

#### 6. **Limited Scalability**
- All shortcuts and history loaded into memory
- No pagination or lazy loading
- Linear search through data structures
- Performance degrades with large datasets

### **Architectural Limitations**

#### 7. **Tight Coupling Between Components**
- Menu dispatcher directly calls feature handlers
- No event system or plugin architecture
- Features have direct dependencies on config
- Difficult to add new features without modifying main.cpp

#### 8. **No Logging or Debugging Infrastructure**
- No centralized logging system
- No debug mode
- No execution tracing
- Difficult to diagnose production issues

#### 9. **Incomplete Features**
- Session Manager: Not implemented (N/A)
- Task Manager: Not implemented (N/A)
- Config Loader editing: Commented out (N/A)
- System Stats: Partially implemented

#### 10. **No Separation of Concerns**
- File I/O mixed with business logic
- Menu UI logic in main.cpp dispatcher
- No clear data layer or model layer
- Interactive mode functions duplicate logic

### **Code Quality Limitations**

#### 11. **Header Guard Inconsistencies**
- Some use pragma once, some use ifndef
- No standard naming convention
- Missing include guards in some files

#### 12. **Memory Management Concerns**
- No use of smart pointers
- Potential memory leaks in class destructors
- No RAII patterns
- Manual resource management prone to errors

#### 13. **No Unit Testing Infrastructure**
- No test framework integration
- No test directory structure
- No mocking capabilities
- Very difficult to unit test components

#### 14. **Build System Limitations**
- Makefile is basic (no dependency tracking)
- Hard-coded source file lists
- No incremental build support
- Recompiles all files even for single changes



## Conclusion

TermiFlow is a **modular, feature-rich terminal launcher** with a solid foundation for basic use cases. The architecture is straightforward and easy to understand, making it accessible for contributors. However, the project would benefit significantly from improved error handling, proper separation of concerns, automated testing, and a clearer abstraction layer for platform differences.

The current implementation prioritizes functionality and simplicity over robustness and extensibility, which is appropriate for a beta-stage project (v0.1.1).