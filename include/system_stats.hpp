//system_stats.cpp header file
#ifndef SYSTEM_STATS
#define SYSTEM_STATS

#include <string>

class SystemStats {
public:
    static std::string getCPU_Usage();
    static std::string getMemoryUsage();
    static std::string getUptime();
};

#endif