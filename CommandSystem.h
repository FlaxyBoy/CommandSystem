//
// Created by Blood on 13.12.2020.
//

#ifndef COMMANDSYSTEM_COMMANDSYSTEM_H
#define COMMANDSYSTEM_COMMANDSYSTEM_H

#include "Command.h"

class CommandSystem {
private:
    LinkedList<Command> commands;
    bool enable;
    static LinkedList<string> getArgs(string line);
public:
    CommandSystem();
    void registerCommand(Command command);
    void start();
    void stop();
};


#endif //COMMANDSYSTEM_COMMANDSYSTEM_H
