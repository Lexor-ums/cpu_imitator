/**************************************************************************
**  File: SimpleTask.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 15.05.2018
**************************************************************************/
#include "SimpleTask.h"



SimpleTask::SimpleTask(const TaskConfig& config, std::shared_ptr<InstructionsExecutor> &executor, const u_char id)
    : m_id(id), config(config), m_executor(executor)
{

}

void SimpleTask::addInstruction(std::shared_ptr<IBaseInstruction> ptr)
{
    m_instructionsQueue.push_back(ptr);
}

void SimpleTask::next()
{
    auto timeElapsed = config.quantum;
    while (timeElapsed > 0)
    {
        if (m_executor.get()->exec(timeElapsed, m_instructionsQueue.front()))
        {
            m_instructionsQueue.pop_front();
        }
    }
}

u_char SimpleTask::id() const
{
    return m_id;
}

void SimpleTask::setId(const u_char &id)
{
    m_id = id;
}
