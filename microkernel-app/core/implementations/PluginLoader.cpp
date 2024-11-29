#include "../headers/PluginLoader.h"

using namespace std;

void PluginLoader::load(const string &pluginPath) {
    void *pluginHandle = dlopen(pluginPath.c_str(), RTLD_LAZY);
    if (!pluginHandle) {
        cerr << "Failed to load plugin: " << dlerror() << "\n";
        return;
    }

    const char* (*getPluginType)() = (const char* (*)())dlsym(pluginHandle, "getPluginType");
    if (!getPluginType) {
        cerr << "Failed to find getPluginType: " << dlerror() << "\n";
        dlclose(pluginHandle);
        return;
    }

    string pluginType = getPluginType();
    if (!validateType(pluginType)) {
        cerr << "Invalid plugin type: " << pluginType << "\n";
        dlclose(pluginHandle);
        return;
    }

    registerPlugin(pluginHandle); // child class, specific implementation
}
