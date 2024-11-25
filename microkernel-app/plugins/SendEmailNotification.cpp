#include <iostream>
using namespace std;

extern "C" // to avoid name mangling, meaning other code can see this function written in C, with name initializePlugin
{
    // Plugin initialization
    void initializePlugin()
    {
        cout << "Email Notification Plugin Initialized.\n";
    }

    // Hook to handle new notifications
    void onNotificationReceived(const string &notification)
    {
        cout << "[Email Plugin] New Notification: " << notification << "\n";
    }
}
