#ifndef MICROKERNEL_H
#define MICROKERNEL_H

#include <string>
#include <vector>

class Microkernel
{
public:
    static void registerStudent(const std::string &name, const std::string &rollNumber);
    static void applyForInstitute();
    static void showDashboard(const std::string &name, const std::string &rollNumber);
    static void trackApplicationStatus();
    static void showAlerts(); // Declare the showAlerts function

    static std::vector<std::string> notifications; // Static notifications list
};

#endif // MICROKERNEL_H
