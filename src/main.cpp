//main.cpp: Includes all the application control flow
#include <iostream>


void showMenu() {
    std::cout<<"\n\t\_______\n";
    std::cout<<"\n\t\\    \/\n";
    std::cout<<"\n\t \\  \/\n";
    std::cout<<"\n\t  \\\/\n";
    std::cout<<"\n\t   \/\n";
    std::cout << "\n\t--- TermiFlow (beta) ---\n";
    std::cout << "1. Launch an application\n";
    std::cout << "2. Manage shortcuts\n";
    std::cout << "3. View running tasks\n";
    std::cout << "4. Change theme\n";
    std::cout << "5. Config settings\n";
    std::cout << "6. Check History\n";
    std::cout << "7. Session manager\n";
    std::cout << "8. Command handling\n";
    std::cout << "9. Exit\n";
}

int main() {
    int choice;

    while (true) {
        showMenu();
        /*std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                launchApp();//launch.cpp
                break;
            case 2:
                manageShortcuts();//shortcuts.cpp
                break;
            case 3:
                showRunningTasks(); //task_manager.cpp
                break;
            case 4:
                changeTheme(); //banner.txt .Needs a seperate file or just add in some related file 
                break;
            case 5:
                config(); //config_loader.cpp
                break;
            case 6:
                history(); //history.cpp
                break;
            case 7:
                sessionManager(); //session_manager.cpp
                break;
            case 8:
                cmdHandler(); //command_handler.cpp
                break;
            case 9:
                std::cout <<"Application terminated..\nHave a nice day!\n";
                return 0;
            default:
                std::cout << "Invalid option!\n";
        }
    }*/
    }
return 0;
}
