#include <iostream>
#include <string>
#include <array> // C++11
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

// external variables
extern string NAME;
extern int debug;
extern string inv[];

// global variables
std::string location;
std::array<std::string, 21> save_dat; // it is recommended that you use std::array rather than raw C-style arrays

void say(std::string msg)
{
    std::cout << msg << std::endl;
}

// Fixed bug:  Streams have an explicit boolean operator, using a stream as the return value of 
//             a boolean returning function should emit a compiler error. Fixed as of 2014-10-17 4:30PM

bool save_check(std::string dir)
{
    location = "saves/" + dir + ".txt";
    std::ifstream check(location.c_str());
    return check.is_open();
}

void load(std::string dir)
{
    int i = 3;
    std::ifstream sav(dir.c_str());
    sav >> save_dat[1] >> save_dat[2];
    
    if (save_dat[2] != "inv_start")
    {
        say("FATAL ERROR AT rooms_api.load(" + dir + ")");
        say("Your save failed to load! Please create a new one to avoid this message.");
        exit(2);
    }
    
    do
    {
        if (save_dat[i++] == "save_end")
        {
            say("FATAL ERROR AT rooms_api.load" + dir + ")");
            say("Your save failed to load! Please create a new one to avoid this message.");
            exit(2);
        }
    } while (save_dat[i] != "inv_end" || sav >> save_dat[i])
}