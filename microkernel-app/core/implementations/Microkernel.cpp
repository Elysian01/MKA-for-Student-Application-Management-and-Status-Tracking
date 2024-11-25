#include "../headers/Microkernel.h"
#include "../headers/ApplicationStatusTracker.h"
#include <iostream>
#include <string>

using namespace std;

vector<string> Microkernel::notifications;

void Microkernel::registerStudent(const string &name, const string &rollNumber)
{
    cout << "Student registered: " << name << " with Roll Number: " << rollNumber << "\n";
}

void Microkernel::applyForInstitute()
{
    string instituteName;
    cout << "Enter Institute Name: ";
    cin >> instituteName;
    cout << "Applied for " << instituteName << " Institute.\n";
    notifications.push_back("Applied for " + instituteName + " Institute");
}

void Microkernel::showDashboard(const string &name, const string &rollNumber)
{
    cout << "Student Dashboard:\n";
    cout << "Name: " << name << "\nRoll Number: " << rollNumber << "\n";
    showAlerts(); // Now the compiler knows about showAlerts
}

void Microkernel::trackApplicationStatus()
{
    ApplicationStatusTracker::trackApplicationStatus();
}

void Microkernel::showAlerts()
{
    cout << "Alerts: \n";
    for (const auto &alert : notifications)
    {
        cout << alert << "\n";
    }
}
