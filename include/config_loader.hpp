//header file for config.cpp

#ifndef CONFIG_LOADER
#define CONFIG_LOADER

#include <string>
#include <unordered_map>

struct Config {
    std::unordered_map<std::string, std::string> values;
};

Config loadConfig(const std::string& path);

#endif
