//
// Created by Blood on 13.12.2020.
//

#ifndef COMMANDSYSTEM_COMMAND_H
#define COMMANDSYSTEM_COMMAND_H

#include <iostream>
#include <string>
#include "LinkedList.h"

using std::string;
using std::getline;
using std::cin;
using std::cout;

class Command {
protected:
    string name;
    string property;
    string usage;
    LinkedList<string> alies;
    void addAliesWord(string word);
public:
    Command();
    Command(string name , string property , string usage, LinkedList<string> alies);
    Command(string name , string property , string usage);
    virtual void onExecute() {

    };
    bool check(string command);
};



#endif //COMMANDSYSTEM_COMMAND_H
