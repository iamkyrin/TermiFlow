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
    void add(const std::string& key, const std::string& value ); //def: default key; unew: user's new key
    void remove(const std::string& key);
    void save();
    void list();
    bool exists(const std::string& value);
    std::string getValue(const std::string& key);


};

#endif
