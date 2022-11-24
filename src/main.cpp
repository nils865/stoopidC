#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

#include "cpp/utils/utils.hpp"
#include "cpp/math/math.hpp"
#include "cpp/strings/stringHandler.hpp"
#include "cpp/bools/boolManager.hpp"
#include "cpp/comment/comment.hpp"
#include "cpp/exception/exceptionHandler.hpp"
#include "cpp/exception/errorMessages.hpp"

size_t line = 0;

size_t getCurrentLine() {
    return line;
}

void setCurrentLine(size_t number) {
    line = number;
}

int main(int argc, char *argv[]) {
    std::vector<std::string> lines;
    std::string filename = "";

    if (argc > 1) {
        // load file
        filename = argv[1];
        std::ifstream Script(filename);
        std::string cache;

        while (getline (Script, cache)) {
            lines.push_back(cache);
        }

        Script.close();
    } else {
        std::cerr << "No filename was given!" << std::endl;
        return 1;
    }

    if (lines.size() < 1) {
        std::cerr << "The file " + filename + " doesn't exist!" << std::endl;
        return 1;
    }

    // output file
    for (line = 0; line < lines.size(); line++) {
        try {
            std::vector<std::string> linepieces = utils::splitString(removeComment(lines[line]), ':');
            linepieces[0] = utils::removeChar(linepieces[0], ' ');

            if (linepieces[0] == "var") {
                // initialize a new variable
                std::vector<std::string> varPieces = getVarPieces(utils::combineArgs(linepieces, 1));

                Variable newVar;
                newVar.name = utils::removeChar(varPieces[0], ' ');
                newVar.value = utils::getValue(utils::trim(varPieces[1], ' '));

                addVariable(newVar);
            } else if (linepieces[0] == "out") {
                // print something to the output
                std::cout << removeQuotation(utils::getValue(utils::combineArgs(linepieces, 1))) << std::endl;
            } else if (linepieces[0] == "goto") {
                // change the next line read by the interpreter
                std::string args = utils::trim(utils::combineArgs(linepieces, ' '), 1);

                if (!isNumber(args)){
                    throw error::notANumber(args);
                }

                line = stoi(args) - 2;
            } else if (linepieces[0] == "sleep") {
                std::string arg = utils::getValue(utils::combineArgs(linepieces, 1));
                if (!isNumber(arg)) throw error::invalidValue(arg);
                int argnum = stoi(arg);
                if (argnum < 1) throw error::invalidValue(arg);

                std::this_thread::sleep_for(std::chrono::milliseconds(argnum));            
            } else if (linepieces[0] == "end") {
                // ends the execution of the script
                return 0;
            } else if (linepieces[0] == "goif") {
                std::string condition = utils::getValue(utils::combineArgs(linepieces, 2));

                if (condition == "true") {
                    if (!isNumber(utils::trim(linepieces[1], ' '))) {
                        throw error::notANumber(utils::trim(linepieces[1], ' '));
                    }

                    line = stoi(utils::trim(linepieces[1], ' ')) - 2;
                } else if (condition == "false") {
                    continue;
                } else {
                    throw error::notABoolean(condition);
                }
            } else if (linepieces[0] == "if") {
                std::string condition = utils::getValue(linepieces[1]);

                if (utils::combineArgs(linepieces, 2) != "{") {
                    return 1;
                }

                if (condition == "true") {
                    continue;
                } else if (condition == "false") {
                    continue;
                } else {
                    throw error::notABoolean(condition);
                }
            } else if (linepieces[0] == "" || linepieces[0][0] == '#') {
                // do nothing on empty lines pr comments
                continue;
            } else {
                std::vector<std::string> varPieces;

                try {
                    varPieces = getVarPieces(utils::combineArgs(linepieces, 0));
                } catch (std::string varErr) {
                    throw error::keywordNotFound(linepieces[0]);
                    return 1;
                }
                
                if (isVariable(varPieces[0])) {
                    setVariable(varPieces[0], utils::getValue(utils::trim(varPieces[1], ' ')));
                } else {
                    throw error::variableNotFound(varPieces[0]);
                }
            }
        } catch (std::string error) {
            throwException(error);
            return 1;
        }
    }

    return 0;
}