//header file for history.cpp

#include <string>
#include <vector>

class history {
public:
    void load(); //load commands
    void save(); //save commands
    history();
    void add(const std::string& cmd); //add command to history
    void list(); //list the past commands
    std::string get(int index);

private:
    std::string filePath;
    std::vector<std::string> cmdEntries;
};
history h;
