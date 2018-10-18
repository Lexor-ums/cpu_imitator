/**************************************************************************
**  File: BadStructureException.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 22.05.2018
**************************************************************************/
#include "BadStructureException.h"

BadStructureException::BadStructureException()
{

}

std::string BadStructureException::description()
{
    return "Task don`t have end instruction or its synax is invalid";
}
