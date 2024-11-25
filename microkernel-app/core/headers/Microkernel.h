#ifndef MICROKERNEL_H
#define MICROKERNEL_H

#include <string>
#include <vector>
#include <functional>

class Microkernel
{
public:
    static std::vector<std::string> notifications;                          // Holds notifications
    static std::vector<std::function<void(const std::string &)>> observers; // Registered observers

public:
    static void registerStudent(const std::string &name, const std::string &rollNumber);
    static void applyForInstitute();
    static void showDashboard(const std::string &name, const std::string &rollNumber);
    static void trackApplicationStatus();
    static void showAlerts();

    // Observer registration
    static void addObserver(const std::function<void(const std::string &)> &observer);
    static void notifyObservers(const std::string &notification);
};

#endif // MICROKERNEL_H
