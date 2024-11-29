#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include <string>
#include <dlfcn.h>
#include <iostream>

class PluginLoader {
protected:
    // Hook to validate plugin type
    virtual bool validateType(const std::string &type) = 0;

    // Hook method: Register the plugin-specific functionality like adding to observer list, and adding to task list
    virtual void registerPlugin(void *pluginHandle) = 0;


public:
    /* By making the destructor virtual, you ensure that the destructor of the correct derived class is called when an object is deleted through a base class pointer. */
    /* Without a virtual destructor, only the destructor of the base class (PluginLoader) would be called, and the destructor of the derived class (NotificationPluginLoader) would not be invoked. This could lead to resource leaks if the derived class allocates resources (like memory or file handles) and doesn't release them. */ 
    virtual ~PluginLoader() = default;

    // Template method: Loads the plugin and invokes specific hooks
    void load(const std::string &pluginPath); // this internally uses validateType & registerPlugin
};

#endif 
