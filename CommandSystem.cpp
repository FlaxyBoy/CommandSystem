//
// Created by Blood on 13.12.2020.
//

#include "CommandSystem.h"



CommandSystem::CommandSystem() {
    enable = true;
    commands = LinkedList<Command>();
}

void CommandSystem::start() {
    string line;
    while (enable) {
        getline(cin , line);
        cout << "\n";
        commands.updateIterator();
        bool flag = false;
        LinkedList<string> cmd = getArgs(line);
        while (cmd.hasNext()) {
            cout << "\n" << cmd.next();
        }
        cout << "\n";
    }
}

void CommandSystem::registerCommand(Command command) {
    commands.add(std::move(command));
}

void CommandSystem::stop() {
    enable = false;
}

LinkedList<string> CommandSystem::getArgs(string line) {
    LinkedList<string> list;
    string arg = "";
    for(int i = 0 ; i < line.length() ; i++) {
        char c = line.at(i);
        if(c == ' ') {
            list.add(arg);
            arg = "";
        }else {
            arg += c;
        }
    }
    return list;

}
