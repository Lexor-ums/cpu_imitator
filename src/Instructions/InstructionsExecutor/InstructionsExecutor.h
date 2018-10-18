#ifndef INSTRUCTIONSEXECUTOR_H
#define INSTRUCTIONSEXECUTOR_H
#include <deque>
//#include "SimpleTask.h"
#include "Instructions.h"
#include <memory>

class TaskConfig;
class SimpleTask;
class InstructionsExecutor
{
public:
    /*!
     * \brief InstructionsExecutor конструктор класса, отвечающего за выполнения инструкций процесора
     * \param readyQueue - указатель на очередь готовых к выполнению. задач
     * \param blockQueue - указатель на очередь ожидающий разблокировки задач
     */
    InstructionsExecutor(std::deque<std::shared_ptr<SimpleTask> > * readyQueue,
                         std::deque<std::shared_ptr<SimpleTask> > * blockQueue);
    /*!
     * \brief exec исполняет инструкцию
     * \param timeElapsed - ссылка на оставшееся время кванта выполнения задачи
     * \param instruction - указатель на инструкцию
     * \return 0 - если был вызван блокирующий lock, иначе - 1
     */
    int exec(u_char &timeElapsed, std::shared_ptr<IBaseInstruction> &instruction);

private:
    std::deque<std::shared_ptr<SimpleTask> > * m_readyQueue;
    std::deque<std::shared_ptr<SimpleTask> > * m_blockQueue;
};

#endif // INSTRUCTIONSEXECUTOR_H
