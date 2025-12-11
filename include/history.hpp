//header file for history.cpp

#include <string>
#include <vector>

class History {
public:
    History(const std::string& path);

    void load();
    void save();

    void add(const std::string& cmd);
    void list() const;
    std::string get(int index) const;

private:
    std::string filePath;
    std::vector<std::string> entries;
};
