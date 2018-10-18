/**************************************************************************
**  File: Scheduler.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 15.05.2018
**************************************************************************/
#include "Scheduler.h"
#include "BadValueException.h"
#include "BadStructureException.h"

Scheduler::Scheduler(const std::string &fileName)
{
    try {
        TaskCreator creator(fileName);
        m_instructionsExecutor = std::make_shared<InstructionsExecutor>(&m_readyQueue, &m_blockQueue);
        getTaskList(creator);
    }
    catch (OpenFileException& ex) {
        throw ex;
    }
    catch (ParseException& ex) {
           throw ex;
    }
    catch (BadValueException& ex) {
        throw ex;
    }
    catch (BadStructureException& ex)
    {
        throw ex;
    }
}

void Scheduler::go()
{
    while(m_readyQueue.size() != 0)
    {
        m_readyQueue.front().get()->next();
    }
}

void Scheduler::getTaskList(TaskCreator& creator)
{
    int id = 1;
    while(creator.canCreate())
    {
        m_readyQueue.push_back(creator.createTask(m_instructionsExecutor, id));
        ++id;
    }
}

