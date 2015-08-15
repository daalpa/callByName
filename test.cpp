/*
 * Daniel Alves Paladim 2015
 */


#include <iostream>
#include "callByName.h"

FUNCTION_CALL_BY_NAME(first_function) {
    std::cout << "Called first_function\n";
}

FUNCTION_CALL_BY_NAME(second_function) {
    std::cout << "Called second_function\n";
}

int main(int argc, char* argv[]) {
    if(argc > 1) {
        try {
        callFunction(argv[1]);
        } catch(std::out_of_range& ex) {
            std::cerr << "The function " << argv[1] << " does not exist." << '\n';
        }
    }
    else {
        std::cout << "No function to call provided. Type: " << argv[0] << " FUNCTION_NAME \n"
                     "where FUNCTION_NAME is any of the following\n";
        for(const auto& name_function : functionContainer) {
            std::cout << '\t' << name_function.first << '\n';
        }
    }
    return 0;
}