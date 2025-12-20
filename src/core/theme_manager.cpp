//theme manager (includes both interactive and command line operations.)
#include "../../include/theme_manager.hpp"

void changeTheme(std::string theme){ //for command handler mode
    //std::string themeType;
    if(theme=="light"){
        system("color 70");//white background with black text
    }
    else if(theme=="dark"){
        system("color 07"); //black backgound with white text / default theme
    }
    else
        std::cout<<"Invalid theme !\n";
}

void changeTheme(){  //for interactive mode (menu based)
    std::string themeType;
    std::cout<<"Enter theme: (dark / light) :";
    std::cin>>themeType;
    changeTheme(themeType);
}
