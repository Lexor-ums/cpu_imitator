#include "InstructionsExecutor.h"
#include "SimpleTask.h"
#include <typeinfo>
#include <typeindex>
#include <algorithm>

namespace {
    bool gHasBlocked = false;
    u_char gLockCount = 0;
}//unnamed namespace

InstructionsExecutor::InstructionsExecutor(std::deque<std::shared_ptr<SimpleTask> > * readyQueue,
                                           std::deque<std::shared_ptr<SimpleTask> > * blockQueue) : m_readyQueue(readyQueue), m_blockQueue(blockQueue)
{
}

int InstructionsExecutor::exec(u_char &timeElapsed, std::shared_ptr<IBaseInstruction>& instruction)
{
    if(typeid (*instruction.get()) == typeid (PrintInstruction))
    {
        std::cout<<(int)m_readyQueue->front().get()->id()<<" : ";
        instruction.get()->execNext();
        timeElapsed -= instruction.get()->execTime();
    }
    if(typeid (*instruction.get()) == typeid (AssignementInstruction))
    {
        instruction.get()->execNext();
        timeElapsed -= instruction.get()->execTime();
    }
    if(typeid (*instruction.get()) == typeid (LockInstruction))
    {
        instruction.get()->execNext();
        timeElapsed -= instruction.get()->execTime();
        if(gHasBlocked)
        {
            m_blockQueue->push_back(m_readyQueue->front());
            m_readyQueue->pop_front();
            ++gLockCount;
            return 0;
        }
        gHasBlocked = true;
    }
    if(typeid (*instruction.get()) == typeid (UnlockInstruction))
    {
        instruction.get()->execNext();
        timeElapsed -= instruction.get()->execTime();
        if(gLockCount > 0)
        {
            m_readyQueue->push_back(m_readyQueue->front());
            m_readyQueue->pop_front();
            m_readyQueue->push_front(m_blockQueue->front());
            m_blockQueue->pop_front();
            gHasBlocked = false;
            --gLockCount;
            return 1;
        }
        gHasBlocked = false;
    }
    if(typeid (*instruction.get()) == typeid (EndInstruction))
    {
        instruction.get()->execNext();
        timeElapsed -= instruction.get()->execTime();
        m_readyQueue->pop_front();
        return 0;
    }
    m_readyQueue->push_back(m_readyQueue->front());
    m_readyQueue->pop_front();
    return 1;
}

