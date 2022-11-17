#include <string>
#include <vector>
#include <iostream>

#include "../variables/variableManager.hpp"
#include "../math/math.hpp"
#include "../strings/stringHandler.hpp"
#include "../bools/boolManager.hpp"
#include "../../c/cBools/cBools.h"

const char* removeFirstCharInString(const char* input) {
    std::string str = input;
    std::string output = "";

    if (str.size() < 2) {
        throw 69;
    }

    for (size_t i = 1; i < str.size(); i++) {
        output += str[i];
    }
    
    return output.c_str();
}

std::string combineArgs(std::vector<std::string> input , size_t start) {
    std::string output = "";

    for (size_t i = start; i < input.size(); i++) {
        output += input[i];
        if (i + 1 < input.size()) {
            output += ":";
        }
    }
    

    return output;
}

std::string removeChar(std::string input, char remove) {
    std::string output = "";

    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] != remove) {
            output += input[i];
        }
    }

    return output;
}

std::vector<std::string> splitString(std::string input, char splitter) {
    std::vector<std::string> output;
    std::string cache = "";

    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == splitter) {
            output.push_back(cache);
            cache = "";
            continue;
        } else {
            cache += input[i];
            continue;
        }
    }

    output.push_back(cache);
    cache = "";

    return output;
}


std::string trim(std::string input, char trimmer) {
    size_t start = 0;
    size_t end = input.size();
    std::string output = "";

    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] != trimmer) {
            start = i;
            break;
        }
    }

    for (size_t i = input.size() - 1; i >= 0; i--) {
        if (input[i] != trimmer) {
            end = i + 1;
            break;
        }
    }

    for (size_t i = start; i < end; i++) {
        output += input[i];
    }

    return output;
}

std::string getValue(std::string input) {
    std::string trimmedInput = trim(input, ' ');

    if (isVariable(trimmedInput)) {
        return getVariable(trimmedInput).value;
    }

    if (isBool(trimmedInput.c_str())) {
        return trimmedInput;
    }

    if (trimmedInput[0] == '!') {
        std::cout << "test" << std::endl;
        std::string uninverted = removeFirstCharInString(trimmedInput.c_str());
        std::cout << "uninverted bool: " + uninverted << std::endl;

        if (isBool(uninverted.c_str())) {
            std::cout << "inverted bool: " + std::to_string(!strToBool(uninverted.c_str())) << std::endl;

            return std::to_string(strToBool(uninverted.c_str()));
        }
    }
    
    try {
        return std::to_string(solveEquasion(removeChar(input, ' ')));
    } catch (int mathErr) {
        try {
            return makeStpdString(input);
        } catch (int strErr) {
            try {
                return solveBool(trimmedInput);
            } catch (int boolErr) {
                throw 69;
            }
        }
    }

    return input;
}