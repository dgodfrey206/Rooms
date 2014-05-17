#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

//external variables
extern string NAME;
extern int debug;
extern string inv[];

//global variables
string location;
string save_dat[21];

void say(string msg)
{
    cout << msg << endl;
    return;
}

bool save_check(string dir)
{
    location = "saves/" + dir + ".txt";
    ifstream check(location.c_str());
    return check;
}

void load(string dir)
{
    int i = 3;
    ifstream sav(dir.c_str());
    sav >> save_dat[1];
    sav >> save_dat[2];
    if (save_dat[2] != "inv_start")
    {
        say("FATAL ERROR AT rooms_api.load(" + dir.c_str() + ")");
        say("Your save failed to load! Please create a new one to avoid this message.");
        exit(2);
    }
    while (save_dat[i] != "inv_end")
    {
        sav >> save_dat[i];
        if (save_dat[i] == "save_end")
        {
            say("FATAL ERROR AT rooms_api.load" + dir.c_str() + ")");
            say("Your save failed to load! Please create a new one to avoid this message.");
            exit(2);
        }
        i++;
    }

}

