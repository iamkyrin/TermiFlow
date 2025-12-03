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
        std::cout << "launch <app> : Launch an application\n";
        std::cout << "Manage shortcuts\n";
        std::cout << "View running tasks\n";
        std::cout << "Change theme\n";
        std::cout << "Config settings\n";
        std::cout << "Check History\n";
        std::cout << "Session manager\n";
        std::cout << "Command handling\n";
        std::cout << "Exit\n";
    }

    else {
        std::cout << "Unknown command. Type 'help'.\n";
    }
}