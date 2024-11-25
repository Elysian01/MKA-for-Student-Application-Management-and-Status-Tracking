#include <iostream>
using namespace std;

extern "C" // to avoid name mangling, meaning other code can see this function written in C, with name initializePlugin
{
    const char* getPluginType() {
        return "statistics";
    }

    const char* getTaskName() {
        return "Recommend Institutes Based on Past Data, and providing statistics";
    }

    void executeTask() {
        std::cout << "Analyzing past data and generating recommendations...\n";
    }


    // Plugin initialization
    void initializePlugin()
    {
        cout << "Recommendation Statistics Plugin Initialized.\n";
    }

   
}
