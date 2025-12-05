#include <iostream>
#include <string>
#include <sstream>
#include "../../include/command_handler.hpp"
#include "../../include/launch.hpp"

//header file error check proper linking of files
void cmdHandler() {
    std::string input;
    std::string command;
    std::string app;
    while(true){
        std::cout<<"Enter command line instruction : ";
        std::getline(std::cin,input);
        std::stringstream ss(input);
        ss >> command;
        std::getline(ss, app);
        if (command == "launch") {
            launchApp(app);    // pass app name
        }
        /*
        else if (command == "shortcut") {
            std::string action;
            ss >> action;
            manageShortcuts(action);
        }

        else if (command == "tasks") {
            showRunningTasks();
        }

        else if (command == "theme") {
            std::string mode;
            ss >> mode;
            changeTheme(mode);
        }
        else if (command == "config") {
            config();
        }
        else if (command == "histo") {
            history();
        }
        else if (command == "sm") {
            sessionManager();
        }
        else */if(command == "exit" || command == "quit"){
            std::cout<<"Command - line terminated !\n";
            return;
        }
        else if (command == "help") {
            std::cout << "\n\t--Available commands --\n";
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
}