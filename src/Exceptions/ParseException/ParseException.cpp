/**************************************************************************
**  File: parseexception.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 16.05.2018
**************************************************************************/
#include "ParseException.h"


ParseException::ParseException(unsigned char badStr) : m_badString(badStr)
{

}

std::string ParseException::description()
{
    return "Cant`t parse file at string " + std::to_string(m_badString);
}
