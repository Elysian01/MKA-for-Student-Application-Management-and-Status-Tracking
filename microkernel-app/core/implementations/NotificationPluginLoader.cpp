#include "../headers/NotificationPluginLoader.h"

using namespace std;

bool NotificationPluginLoader::validateType(const string &type) {
    return type == "notification";
}

void NotificationPluginLoader::registerPlugin(void *pluginHandle) {
    void (*onNotificationReceived)(const string &) = 
        (void (*)(const string &))dlsym(pluginHandle, "onNotificationReceived");
    if (!onNotificationReceived) {
        cerr << "Failed to find onNotificationReceived: " << dlerror() << "\n";
        dlclose(pluginHandle);
        return;
    }

    Microkernel::addObserver(onNotificationReceived);
    cout << "Notification plugin registered successfully.\n";
}
