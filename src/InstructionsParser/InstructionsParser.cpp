/**************************************************************************
**  File: InstructionsParser.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 22.05.2018
**************************************************************************/
#include "InstructionsParser.h"
#include "BadValueException.h"
#include "ParseException.h"
#include <regex>
namespace  {
    constexpr auto confExpr = "(\\d[' ']+\\d[' ']+\\d[' ']+\\d[' ']+\\d[' ']+\\d[' ']+\\d$)";
    constexpr auto assigmentExpr = "(\\w[' ']+[=][' ']+\\d+$)";
    constexpr auto printExpr = "(\\bprint\\b[' ']\\w$)";
    constexpr auto lockExpr = "(\\block\\b$)";
    constexpr auto unlockExpr = "(\\bunlock\\b$)";
    constexpr auto endExpr = "(\\bend\\b$)";
}
InstructionsParser::InstructionsParser()
{

}

TaskConfig InstructionsParser::getConfig(const std::string &confStr)
{
    TaskConfig config;
    std::regex confRegExp(confExpr);
    if(std::regex_search(confStr,confRegExp))
    {
        std::regex digitRegExp("(\\d+)");
        auto digitsBegin = std::sregex_iterator(confStr.begin(), confStr.end(), digitRegExp);
        auto digitsEnd = std::sregex_iterator();
        int i = 0;
        for (std::sregex_iterator it = digitsBegin; it != digitsEnd; ++it, ++i) {
                std::smatch match = *it;
                config[i] = std::atoi(match.str().c_str());
            }
    }
    else
        throw ParseException(0);
    return config;
}

bool InstructionsParser::tryEnd(std::string commandLine)
{
    std::regex expr(endExpr);
    if(std::regex_search(commandLine, expr))
    {
        return true;
    }
    return false;
}

bool InstructionsParser::tryAssignement(std::string commandLine)
{
    std::regex expr(assigmentExpr);
    if(std::regex_search(commandLine, expr))
    {
        return true;
    }
    return false;
}

bool InstructionsParser::tryLock(std::string commandLine)
{
    std::regex expr(lockExpr);
    if(std::regex_search(commandLine, expr))
    {
        return true;
    }
    return false;
}

bool InstructionsParser::tryUnlock(std::string commandLine)
{
    std::regex expr(unlockExpr);
    if(std::regex_search(commandLine, expr))
    {
        return true;
    }
    return false;
}

bool InstructionsParser::tryPrint(std::string commandLine)
{
    std::regex expr(printExpr);
    if(std::regex_search(commandLine, expr))
    {
        return true;
    }
    return false;
}
