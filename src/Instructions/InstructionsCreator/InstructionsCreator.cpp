/**************************************************************************
**  File: InstructionsCreator.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 18.05.2018
**************************************************************************/
#include "InstructionsCreator.h"
#include <regex>
#include <tuple>
#include "BadValueException.h"

namespace  {
    constexpr auto gMaxValue = 100;
}

InstructionsCreator::InstructionsCreator()
{

}

std::shared_ptr<IBaseInstruction> AssignemetnCreator::create(const std::string &instructionStr, u_char execTime)
{
    auto key = 0u;
    auto value = 0u;
    std::vector<char*> tokens;
    char* pch = std::strtok(const_cast<char*>(instructionStr.c_str()), " =");
    tokens.push_back(pch);
    while (pch != nullptr)
    {
        pch = strtok (nullptr, " =");
        tokens.push_back(pch);
    }
    key = static_cast<u_char>(tokens[0][0]);
    value = static_cast<u_char>(std::stoul(tokens[1]));
    if(value > gMaxValue)
        throw BadValueException(value);
    return std::shared_ptr<IBaseInstruction>(new AssignementInstruction(key, value, execTime));
}

std::shared_ptr<IBaseInstruction> PrintCreator::create(const std::string &instructionStr, u_char execTime)
{
    auto key = 0u;
    char* pch = std::strtok(const_cast<char*>(instructionStr.c_str()), " ");
    while (pch != nullptr)
    {
        pch = strtok (nullptr, " =");
        if(pch != nullptr)
        {
            key = static_cast<u_char>(pch[0]);
        }
    }
    return std::shared_ptr<IBaseInstruction>(new PrintInstruction(key, execTime));
}

std::shared_ptr<IBaseInstruction> EndCreator::create(const std::string &instructionStr, u_char execTime)
{
    std::ignore = instructionStr;
    return std::shared_ptr<IBaseInstruction>(new EndInstruction(execTime));
}

std::shared_ptr<IBaseInstruction> LockCreator::create(const std::string &instructionStr, u_char execTime)
{
    std::ignore = instructionStr;
    return std::shared_ptr<IBaseInstruction>(new LockInstruction(execTime));
}

std::shared_ptr<IBaseInstruction> UnlockCreator::create(const std::string &instructionStr, u_char execTime)
{
    std::ignore = instructionStr;
    return std::shared_ptr<IBaseInstruction>(new UnlockInstruction(execTime));
}
