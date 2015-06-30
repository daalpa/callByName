#include <iostream>
#include "callByName.h"

FUNCTION_CALL_BY_NAME(AAAA) {
    std::cout << "Called AAAA\n";
}

FUNCTION_CALL_BY_NAME(BBBB) {
    std::cout << "Called BBBB\n";
}

int main(int argc, char* argv[]) {
    callFunction(argv[1]);
    return 0;
}