// program for config implementation and management
#include "../../include/config_loader.hpp"
#include <fstream>
#include <sstream>
 
Config loadConfig(const std::string& path) {
    Config config;
    std::ifstream file(path);

    if (!file.is_open()) {
        // default config parameters
        config.values["user_interface.theme"] = "default";
        config.values["user_interface.show_banner"] = "true";
        config.values["behavior.auto_apply_theme"] = "true";
        return config;
    }

    std::string line, section;

    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#')
            continue;

        if (line.front() == '[' && line.back() == ']') {
            section = line.substr(1, line.size() - 2);
        } else {
            auto pos = line.find('=');
            if (pos == std::string::npos) continue;

            std::string key = section + "." + line.substr(0, pos);
            std::string value = line.substr(pos + 1);

            config.values[key] = value;
        }
    }
    return config;
}
