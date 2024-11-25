#include <iostream>
#include <dlfcn.h>  // For dynamic library loading
#include <string>
#include <vector>
#include <filesystem>  // For directory traversal

namespace fs = std::filesystem;  // Alias for filesystem namespace
using namespace std;

// Function to load and execute a plugin
void loadPlugin(const string &pluginPath) {
    void *handle = dlopen(pluginPath.c_str(), RTLD_LAZY); // reads .so file
    if (!handle) {
        cerr << "Error loading plugin: " << dlerror() << endl;
        return;
    }

    typedef void (*PluginInit)();
    PluginInit initFunc = (PluginInit)dlsym(handle, "initializePlugin");
    if (!initFunc) {
        cerr << "Error finding initializePlugin function: " << dlerror() << endl;
        dlclose(handle);
        return;
    }

    initFunc();  // Call the plugin's initialize function
    dlclose(handle);  // Close the plugin after use
}

int main() {
    cout << "Core system started.\n";

    vector<string> plugins;
    // Traverse the 'plugins' directory to find .so files
    for (const auto &entry : fs::directory_iterator("./plugins")) {
        if (entry.is_regular_file() && entry.path().extension() == ".so") {
            plugins.push_back(entry.path().string());
        }
    }
    if (plugins.empty()) {
        cerr << "No plugins found in the plugins directory." << endl;
        return 1;
    }

    cout << "Available Plugins:\n";

    for (size_t i = 0; i < plugins.size(); ++i) {
        cout << i + 1 << ". " << plugins[i] << "\n";
    }

    int choice;
    cout << "Enter the number of the plugin to load (or 0 to exit): ";
    cin >> choice;

    if (choice > 0 && choice <= static_cast<int>(plugins.size())) {
        cout << "Loading plugin: " << plugins[choice - 1] << "\n";
        loadPlugin(plugins[choice - 1]);
    } else {
        cout << "Exiting.\n";
    }

    return 0;
}
