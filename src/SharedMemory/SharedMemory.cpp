/**************************************************************************
**  File: sharedmemory.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 15.05.2018
**************************************************************************/
#include "SharedMemory.h"

SharedMemory &SharedMemory::instance()
{
    static SharedMemory obj;
    return  obj;
}

u_char SharedMemory::getParam(u_char key) const
{
    return m_paramsState.at(key);
}

void SharedMemory::setParam(u_char key, u_char value)
{
    m_paramsState[key] = value;
}

SharedMemory::SharedMemory()
{
    if(!m_initialized)
    {
        initValues();
        m_initialized = true;
    }
}

SharedMemory::~SharedMemory()
{

}

void SharedMemory::initValues()
{
    for(u_char ch = 'a'; ch <= 'z'; ++ch )
        m_paramsState[ch]= static_cast<u_char>(0);
}
