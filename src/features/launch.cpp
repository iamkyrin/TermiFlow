#include <iostream>
#include <windows.h>
#include "../../include/launch.hpp"

void launchApp() {
    std::string command;
    std::string appName;
    std::cout<<">>> launch ";
    std::cin>>appName;

    if (appName == "chrome") {
        command = "start chrome";
    }
    else if (appName == "vscode") {
        command = "code";
    }
    else if (appName == "notepad") {
        command = "notepad";
    }
    else {
        std::cout << "Unknown app: " << appName << "\n";
        return;
    }
    system(command.c_str());
    std::cout << "Launching " << appName << "...\n";
}
