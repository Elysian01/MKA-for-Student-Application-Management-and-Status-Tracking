# Microkernel-Architecture-for-Student-Application-Management-and-Status-Tracking

---
Project works only on Linux environment

## [Main Application](./microkernal-app)

### Features Demonstrated

1. Dynamic Plugin Loading: Choose one or both plugins at runtime.
2. Core with Hooks: The core exposes an alert list (std::vector) for plugins to access and send notifications. Particularly it uses, Observer Design Pattern, to exposes particular information.

3. Plugin Notification System: Extensions utilize the core's hook to trigger notifications (SMS/Email).
4. Menu-Based Interaction: Includes student registration, document verification, application tracking, and dashboard. 

### Plugin Discovery Mechanism and a Dynamic Registration Process.

Achieve this by:

1. Using a plugins directory: All plugins are placed in a specified folder (e.g., ./plugins/).
2. Scanning the directory: At runtime, the core scans the directory for .so files.
3. Dynamic loading and registration: Each plugin implements a standard set of exported functions, such as initializePlugin and getNotificationHandler. These functions allow the core to dynamically load and attach plugins.

4. **Benefits of This Design**
    1. Dynamic Extensibility: New plugins can be added without modifying or recompiling the core. 
    2. Separation of Concerns: Core and plugins are completely decoupled. Plugins implement a well-defined interface.
    3. Flexibility: Plugins can implement custom logic for processing notifications.

### Build

To built and run this project, run the following command
```bash
chmod +x build_and_run_mka.sh
```
```bash
./build_and_run_mka.sh
```
## [Dynamic Loading of Library Example](./dynamic_loading_lib_example/)

Here, we demonstrate Dynamic loading of plugin were we can choose one or both plugins at runtime.

To built and run this project, run the following command
```bash
chmod +x build_and_run_dynamic_example.sh
```
```bash
./build_and_run_dynamic_example.sh
```