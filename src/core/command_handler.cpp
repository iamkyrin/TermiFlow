#include <iostream>
#include <string>
#include <sstream>
#include "../../include/command_handler.hpp"
#include "../../include/launch.hpp"
#include "../../include/theme_manager.hpp"
#include "../../include/shortcuts.hpp"

//launch module is having errors; shortcut module works but mapping is wrong with wrong output , has errors too !!. Rest of the modules work correctly.
    void cmdHandler() {
        std::string input;
         //shortcuts class object declaration
        while(true){
            std::cout<<"\n>>>";
            //std::cin.clear();
            std::getline(std::cin,input); //'input' string is overloaded and no 'const' keyword used, check this.
            std::stringstream ss(input);
            std::string command, parameter;
            ss >> command >> parameter;

            shortcuts s;
            std::string extra1,extra2;
            std::stringstream kk(parameter);
            kk>>extra1>>extra2;

                if (command == "launch") {
                    
                    if(s.exists(extra2)) { //check whether user-created shortcut exists or not
                        parameter = s.getValue(extra2);
                    
                    launchApp(parameter); // pass app name
                }
                }
                // Add more command handling as needed

                else if(command == "theme"){ //theme dark and theme light
                        changeTheme(parameter);

                }
                else if(command == "shortcut"){
                    
            
            
                    //void mapCheck();//here s: object of class 'shortcuts'
                        if(parameter=="add"){
                            s.add(extra1, extra2);
                        }
                        else if(parameter=="remove"){
                            s.remove(extra2);
                        }
                        else if(parameter == "list"){
                            s.list();
                        }
                        else
                            std::cout<<"Invalid shortcut command !. Check 'help'\n";
                    }
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
                    break;
            }
        }
    }

           
