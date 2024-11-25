#include <iostream>
using namespace std;

extern "C"
{
    void initializePlugin()
    {
        cout << "Notification Manager Plugin: Sending notifications...\n";
    }

    void executePlugin()
    {
    }
}