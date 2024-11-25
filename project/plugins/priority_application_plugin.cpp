#include <iostream>

extern "C" void initializePlugin() {
    std::cout << "Priority Application Plugin initialized!\n";
}
