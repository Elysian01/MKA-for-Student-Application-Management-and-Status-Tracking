#include "../headers/StatisticsPluginLoader.h"

using namespace std;

vector<PluginTask> statisticsTasks;

bool StatisticsPluginLoader::validateType(const string &type) {
    return type == "statistics";
}

void StatisticsPluginLoader::registerPlugin(void *pluginHandle) {
    const char* (*getTaskName)() = (const char* (*)())dlsym(pluginHandle, "getTaskName");
    void (*executeTask)() = (void (*)())dlsym(pluginHandle, "executeTask");

    if (!getTaskName || !executeTask) {
        cerr << "Failed to find required functions for statistics plugin: " << dlerror() << "\n";
        dlclose(pluginHandle);
        return;
    }

    PluginTask task = {getTaskName(), executeTask};
    statisticsTasks.push_back(task);
    cout << "Statistics plugin registered: " << task.taskName << "\n";
}
