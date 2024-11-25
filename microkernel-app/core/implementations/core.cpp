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

// Function to load and register a single plugin
void loadPlugin(const string &pluginPath)
{
    cout << "Loading plugin: " << pluginPath << "\n";

    // Load the plugin
    void *pluginHandle = dlopen(pluginPath.c_str(), RTLD_LAZY);
    if (!pluginHandle)
    {
        cerr << "Failed to load plugin: " << pluginPath << "\n";
        cerr << dlerror() << "\n";
        return;
    }

    // Get the initializePlugin function
    void (*initializePlugin)() = (void (*)())dlsym(pluginHandle, "initializePlugin");
    if (!initializePlugin)
    {
        cerr << "Failed to find initializePlugin in " << pluginPath << "\n";
        cerr << dlerror() << "\n";
        dlclose(pluginHandle);
        return;
    }

    // Get the onNotificationReceived function
    void (*notificationHandler)(const string &) = (void (*)(const string &))dlsym(pluginHandle, "onNotificationReceived");
    if (!notificationHandler)
    {
        cerr << "Failed to find onNotificationReceived in " << pluginPath << "\n";
        cerr << dlerror() << "\n";
        dlclose(pluginHandle);
        return;
    }

    // Initialize the plugin and register its notification handler
    initializePlugin();
    Microkernel::addObserver(notificationHandler);

    cout << "Plugin loaded and registered successfully: " << pluginPath << "\n\n";
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

// Main function
int main()
{
    string studentName, rollNumber;

    // Configure and load plugins
    configurePlugins();

    // Main flow
    cout << "Enter Student Name: ";
    cin >> studentName;
    cout << "Enter Roll Number: ";
    cin >> rollNumber;
    Microkernel::registerStudent(studentName, rollNumber);
    DocumentVerification::verifyDocuments();

    int choice;
    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Application Tracking\n";
        cout << "2. Apply for Institute\n";
        cout << "3. Show Dashboard\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cout << "\n";

        switch (choice)
        {
        case 1:
            Microkernel::trackApplicationStatus();
            break;
        case 2:
            Microkernel::applyForInstitute();
            break;
        case 3:
            Microkernel::showDashboard(studentName, rollNumber);
            break;
        case 4:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
