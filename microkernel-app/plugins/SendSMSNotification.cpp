#include <iostream>
using namespace std;

extern "C"
{
    void initializePlugin()
    {
        cout << "SMS Notification Plugin Initialized.\n";
    }

    void sendSMS(const string &message)
    {
        cout << "SMS: " << message << "\n";
    }
}
