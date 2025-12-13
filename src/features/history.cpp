//history.cpp: handle operations of saving command_handler command history.
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
    cmdEntries.push_back(cmd); //push cmd(command entered) to vector cmdEntries
    save();
}

void history::list(){
    int indexNo = 1;
    std::cout<<"\t--- + --- cmd history --- + --- \n";
    for(auto& e : cmdEntries) { //for each loop
        std::cout << indexNo++ << ". " << e << "\n"; //feature: add latest command indicating label.
    }
}

std::string history::get(int index){
    if(index < 1 || index > (int)cmdEntries.size()){
        std::cout<<"Oops !. Command not found.\n";
        return "";
    }
    return cmdEntries[index - 1];
}

void history::historyClear(){
    cmdEntries.clear(); //to clear contents of vector cmdEntries.
    save();
    std::cout<<"History cleared!. Type some new commands to fill the cmd history.\n";
}

//interactive mode history operations handler function
void historyInteractive(){ 
    history h; //'h' : object of class 'history'
    char ch;
    std::string historyMethod;
    int cmdIndex;
    std::cout<<"\t-- Available history methods --\n";
    std::cout<<"<list>\t <goto>\n";
    std::cout<<"Enter method to be used: ";
    std::cin>>historyMethod;

    if(historyMethod == "list"){
        h.list();
    }
    else if(historyMethod == "goto"){ //yet to implement
        std::cout<<"Enter index no of the command you want: ";
        std::cin>>cmdIndex;
        h.get(cmdIndex);
    }
    else if(historyMethod == "clear"){
       std::cout<<"Danger: All cmd history will be wiped out!. Press 'y' to continue, 'n' to exit cleaning operation.";
       std::cin>>ch;
       if(ch == 'y' || ch == 'Y'){
            h.historyClear();
        }
       else if(ch == 'n' || ch == 'N'){
            std::cout<<"History cleaning process terminated.\n";
            return;
        }
        else{
            std::cout<<"Error!. The application is confused with your intentions. Try again.\n";
        }
    }
    else{
        std::cout<<"Invalid history method!.\n";
    }
}
