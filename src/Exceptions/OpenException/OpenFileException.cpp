/**************************************************************************
**  File: OpenFileException.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 15.05.2018
**************************************************************************/
#include "OpenFileException.h"

OpenFileException::OpenFileException(const std::string& fileName): m_fileName(fileName)
{

}

std::string OpenFileException::description()
{
    return "Cant open file " + m_fileName;
}
