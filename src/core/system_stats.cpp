//system stats such as CPU usage, Memory usage, and Uptime is displayed using this file
#include "../../include/system_stats.hpp"
#include <windows.h>
#include <sstream>

std::string SystemStats::getCPU_Usage() {
    // Placeholder for now (fix this after beta release)
    return "CPU: calculating...";
}
//Add memory usage function, uptime finctiom and complete the cpu usage function.

std::string SystemStats::getMemoryUsage() { //contains builtin and system level functions and keywords
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(memInfo);
    GlobalMemoryStatusEx(&memInfo);

    long long total = memInfo.ullTotalPhys / (1024 * 1024);
    long long used  = (memInfo.ullTotalPhys - memInfo.ullAvailPhys) / (1024 * 1024);

    std::ostringstream out;
    out << "Memory: " << used << " / " << total << " MB\n"<<(used/total)*100.0<<"%";
    return out.str();
}