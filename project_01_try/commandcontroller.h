#ifndef COMMANDCONTROLLER_H
#define COMMANDCONTROLLER_H
#include <bits/stdc++.h>
#include "command.h"

class CommandController
{
private:
    CommandController();
    int pointer;
    QVector<Command> stack;
public:
    static CommandController& getInst();
    void addCommand(Command com);
    void undo(State* state);
    void redo(State* state);
};

#endif // COMMANDCONTROLLER_H
