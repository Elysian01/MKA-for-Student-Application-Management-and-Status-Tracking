#ifndef STUDENT_DASHBOARD_H
#define STUDENT_DASHBOARD_H

#include <iostream>
#include <string>

class StudentDashboard
{
public:
    static void showStudentDetails(const std::string &name, const std::string &rollNumber);
    static void showAlerts();
};

#endif
