
# TermiFlow

> **A modular, extensible terminal productivity launcher written in C++**  
> Built to reduce friction between intent and execution.

---

## What is TermiFlow?

**TermiFlow** is a command-driven terminal tool that lets users **launch applications, execute shortcuts, and track command history** — all from a single, fast, keyboard-centric interface.

Think of it as:
- a ***minimal launcher***
- a ***command hub***
- a ***foundation for terminal automation***

No GUI. No fluff. Just flow.

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
- Launches system applications directly from the terminal
- Platform-aware execution logic (Windows-focused for now)

### Custom Shortcuts
- Users can define their own shortcuts  
  Example:
  ```bash
  shortcuts add  chrome c
  ```


