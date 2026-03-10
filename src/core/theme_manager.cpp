//theme manager (includes both interactive and command line operations.)
#include "../../include/theme_manager.hpp"

void changeTheme(std::string theme){ //for command handler mode
    //std::string themeType;
    saveThemeToConfig(theme);
    #ifdef _WIN32
        if(theme=="light"){
            system("cls");
            system("color 70"); // white background with black text
        }
        else if(theme=="dark"){
            system("cls");
            system("color 07"); // black background with white text / default theme
        }
        else
            std::cout<<"Invalid theme !\n";
    #else
        if(theme=="light"){
            std::cout << "\033[47;30m"; // white background with black text
        }
        else if(theme=="dark"){
            std::cout << "\033[40;37m"; // black background with white text / default theme
        }
        else
            std::cout<<"Invalid theme !\n";
    #endif
}

void changeTheme(){  //for interactive mode (menu based)
    std::string themeType;
    std::cout<<"Enter theme: (dark / light) :";
    std::cin>>themeType;
    changeTheme(themeType);
}

void saveThemeToConfig(const std::string& theme) {
    std::ofstream file("config/termiflow.conf");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open config file for writing!\n";
        return;
    }
    file <<
        "[user_interface]\n"
        "theme=" << theme << "\n"
        "show_banner=true\n\n"
        "[behavior]\n"
        "auto_apply_theme=true\n";
    file.close();
    std::cout << "Theme saved successfully!\n";
}
