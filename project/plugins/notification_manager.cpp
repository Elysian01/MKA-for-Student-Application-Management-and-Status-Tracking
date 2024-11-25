#include <iostream>

extern "C" void initializePlugin() {
    std::cout << "Notification Manager Plugin initialized!\n";
}
