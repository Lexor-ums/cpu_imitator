/**************************************************************************
**  File: SimpleTask.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 15.05.2018
**************************************************************************/
#ifndef SIMPLETASK_H
#define SIMPLETASK_H
#include <iostream>
#include <queue>
#include "Instructions.h"
#include "InstructionsExecutor.h"
#include "TaskConfig.h"
#include <memory>

class SimpleTask
{
public:
    /*!
     * \brief SimpleTask конструктор класса, опитсывающего задачу
     * \param config ссылка на конфигурационный файл
     * \param executor ссылка на класс, следящий за выполением инструкций
     * \param id номер порядковй задачи
     */
    SimpleTask(const TaskConfig& config, std::shared_ptr<InstructionsExecutor>& executor, const u_char id = 1);
    /*!
     * \brief addInstruction добавляет новую инструкцию в задачу
     * \param ptr указатель на инструкцию
     */
    void addInstruction(std::shared_ptr<IBaseInstruction> ptr);
    /*!
     * \brief next исполяет следующаю инструкцию
     */
    void next();
    /*!
     * \brief id возвращает номер задачи
     * \return номер задаяи
     */
    u_char id() const;
    /*!
     * \brief setId устанавливает номер задачи
     * \param id номер задачи
     */
    void setId(const u_char &id);

private:
    u_char m_quantum = 0;
    u_char m_unitEcex = 0;
    u_char m_id;
    TaskConfig config;
    std::deque<std::shared_ptr<IBaseInstruction> > m_instructionsQueue;
    std::shared_ptr<InstructionsExecutor> m_executor;

};

#endif // SIMPLETASK_H
