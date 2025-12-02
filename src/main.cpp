//main.cpp: Includes all the application control flow
#include <iostream>


void showMenu() {
    std::cout << "\n\t--- TermiFlow (beta) ---\n";
    std::cout << "1. Launch an application\n";
    std::cout << "2. Manage shortcuts\n";
    std::cout << "3. View running tasks\n";
    std::cout << "4. Change theme\n";
    std::cout << "5. Exit\n";
}

int main() {
    int choice;

    while (true) {
        showMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                launchApp();
                break;
            case 2:
                manageShortcuts();
                break;
            case 3:
                showRunningTasks();
                break;
            case 4:
                changeTheme();
                break;
            case 5:
                std::cout <<"Application terminated..\nHave a nice day!\n";
                return 0;
            default:
                std::cout << "Invalid option!\n";
        }
    }
}
