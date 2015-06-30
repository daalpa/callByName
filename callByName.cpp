#include <string>

#include "callByName.h"

std::map<std::string, CallableByName*> functionContainer;
void registerFunction(const std::string& name, CallableByName* function) {
    functionContainer[name] = function;
}

void callFunction(const std::string name) {
    functionContainer[name]->run();
}