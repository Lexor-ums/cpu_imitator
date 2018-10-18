/**************************************************************************
**  File: ConfigReader.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 15.05.2018
**************************************************************************/
#include "ConfigReader.h"
#include <fstream>
#include <iostream>

ConfigReader::ConfigReader(const std::string& fileName, std::vector<std::string> &v)
{
    try {
        readFile(fileName, v);
    }
    catch (OpenFileException &exc) {
        throw exc;
    }
}

void ConfigReader::readFile(const std::string &fileName, std::vector<std::string> &v)
{
    std::ifstream input(fileName, std::ios_base::in);
    if(!input.is_open())
        throw OpenFileException(fileName);
    while (!input.eof()) {
        std::string str;
        std::getline(input, str);
        if(str.at(0) != '#')
        {
            v.push_back(str);
        }
    }
}
