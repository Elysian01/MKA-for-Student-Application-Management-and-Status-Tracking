# Microkernel-Architecture-for-Student-Application-Management-and-Status-Tracking

---
Project works only on Linux environment

## [Main Application](./microkernal-app)

### Plugin Discovery Mechanism and a Dynamic Registration Process.

### Key Concepts

#### **1. Plugin Metadata**
Each plugin should provide metadata that specifies its type (e.g., `"notification"`, `"statistics"`) and necessary functions for integration.

#### **2. Dynamic Discovery**
A central discovery service reads all plugins, queries their metadata, and registers them based on their type.

#### **3. Integration Logic**

- **Notification Plugins**: Add to the observer list for automatic triggering.
- **Statistics Plugins**: Add to the user-triggerable menu.

### Advantages of This System

- **Dynamic Integration**: New plugins can be added without changing core code.
- **Categorization**: Plugins are categorized by type, and each type is handled differently.
- **Extensibility**: Adding a new plugin type requires minimal changes (e.g., "logging" type).
- **User-Controlled & Automatic**: Combines user-triggered and automatic behavior based on the plugin type.

### Example Plugins

#### **Recommendation Plugin (Statistics)**
- **Type**: `"statistics"`
- **Task**: Recommend institutes based on user data.

#### **Email Notification Plugin (Notification)**
- **Type**: `"notification"`
- **Task**: Send email alerts for new notifications.

### **SMS Notification Plugin (Notification)**
- **Type**: `"notification"`
- **Task**: Send sms alerts for new notifications.

Achieve this by:

1. Using a plugins directory: All plugins are placed in a specified folder (e.g., ./plugins/).
2. Scanning the directory: At runtime, the core scans the directory for .so files.
3. Dynamic loading and registration: Each plugin implements a standard set of exported functions, such as initializePlugin and getNotificationHandler. These functions allow the core to dynamically load and attach plugins.


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