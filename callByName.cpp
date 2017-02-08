/*
 * Daniel Alves Paladim 2015
 */


#include <string>

#include "callByName.h"

namespace CBN {

inline static Container& getFunctionContainerInternal() {
    static Container functionContainer;
    return functionContainer;
}

const Container& getFunctionContainer() {
    return getFunctionContainerInternal();
}

void registerFunction(const std::string& name, CallableByName& function) {
    getFunctionContainerInternal().emplace(name, function);
}

void callFunction(const std::string& name) {
    getFunctionContainerInternal().at(name).run();
}

}
