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

// Function to load and execute a plugin
void loadPlugin(const string &pluginPath)
{
    void *handle = dlopen(pluginPath.c_str(), RTLD_LAZY);
    if (!handle)
    {
        cerr << "Error loading plugin: " << dlerror() << endl;
        return;
    }

    typedef void (*PluginInit)();
    PluginInit initFunc = (PluginInit)dlsym(handle, "initializePlugin");
    if (!initFunc)
    {
        cerr << "Error finding initializePlugin function: " << dlerror() << endl;
        dlclose(handle);
        return;
    }

    initFunc();      // Call the plugin's initialize function
    dlclose(handle); // Close the plugin after use
}

void configurePlugins()
{
    cout << "Configuring Plugins .....\n";
    string pluginDir = "../plugins/so";
    vector<string> plugins;

    // Read all .so files from the plugin directory
    for (const auto &entry : fs::directory_iterator(pluginDir))
    {
        if (entry.path().extension() == ".so")
        {
            plugins.push_back(entry.path());
        }
    }

    if (plugins.empty())
    {
        cout << "No plugins found in directory: " << pluginDir << endl;
    }
    else
    {

        cout << "Available Plugins:\n";

        for (size_t i = 0; i < plugins.size(); ++i)
        {
            cout << i + 1 << ". " << plugins[i] << "\n";
        }

        int choice;
        cout << "Enter the plugin number: ";
        cin >> choice;

        if (choice > 0 && choice <= (int)plugins.size())
        {
            cout << "Loading plugin: " << plugins[choice - 1] << "\n";
            loadPlugin(plugins[choice - 1]);
        }
    }
}

int main()
{
    string studentName, rollNumber;

    configurePlugins();

    cout << "Enter Student Name: ";
    cin >> studentName;
    cout << "Enter Roll Number: ";
    cin >> rollNumber;
    Microkernel::registerStudent(studentName, rollNumber);
    DocumentVerification::verifyDocuments();

    int choice;
    while (true)
    {
        cout << "1. Application Tracking\n";
        cout << "2. Apply for Institute\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Microkernel::trackApplicationStatus();
            break;
        case 2:
            Microkernel::applyForInstitute();
            break;
        case 3:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
