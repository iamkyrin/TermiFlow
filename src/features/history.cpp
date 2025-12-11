//history.cpp: handles operation of saving command_handler command history
#include <string>
#include <fstream>
#include <iostream>
#include "../../include/history.hpp"

void history::load() {
    cmdEntries.clear();
    std::ifstream infile(filePath);
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
    std::ofstream outfile(filePath);
    for(auto& e : cmdEntries) {
        outfile << e << "\n";
    }
    outfile.close();
}
