#include "../headers/StudentDashboard.h"
#include "../headers/Microkernel.h"
#include <iostream>

void StudentDashboard::showStudentDetails(const std::string &name, const std::string &rollNumber)
{
    std::cout << "Name: " << name << "\nRoll Number: " << rollNumber << "\n";
}

void StudentDashboard::showAlerts()
{
    std::cout << "Checking for alerts...\n";
    for (const auto &alert : Microkernel::notifications)
    {
        std::cout << alert << "\n";
    }
}
