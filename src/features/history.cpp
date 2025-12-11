//history.cpp: handles operation of saving command_handler command history
#include <string>
#include <fstream>
#include <iostream>
#include "../../include/history.hpp"

//go through and understand all of these functions and what they do. write comments once its clear to follow through.
void history::load() {
    cmdEntries.clear();
    std::ifstream infile("history.txt");
    if(!infile.is_open()){
        return;
    }

    std::string line;
    while(std::getline(infile, line)) {
        cmdEntries.push_back(line);
    }
    infile.close();
}

void history::save() {
    std::ofstream outfile("history.txt");
    for(auto& e : cmdEntries) { //for each loop
        outfile << e << "\n";
    }
    outfile.close();
}

history::history(){
    load();
}
void history::add(const std::string& cmd) {
    cmdEntries.push_back(cmd);
    save();
}

void history::list(){
    int idx = 1;
    for(auto& e : cmdEntries) { //for each loop
        std::cout << idx++ << ". " << e << "\n";
    }
}

std::string history::get(int index){
    if(index < 1 || index > (int)cmdEntries.size()){
        return "";
    }
    return cmdEntries[index - 1];
}