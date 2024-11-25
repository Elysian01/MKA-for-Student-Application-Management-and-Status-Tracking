#include <iostream>
using namespace std;

extern "C" // to avoid name mangling, meaning other code can see this function written in C, with name initializePlugin
{
    void initializePlugin()
    {
        cout << "Email Notification Plugin Initialized.\n";
    }

    void sendEmail(const string &message)
    {
        cout << "Email: " << message << "\n";
    }
}
