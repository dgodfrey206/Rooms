#include <iostream>
#include <sstream>
#include "lib/rooms_api.h"
#include "lib/rooms_level-1.cpp"
using namespace std;

//external variables
extern string location;

//global variables
const double version = 2;
int debug = 0;
string NAME;
string inv[12] = "empty";

int main()
{
    inv[11] = "last";
    bool result;
    string input;
    say("Welcome to Rooms!");
    say("This was originally a text-based game written in batch.");
    say("While it hasn't changed much, this is the C++ port which has better handling of functions, commands, and gameplay.");
    say("Would you like to play?");
    while (true)
    {
        cin >> input;
        if (input == "yes" || "y")
        {
            break;
        }
        if (input == "no" || "n")
        {
            say("program terminated...");
            exit(1);
        }
        if (input == "debug")
        {
            say("Debug mode enabled.");
            debug = 1;
            break;
        }
    }
    say("What is your name?");
    say("WARNING: This is used for your save file. Case sensitive.");
    cin >> NAME;
    say("Hello, " + NAME + ".");
    say("Would you like me to check if you have an existing save and load it?");
    say("If you decline, any save under your name will be overwritten.");
    input = "empty";
    while (true)
    {
        cin >> input;
        if (input == "y" || "yes")
        {
            break;
        }
        if (input == "n" || "no")
        {
            break;
        }
    }
    if (input == "y" || "yes")
    {
        result = save_check(NAME);
        if (result == true)
        {
            load(location);
        }
        else
        {
            say("not exist");
        }
    }
}
