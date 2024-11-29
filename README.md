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

### Template Design Pattern

The Template Design Pattern allows you to define the skeleton of an algorithm in a base class and let subclasses override specific steps without changing the overall structure. It is useful when you have a standard structure but want to allow extensibility for specific parts.

In the code you provided, you can apply the Template Design Pattern to refactor and optimize repeated functionality, such as:

Plugin Loading:
1. The plugin loading logic (e.g., for notification and statistics plugins) has similar steps: loading the library, fetching functions, and registering the plugin.
2. You can use a template method to define the common steps and let derived classes handle plugin-specific registration.

### Benefits of using Template Pattern

1. **Modular Code**: The logic for handling each type of plugin is encapsulated in its respective class.
2. **Extendability**: Adding new plugin types (e.g., logging, authentication) becomes easy—just create a new subclass of PluginLoader.
3. **Reusability**: The common logic for loading plugins is handled in the base class, reducing duplication.


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