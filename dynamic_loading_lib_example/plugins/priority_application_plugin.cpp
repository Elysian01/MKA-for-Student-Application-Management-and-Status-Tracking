#include <iostream>
using namespace std;

extern "C" {
    void initializePlugin() {
        cout << "Priority Application Plugin: Processing high-priority applications...\n";
    }
}
