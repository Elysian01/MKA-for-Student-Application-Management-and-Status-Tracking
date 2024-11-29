#ifndef STATISTICSPLUGINLOADER_H
#define STATISTICSPLUGINLOADER_H

#include "./PluginLoader.h"
#include <string>
#include <iostream>
#include <vector>
#include <dlfcn.h>

struct PluginTask {
    std::string taskName;       // A string to store the name of the task
    void (*executeTask)();      // A pointer to a function that takes no arguments and returns void
};

// below is just referencing it, its def is present in the .cpp file
extern std::vector<PluginTask> statisticsTasks;

class StatisticsPluginLoader : public PluginLoader {
protected:
    bool validateType(const std::string &type) override;
    void registerPlugin(void *pluginHandle) override;
};

#endif 
