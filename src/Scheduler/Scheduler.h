/**************************************************************************
**  File: Scheduler.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 15.05.2018
**************************************************************************/
#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <queue>
#include <memory>
#include "SimpleTask.h"
#include "TaskCreator.h"
#include "InstructionsExecutor.h"

class Scheduler
{
public:
    /*!
     * \brief Scheduler конструктор класса планировщика задач
     * \param fileName ссылка на имя конфигурационного файла
     */\
    Scheduler(const std::string& fileName) noexcept(false);
    /*!
     * \brief go  запускает выполнение задачи
     */
    void go();
private:
    /*!
     * \brief getTaskList читает файл настроек и создаёт задачи
     * \param creator ссылка на класс, генерирующий задачи из инструкций
     */
    void getTaskList(TaskCreator &creator) noexcept(false);
    std::deque<std::shared_ptr<SimpleTask> > m_readyQueue;
    std::deque<std::shared_ptr<SimpleTask> > m_blockQueue;
    std::shared_ptr<InstructionsExecutor> m_instructionsExecutor;
};

#endif // SCHEDULER_H
