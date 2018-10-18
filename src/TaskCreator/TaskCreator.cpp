/**************************************************************************
**  File: TaskCreator.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 15.05.2018
**************************************************************************/
#include "TaskCreator.h"
#include "BadStructureException.h"
#include "BadValueException.h"
#include <regex>
#include <numeric>
#include "SimpleTask.h"
bool TaskCreator::canCreate() const
{
    if(m_currentStep != (m_insrtuctionVector.size()))
        return true;
    else
        return false;
}

std::shared_ptr<SimpleTask> TaskCreator::createTask(std::shared_ptr<InstructionsExecutor>& executor, const u_char id)
{
    auto taskPtr = std::make_shared<SimpleTask>(m_config, executor, id);
    while(!iParser.tryEnd(m_insrtuctionVector[m_currentStep]) && m_currentStep < m_insrtuctionVector.size()  )
    {        
        if( iParser.tryAssignement(m_insrtuctionVector[m_currentStep]) )
        {
            try {
                taskPtr.get()->addInstruction(iCreator.craeteInstruction<AssignemetnCreator>(
                                                  m_insrtuctionVector[m_currentStep], m_config.assigmentTime));
            }
            catch (BadValueException& ex) {
                throw BadValueException(ex.givenValue(), m_currentStep + 1);
            }
        }
        else if(iParser.tryLock(m_insrtuctionVector[m_currentStep]))
        {
            taskPtr.get()->addInstruction(iCreator.craeteInstruction<LockCreator>(
                                              m_insrtuctionVector[m_currentStep],m_config.lockTime));
        }
        else if(iParser.tryPrint(m_insrtuctionVector[m_currentStep]))
        {
            taskPtr.get()->addInstruction(iCreator.craeteInstruction<PrintCreator>(
                                              m_insrtuctionVector[m_currentStep], m_config.outputTime));
        }
        else if(iParser.tryUnlock(m_insrtuctionVector[m_currentStep]))
        {
            taskPtr.get()->addInstruction(iCreator.craeteInstruction<UnlockCreator>(
                                              m_insrtuctionVector[m_currentStep], m_config.unlockTime));
        }
        else
        {
            throw ParseException(m_currentStep  +1);
        }
        ++m_currentStep;
    }
    ++m_currentStep;

    if(m_currentStep <= m_insrtuctionVector.size())
        taskPtr.get()->addInstruction(iCreator.craeteInstruction<EndCreator>(
                                          m_insrtuctionVector[m_currentStep], m_config.endTime));
    else
    {
        throw BadStructureException();
    }
    return taskPtr;
}

TaskCreator::TaskCreator(const std::string &fileName)
{
    try {
        ConfigReader reader(fileName, m_insrtuctionVector);
    }
    catch (OpenFileException & ex) {
        throw ex;
    }
    try {
        m_config = iParser.getConfig(m_insrtuctionVector[0]);
    }
    catch (ParseException& ex) {
        throw ex;
    }
}
