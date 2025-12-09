//shortcuts.cpp file: for creating and managing user-defined shortcuts (for launch commands as of now)

//has errrors correct them !
#include <iostream>
#include <fstream>
#include "../../include/shortcuts.hpp"

void shortcuts::add(const std::string& key, const std::string& value){
    shortMap[key]=value; //assigning value to key(the default command word)
    save();
    std::cout<<"Yeah !. Shortcut added: "<<key<<" -> "<<value<<"\n";
}

void shortcuts::remove(const std::string& key){
    shortMap.erase(key); //erase() : erases the 'key' passed to it from the unordered map.
    save();
    std::cout<<"Shortcut for "<<key<<" removed!.\n";

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
        std::cout << " - " << p.first << " -> " << p.second << "\n";
    }

}
bool shortcuts::exists(const std::string& value){
    return shortMap.find(value) != shortMap.end();
}
std::string shortcuts::getValue(const std::string& key){
    std::string value;
    if(exists(key)){
    value= shortMap[key];
    }
    return value;  //returns actual default command mapped shortcut. e.g., returns 'chrome' for 'launch c'.
}

