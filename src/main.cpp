#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "cpp/utils.hpp"

int main() {
    // load file
    std::ifstream Script("test.stpd");

    std::vector<std::string> lines;

    std::string cache;

    while (getline (Script, cache)) {
        lines.push_back(cache);
    }

    Script.close();

    // output file
    for (size_t i = 0; i < lines.size(); i++) {
        std::vector<std::string> linepieces = splitString(lines[i], ':');
        linepieces[0] = removeChar(linepieces[0], ' ');

        if (linepieces[0] == "var") {
            std::vector<std::string> varPieces = splitString(linepieces[1], '=');

            Variable newVar;
            newVar.name = removeChar(varPieces[0], ' ');
            newVar.value = getValue(trim(varPieces[1], ' '));

            addVariable(newVar);
        } else if (linepieces[0] == "out") {
            std::cout << trim(getValue(trim(linepieces[1], ' ')), '\"') << std::endl;
        }
    }

    return 0;
}