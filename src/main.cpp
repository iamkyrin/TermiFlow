//main.cpp: Includes all the application control flow
#include <iostream>
#include <cctype>
#include "../include/command_handler.hpp"
#include "../include/launch.hpp"
#include "../include/shortcuts.hpp"
#include "../include/task_manager.hpp"
#include "../include/theme_manager.hpp"
#include "../include/config_loader.hpp"
#include "../include/history.hpp"
#include "../include/session_manager.hpp"
#include "../include/system_stats.hpp"

void showMenu() {
    
    std::cout << "\n\t--- TermiFlow (beta) ---\n";
    std::cout << "1. Launch an application\n";
    std::cout << "2. Manage shortcuts\n";
    std::cout << "3. View running tasks\n";
    std::cout << "4. Change theme\n";
    std::cout << "5. Config settings\n";
    std::cout << "6. Check History\n";
    //std::cout << "7. Session manager\n";
    std::cout << "7. View systems stats\n";
    std::cout << "8. Command handling\n";
    std::cout << "9. Exit\n";
}

int main() {
    char choice='0';
    std::string buffer;

    while (true) {
        showMenu(); //display menu
        do{
            if(!isdigit(choice)){ //works only when the input is not a digit
                std::cout<<"Error!. Invalid choice format. (Use digits such as 1, 2, ..., 10)\n";
            }
            std::cout<<"Enter your choice: ";
            std::cin>> choice;
        }
        while(!isdigit(choice));//loops if the input is not a digit
        std::getline(std::cin, buffer);

        switch (choice) {
            case 1:
                launchApp();
                break;
            case 2:
                shortcutsInteractive(); 
                break;
            case 3:
                sessionManager();  //N/A
                break;
            case 4:
                changeTheme();
                break;
            case 5:
                config(); //N/A
                break;
            case 6:
                historyInteractive();
                break;
            case 7:
                statsInteractive(); // Partially N/A
                break;
            case 8: 
                sessionManager(); //N/A
                break;
            case 9:
                cmdHandler();
                break;
                
            case 10:
                std::cout <<"Application terminated..\nHave a nice day!\n";
                return 0;
            default:
                std::cout << "Invalid option!. Try again.\n";
        }
    }
    return 0;
}


