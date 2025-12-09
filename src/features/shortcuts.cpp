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

