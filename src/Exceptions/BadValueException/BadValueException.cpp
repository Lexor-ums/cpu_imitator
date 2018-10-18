/**************************************************************************
**  File: BadBalueException.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 22.05.2018
**************************************************************************/
#include "BadValueException.h"


BadValueException::BadValueException(u_char givenValue, u_char position) : m_givenValue(givenValue), m_pos(position)
{

}

std::string BadValueException::description()
{
    if(m_pos)
        return "Bad input value at string " + std::to_string(m_pos) + ". Given : " + std::to_string(m_givenValue) + " maximum : 100";
    else
        return "Bad input value. Given : " + std::to_string(m_givenValue) + " maximum : 100";
}

u_char BadValueException::givenValue() const
{
    return m_givenValue;
}
