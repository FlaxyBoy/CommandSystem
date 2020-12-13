//
// Created by Blood on 13.12.2020.
//

#include "Command.h"

Command::Command(string name, string property, string usage, LinkedList<string> allies) {
    this->name = name;
    this->property = property;
    this->usage = usage;
    this->alies = allies;
}

Command::Command(string name, string property, string usage) {
    this->name = name;
    this->property = property;
    this->usage = usage;
    this->alies = LinkedList<string>();
}

void Command::addAliesWord(string word) {
    this->alies.add(word);
}

bool Command::check(string command) {
    if(name == command) return true;
}