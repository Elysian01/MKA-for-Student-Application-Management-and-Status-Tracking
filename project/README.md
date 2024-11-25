# Dynamic Plugin System

This project demonstrates a dynamic plugin loading system using C++ and shared libraries.

## Directory Structure
```
project/
│
├── core/
│   ├── core.cpp
│   ├── Makefile
│
├── plugins/
│   ├── notification_manager.cpp
│   ├── priority_application_plugin.cpp
│   └── Makefile
```

## Build Instructions

### Step 1: Build the Core
Navigate to the `core/` directory and run:
```bash
cd core
make
```

### Step 2: Build the Plugins
Navigate to the `plugins/` directory and run:
```bash
cd plugins
make
```

### Step 3: Run the Core
Return to the project root and execute the core:
```bash
./core/core
```

### Step 4: Select a Plugin
When prompted, select the plugin you wish to load. For example:
```
Core system started.
Available Plugins:
1. ./plugins/notification_manager.so
2. ./plugins/priority_application_plugin.so
Enter the number of the plugin to load (or 0 to exit): 1
Loading plugin: ./plugins/notification_manager.so
Notification Manager Plugin initialized!
```

## Cleaning Up
Run `make clean` in both `core/` and `plugins/` directories to clean up the generated files.
