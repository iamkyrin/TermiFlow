//header file for shortcuts.cpp 
#ifndef SHORTCUTS
#define SHORTCUTS

#include <string>
#include <sstream>
#include <unordered_map>

class shortcuts {
    private:
    std::unordered_map<std::string, std::string> shortMap;
    std::string filepath;

    public:
    void add(const std::string& def, const std::string& unew ); //def: default key; unew: user's new key
    void remove(const std::string& def);
    void save();
    void list();

};

#endif
