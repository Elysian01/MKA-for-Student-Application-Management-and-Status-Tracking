#include <iostream>
#include <string>
#include <vector>
#include <dlfcn.h>    // For dynamic library loading
#include <filesystem> // For reading directory contents
#include "../headers/Microkernel.h"
#include "../headers/NotificationPluginLoader.h"
#include "../headers/StatisticsPluginLoader.h"
#include "../headers/DocumentVerification.h"

namespace fs = std::filesystem;
using namespace std;

// Load and register a plugin using the appropriate loader
void loadPlugin(const string &pluginPath) {
    // Open the plugin using dlopen
    void *pluginHandle = dlopen(pluginPath.c_str(), RTLD_LAZY);
    if (!pluginHandle) {
        cerr << "Failed to load plugin: " << dlerror() << "\n";
        return;
    }

    // Get the plugin type using a common function from the plugin
    const char* (*getPluginType)() = (const char* (*)())dlsym(pluginHandle, "getPluginType");
    if (!getPluginType) {
        cerr << "Failed to find getPluginType: " << dlerror() << "\n";
        dlclose(pluginHandle);
        return;
    }

    string pluginType = getPluginType();
    dlclose(pluginHandle); // Close the handle after determining the type

    // Use the appropriate loader based on the plugin type
    if (pluginType == "notification") {
        NotificationPluginLoader loader;
        loader.load(pluginPath);
    } else if (pluginType == "statistics") {
        StatisticsPluginLoader loader;
        loader.load(pluginPath);
    } else {
        cerr << "Unknown plugin type: " << pluginType << "\n";
    }
}


// Function to configure and load plugins
void configurePlugins() {
    string pluginDir = "../plugins/so";

    // Validate the plugin directory
    if (!fs::exists(pluginDir) || !fs::is_directory(pluginDir)) {
        cerr << "Plugin directory not found: " << pluginDir << "\n";
        return;
    }

    // Gather available plugins
    vector<string> plugins;
    for (const auto &entry : fs::directory_iterator(pluginDir)) {
        if (entry.path().extension() == ".so") {
            plugins.push_back(entry.path().string());
        }
    }

    // Check if plugins are available
    if (plugins.empty()) {
        cout << "No plugins found in directory: " << pluginDir << endl;
        return;
    }

    // Display available plugins
    cout << "Available Plugins:\n";
    for (size_t i = 0; i < plugins.size(); ++i) {
        cout << i + 1 << ". " << plugins[i] << "\n";
    }

    // User options
    int choice;
    cout << "\nOptions:\n";
    cout << "1. Load a single plugin\n";
    cout << "2. Load all plugins\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        // User selects a single plugin
        int pluginChoice;
        cout << "Enter the plugin number to load: ";
        cin >> pluginChoice;

        if (pluginChoice > 0 && pluginChoice <= (int)plugins.size()) {
            loadPlugin(plugins[pluginChoice - 1]);
        } else {
            cout << "Invalid plugin number.\n";
        }
    } else if (choice == 2) {
        // Load all plugins
        for (const auto &plugin : plugins) {
            loadPlugin(plugin);
        }
    } else {
        cout << "Invalid option. No plugins loaded.\n";
    }
}

// Function to display the main menu
void displayMenu() {
    int choice;
    while (true) {
        cout << "\nMain Menu:\n";
        cout << "1. Application Tracking\n";
        cout << "2. Apply for Institute\n";

        // Add statistics plugin tasks dynamically
        // We got statisticsTasks from the StatisticsPluginLoader.cpp file
        for (size_t i = 0; i < statisticsTasks.size(); ++i) {
            cout << i + 3 << ". " << statisticsTasks[i].taskName << "\n";
        }

        cout << statisticsTasks.size() + 3 << ". Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            Microkernel::trackApplicationStatus();
        } else if (choice == 2) {
            Microkernel::applyForInstitute();
        } else if (choice > 2 && choice <= (int)(statisticsTasks.size() + 2)) {
            // Execute the selected plugin task
            statisticsTasks[choice - 3].executeTask();
        } else if (choice == (int)(statisticsTasks.size() + 3)) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid option. Try again.\n";
        }
    }
}

// Main function
int main() {
    string studentName, rollNumber;

    // Configure and load plugins
    configurePlugins();

    // Main flow
    cout << "\n\nEnter Student Name: ";
    cin.ignore();              // Clear leftover newline character from the input buffer
    getline(cin, studentName); // Use getline for studentName to handle spaces
    cout << "Enter Roll Number: ";
    cin >> rollNumber;
    Microkernel::registerStudent(studentName, rollNumber);
    DocumentVerification::verifyDocuments();

    displayMenu();

    return 0;
}
