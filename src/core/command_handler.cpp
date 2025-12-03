#include <iostream>
#include <sstream>
#include <string>

void handleCommand(const std::string& input) {
    std::stringstream ss(input);
    std::string command;
    ss >> command;

    if (command == "launch") {
        std::string app;
        ss >> app;
        launchApplication(app);    // pass app name
    }

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

    else if (command == "help") {
        std::cout << "\n\t--Available commands --\n";
        std::cout << "launch <app>               : Launch an application\n";
        std::cout << "shortcut add/remove <name> : Manage shortcuts\n";
        std::cout << "tasks                      : View running tasks\n";
        std::cout << "theme <light/dark>         : Change theme\n";
        std::cout << "config                     : Config settings\n";
        std::cout << "histo                      : Check History\n";
        std::cout << "sm                         : Session manager\n";
        std::cout << "cmdhand                    : Command handling\n";
        std::cout << "exit/quit                  : Exit\n";
    }

    else {
        std::cout << "Unknown command. Type 'help'.\n";
    }
}