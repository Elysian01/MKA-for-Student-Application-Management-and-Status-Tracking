#include <iostream>
#include <string>
#include <vector>
#include <dlfcn.h>    // For dynamic library loading
#include <filesystem> // For reading directory contents
#include "../headers/Microkernel.h"
#include "../headers/DocumentVerification.h"
#include "../headers/StudentApplicationSubmission.h"
#include "../headers/StudentDashboard.h"

namespace fs = std::filesystem;
using namespace std;

struct PluginTask {
    string taskName;
    void (*executeTask)();
};

vector<void (*)(const string&)> notificationHandlers;
vector<PluginTask> statisticsTasks;

// Load and register a plugin
void loadPlugin(const string& pluginPath) {

    void* pluginHandle = dlopen(pluginPath.c_str(), RTLD_LAZY);
    if (!pluginHandle) {
        cerr << "Failed to load plugin: " << dlerror() << "\n";
        return;
    }

    // Get plugin type
    const char* (*getPluginType)() = (const char* (*)())dlsym(pluginHandle, "getPluginType");
    if (!getPluginType) {
        cerr << "Failed to find getPluginType: " << dlerror() << "\n";
        dlclose(pluginHandle);
        return;
    }

    string pluginType = getPluginType();

    // Register notification plugins
    if (pluginType == "notification") {
        void (*onNotificationReceived)(const string&) = (void (*)(const string&))dlsym(pluginHandle, "onNotificationReceived");
        if (!onNotificationReceived) {
            cerr << "Failed to find onNotificationReceived: " << dlerror() << "\n";
            dlclose(pluginHandle);
            return;
        }
        notificationHandlers.push_back(onNotificationReceived);
        Microkernel::addObserver(onNotificationReceived);
        cout << "Notification Plugin Loaded: " << pluginPath << "\n";
    }

    // Register statistics plugins
    else if (pluginType == "statistics") {
        const char* (*getTaskName)() = (const char* (*)())dlsym(pluginHandle, "getTaskName");
        void (*executeTask)() = (void (*)())dlsym(pluginHandle, "executeTask");

        if (!getTaskName || !executeTask) {
            cerr << "Failed to find statistics plugin functions: " << dlerror() << "\n";
            dlclose(pluginHandle);
            return;
        }

        PluginTask task = {getTaskName(), executeTask};
        statisticsTasks.push_back(task);
        cout << "Statistics Plugin Loaded: " << task.taskName << "\n";
    }
}

// Discover and load all plugins
void discoverPlugins(const string& pluginDir) {
    for (const auto& entry : fs::directory_iterator(pluginDir)) {
        if (entry.path().extension() == ".so") {
            loadPlugin(entry.path().string());
        }
    }
}

// Function to configure and load plugins
void configurePlugins()
{
    string pluginDir = "../plugins/so";

    // Validate plugin directory
    if (!fs::exists(pluginDir) || !fs::is_directory(pluginDir))
    {
        cerr << "Plugin directory not found: " << pluginDir << "\n\n";
        return;
    }

    // Gather available plugins
    vector<string> plugins;
    for (const auto &entry : fs::directory_iterator(pluginDir))
    {
        if (entry.path().extension() == ".so")
        {
            plugins.push_back(entry.path());
        }
    }

    // Check if plugins are available
    if (plugins.empty())
    {
        cout << "No plugins found in directory: " << pluginDir << endl;
        return;
    }

    // Display available plugins
    cout << "Available Plugins:\n";
    for (size_t i = 0; i < plugins.size(); ++i)
    {
        cout << i + 1 << ". " << plugins[i] << "\n";
    }

    // User options
    int choice;
    cout << "\nOptions:\n";
    cout << "1. Load a single plugin\n";
    cout << "2. Load all plugins\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        // User selects a single plugin
        int pluginChoice;
        cout << "Enter the plugin number to load: ";
        cin >> pluginChoice;

        if (pluginChoice > 0 && pluginChoice <= (int)plugins.size())
        {
            loadPlugin(plugins[pluginChoice - 1]);
        }
        else
        {
            cout << "Invalid plugin number.\n";
        }
    }
    else if (choice == 2)
    {
        // Load all plugins
        for (const auto &plugin : plugins)
        {
            loadPlugin(plugin);
        }
    }
    else
    {
        cout << "Invalid option. No plugins loaded.\n\n";
    }
}

void displayMenu() {
    int choice;
    while (true) {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Application Tracking\n";
        std::cout << "2. Apply for Institute\n";

        // Add statistics plugin tasks
        for (size_t i = 0; i < statisticsTasks.size(); ++i) {
            std::cout << i + 3 << ". " << statisticsTasks[i].taskName << "\n";
        }

        std::cout << statisticsTasks.size() + 3 << ". Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (choice == 1) {
            Microkernel::trackApplicationStatus();
        } else if (choice == 2) {
            Microkernel::applyForInstitute();
        } else if (choice > 2 && choice <= (int)(statisticsTasks.size() + 2)) {
            // Execute the selected plugin task
            statisticsTasks[choice - 3].executeTask();
        } else if (choice == (int)(statisticsTasks.size() + 3)) {
            std::cout << "Exiting...\n";
            break;
        } else {
            std::cout << "Invalid option. Try again.\n";
        }
    }
}



// Main function
int main()
{
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
