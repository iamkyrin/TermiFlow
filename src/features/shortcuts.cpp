//shortcuts.cpp file: for creating and managing user-defined shortcuts (for launch commands as of now)
#include <iostream>
#include <fstream>
#include "../../include/shortcuts.hpp"

void shortcuts::add(const std::string& key, const std::string& value){
    shortMap[key]=value;
    save();
    std::cout<<"Yeah !. Shortcut added: "<<key<<" -> "<<value<<"\n";
}

void shortcuts::remove(const std::string& value){

}
void shortcuts::save(){
    std::ofstream outfile(filepath);
    for(auto& p : shortMap) {
        outfile << p.first << "=" << p.second << "\n";
    }
    outfile.close()
}

void shortcuts::list(){

}

