//shortcuts.cpp file: for creating and managing user-defined shortcuts (for launch commands as of now)
#include <iostream>
#include <fstream>
#include "../../include/shortcuts.hpp"

void shortcuts::add(const std::string& value, const std::string& key){
    shortMap[value]=key; //assigning value to key(the default command word)
    save();
    std::cout<<"Yeah !. Shortcut added: "<<key<<" -> "<<value<<"\n";
}

void shortcuts::add(){
    int appChoice;
    std::string appShortcut;
    std::cout<<"\t-- Available apps --\n";
    std::cout<<"1: chrome\t2: notepad\t3: youtube\n";
    std::cout<<"Select the app to create shortcut for(choose 1/2/3): ";
    std::cin>>appChoice;
    std::cout<<"Create a custom shortcut: ";
    std::cin>>appShortcut;  //shortcut key e.g., 'ch' for chrome
    switch(appChoice){
        case 1: add(appShortcut,"chrome");
                break;
        case 2: add(appShortcut,"notepad");
                break;
        case 3: add(appShortcut,"youtube");
                break;
        default: std::cout<<"Invalid!. The app you want seems to be missing.\n";
    }
}

void shortcuts::remove(){
    std::string appShortcut; //variable to store shortcut to be deleted
    list();
    std::cout<<"Enter shortcut to be removed: ";
    std::cin>>appShortcut;
    remove(appShortcut);
}

void shortcuts::remove(const std::string& key){
    shortMap.erase(key); //erase() : erases the 'value' passed to it from the unordered map.
    std::cout<<"Shortcut for "<<key<<" removed!.\n";
    save();
}

void shortcuts::save(){
    std::ofstream outfile("shortcut_det.txt");
    for(auto& p : shortMap) { //for each loop
        outfile << p.first << "=" << p.second << "\n";
    }
    outfile.close(); //close file
}

void shortcuts::list(){
    std::cout << "Registered shortcuts:\n";
    for(auto& p : shortMap) { //for each loop
        std::cout<<"--"<< p.first << " -> " << p.second << "\n";
    }
}

void shortcuts::load() {
    shortMap.clear();
    std::ifstream infile("shortcut_det.txt");
    std::string line;
    while (std::getline(infile, line)) {
        size_t eq = line.find('='); //needs explanation for the entire function!!
        if (eq != std::string::npos) {
            std::string key = line.substr(0, eq);
            std::string value = line.substr(eq + 1);
            shortMap[key] = value;
        }
    }
    infile.close();
}

// Constructor: load shortcuts from file
shortcuts::shortcuts() { //needs explanation !!
    load();
}

bool shortcuts::exists(const std::string& value){
    if(shortMap.find(value) != shortMap.end()){
        return true;
    }
    return false;
}
std::string shortcuts::getValue(const std::string& value){
    std::string key;
    if(exists(value)){
        key= shortMap[value];
    }
    return key;  //returns actual default command mapped shortcut. e.g., returns 'chrome' for 'launch c'.
}
//interactive mode function which handles all shortcut functions.
void shortcutInteractive(){
    shortcuts s;
    std::string shortcutMethod;
    std::cout<<"\t-- Available shortcut methods --\n";
    std::cout<<"<add>\t <remove>\t<list>\n";
    std::cout<<"Enter method to be used: ";
    std::cin>>shortcutMethod;
                
    if(shortcutMethod == "add"){
        s.add();
    }
    else if(shortcutMethod == "remove"){
        s.remove();
    }
    else if(shortcutMethod == "list"){
        s.list();
    }
    else{
        std::cout<<"Invalid shortcut method!.";
    }
}

