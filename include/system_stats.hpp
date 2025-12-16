#ifndef SYSTEM_STATS_HPP
#define SYSTEM_STATS_HPP

#include <string>

class SystemStats {
public:
    static std::string getCPUUsage();
    static std::string getMemoryUsage();
    static std::string getUptime();
};

#endif