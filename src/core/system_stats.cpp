//system stats such as CPU usage, Memory usage, and Uptime is displayed using this file
#include "../../include/system_stats.hpp"
#include <windows.h>
#include <sstream>
#include <iostream>

std::string SystemStats::getCPU_Usage() {
    // Placeholder for now (fix this after beta release)
    return "CPU: calculating...";
}
//

std::string SystemStats::getMemoryUsage() { //contains builtin and system level functions and keywords
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(memInfo);
    GlobalMemoryStatusEx(&memInfo);

    long long total = memInfo.ullTotalPhys / (1024 * 1024);
    long long used  = (memInfo.ullTotalPhys - memInfo.ullAvailPhys) / (1024 * 1024);

    std::ostringstream out; //to return the whole coutput string as a return string
    out << "Memory: " << used << " / " << total << " MB\n"<<(used/total)*100.0<<"%"; //this is a string which is actually output
    return out.str();//returns the output string mentioned above
}
 //function for getting and calcuating uptime in seconds, minutes and hours.
std::string SystemStats::getUptime() {
    DWORD uptimeMs = GetTickCount();
    int seconds = uptimeMs / 1000.0;
    int minutes = seconds / 60.0;
    int hours = minutes / 60.0;

    std::ostringstream outputString;
    outputString << "Uptime: " << hours << "h " << (minutes / 60.0) << "m";
    return outputString.str();
}

void statsInteractive(){
    std::cout<<"Stats loading...\n";
    

}