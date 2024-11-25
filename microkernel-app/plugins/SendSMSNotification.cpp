#include <iostream>
using namespace std;

extern "C"
{
    // Plugin initialization
    void initializePlugin()
    {
        cout << "SMS Notification Plugin Initialized.\n";
    }

    // Hook to handle new notifications
    void onNotificationReceived(const string &notification)
    {
        cout << "[SMS Plugin] New Notification: " << notification << "\n";
    }
}
