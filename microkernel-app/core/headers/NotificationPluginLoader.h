#ifndef NOTIFICATIONPLUGINLOADER_H
#define NOTIFICATIONPLUGINLOADER_H

#include "./PluginLoader.h"
#include "./Microkernel.h"
#include <string>
#include <iostream>
#include <dlfcn.h>

class NotificationPluginLoader : public PluginLoader {
protected:
    bool validateType(const std::string &type) override;
    void registerPlugin(void *pluginHandle) override;
};

#endif 
