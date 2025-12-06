#include <iostream>
#include <string>
#include <sstream>
#include "../../include/command_handler.hpp"
#include "../../include/launch.hpp"

//header file error check proper linking of files
    void cmdHandler(const std::string& input) {
        std::stringstream ss(input);
        std::string command, appName;
        ss >> command >> appName;

        if (command == "launch") {
            launchApp(appName); // pass app name
        }
        // Add more command handling as needed
        else if (command == "exit" || command == "quit") {
            std::cout << "Command - line terminated !\n";
            return;
        }
        else if (command == "help") {
            std::cout << "\n\t-- Available commands --\n";
            std::cout << "launch <app>               : Launch an application\n";
            std::cout << "shortcut <add/delete>      : Manage shortcuts\n";
            std::cout << "tasks                      : View running tasks\n";
            std::cout << "theme <light/dark>         : Change theme\n";
            std::cout << "config                     : Config settings\n";
            std::cout << "histo                      : Check History\n";
            std::cout << "sm                         : Session manager\n";
            std::cout << "exit/quit                  : Exit\n";
        }
        else {
            std::cout << "Unknown command. Type 'help'.\n";
            return;
        }
    }
           
