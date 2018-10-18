/**************************************************************************
**  File: Instructions.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 15.05.2018
**************************************************************************/
#include "Instructions.h"


AssignementInstruction::AssignementInstruction(u_char param, u_char value, u_char exec) : m_param(param),
    m_value(value), m_execTime(exec)
{

}

void AssignementInstruction::execNext()
{
    SharedMemory::instance().setParam(m_param, m_value);
}

u_char AssignementInstruction::execTime() const
{
    return m_execTime;
}

PrintInstruction::PrintInstruction(u_char param, u_char exec ): m_param(param), m_execTime(exec)
{

}

void PrintInstruction::execNext()
{
    std::cout<<static_cast<int>(SharedMemory::instance().getParam(m_param))<<std::endl;
}

u_char PrintInstruction::execTime() const
{
    return m_execTime;
}

LockInstruction::LockInstruction(u_char exec) : m_execTime(exec)
{

}

void LockInstruction::execNext()
{
}

u_char LockInstruction::execTime() const
{
    return m_execTime;
}

void LockInstruction::setExecTime(const u_char &execTime)
{
    m_execTime = execTime;
}

UnlockInstruction::UnlockInstruction(u_char exec) : m_execTime(exec)
{

}

void UnlockInstruction::execNext()
{
}

u_char UnlockInstruction::execTime() const
{
    return m_execTime;
}

EndInstruction::EndInstruction(u_char exec) : m_execTime(exec)
{

}

void EndInstruction::execNext()
{
}

u_char EndInstruction::execTime() const
{
    return m_execTime;
}
