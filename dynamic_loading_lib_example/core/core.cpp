#include <iostream>
#include <dlfcn.h>    // For dynamic library loading
#include <filesystem> // For reading directory contents
#include <vector>
#include <string>

using namespace std;
namespace fs = std::filesystem;

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

int main()
{
    string pluginDir = "./plugins/so";
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
        return 0;
    }

    cout << "Core system started.\n";
    cout << "Available Plugins:\n";

    for (size_t i = 0; i < plugins.size(); ++i)
    {
        cout << i + 1 << ". " << plugins[i] << "\n";
    }

    int choice;
    cout << "Enter the number of the plugin to load (or 0 to exit): ";
    cin >> choice;

    if (choice > 0 && choice <= (int)plugins.size())
    {
        cout << "Loading plugin: " << plugins[choice - 1] << "\n";
        loadPlugin(plugins[choice - 1]);
    }
    else
    {
        cout << "Exiting.\n";
    }

    return 0;
}
