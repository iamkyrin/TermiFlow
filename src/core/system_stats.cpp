//system stats such as CPU usage, Memory usage, and Uptime is displayed using this file
//Check the entire flow of the program and understand it and test for various test cases.
#include "../../include/system_stats.hpp"
#include <windows.h>
#include <sstream>
#include <iostream>

std::string SystemStats::getCPU_Usage() {
    // Placeholder for now (fix this after beta release)
    return "CPU: N/A";
}

std::string SystemStats::getMemoryUsage() { //contains built-in and system level functions and keywords
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(memInfo);
    GlobalMemoryStatusEx(&memInfo);

    long long total = memInfo.ullTotalPhys / (1024 * 1024);
    long long used  = (memInfo.ullTotalPhys - memInfo.ullAvailPhys) / (1024 * 1024);

    std::ostringstream out; //to return the whole coutput string as a return string
    out << "Memory: " << used << " / " << total << " MB\t [" <<(used/float(total))*100<<"% ]"; //this is a string which is actually an output
    return out.str();//returns the output string mentioned above
}
 //function for getting and calculating uptime in seconds, minutes and hours.
std::string SystemStats::getUptime() {
    DWORD uptimeMs = GetTickCount();
    int seconds = uptimeMs / 1000.0;
    int minutes = seconds / 60.0;
    int hours = minutes / 60.0;

    std::ostringstream outputString;
    outputString << "Uptime: " << hours << "h " << minutes << "m";
    return outputString.str();
}

//fuction which displays all of the three details
void statsInteractive(){
    std::cout<<"Stats loading...\n";
    std::cout<<">>>>>>>>>>>>>>\n";
    std::string cpuDetails= SystemStats::getCPU_Usage();
    std::string memoryDetails= SystemStats::getMemoryUsage();
    std::string uptimeDetails= SystemStats::getUptime();
    std::cout<<cpuDetails<<"\n"<<memoryDetails<<"\n"<<uptimeDetails<<"\n";
}