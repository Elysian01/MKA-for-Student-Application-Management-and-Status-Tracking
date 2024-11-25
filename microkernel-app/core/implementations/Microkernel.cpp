#include "../headers/Microkernel.h"
#include <iostream>
#include <string>

using namespace std;

// Initialize static members
vector<string> Microkernel::notifications;
vector<function<void(const string &)>> Microkernel::observers;

void Microkernel::registerStudent(const string &name, const string &rollNumber)
{
    cout << "Student registered: " << name << " with Roll Number: " << rollNumber << "\n\n";
}

void Microkernel::applyForInstitute()
{
    string instituteName;
    cout << "Enter Institute Name: ";
    cin >> instituteName;

    string notification = "Applied for " + instituteName + " Institute";
    cout << notification << "\n";

    notifications.push_back(notification);
    notifyObservers(notification); // Notify all observers
}

void Microkernel::showDashboard(const string &name, const string &rollNumber)
{
    cout << "Student Dashboard:\n";
    cout << "Name: " << name << "\nRoll Number: " << rollNumber << "\n";
    showAlerts();
}

void Microkernel::trackApplicationStatus()
{
    cout << "Tracking application status...\n";
    // Example implementation; real tracking would involve more logic
}

void Microkernel::showAlerts()
{
    cout << "Alerts: \n";
    for (const auto &alert : notifications)
    {
        cout << alert << "\n";
    }
}

// Add an observer (plugin)
void Microkernel::addObserver(const function<void(const string &)> &observer)
{
    observers.push_back(observer);
}

// Notify all registered observers of a new notification
void Microkernel::notifyObservers(const string &notification)
{
    for (const auto &observer : observers)
    {
        observer(notification); // Call each observer's function
    }
}
