/**************************************************************************
**  File: TaskCreator.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 15.05.2018
**************************************************************************/
#ifndef TASKCREATOR_H
#define TASKCREATOR_H
#include "ConfigReader.h"
#include "Instructions.h"
#include "InstructionsCreator.h"
#include "InstructionsExecutor.h"
#include "InstructionsParser.h"
#include "SimpleTask.h"
#include <memory>
#include <iostream>

class TaskCreator
{
public:
    /*!
     * \brief TaskCreator конструктор класса, генерирующего задачи
     * \param fileName сылка на имя конфиг-файла
     */
    TaskCreator(const std::string& fileName) noexcept(false);
    /*!
     * \brief canCreate проверяет возможность добавления новой задачи
     * \return true если возможно
     */
    bool canCreate() const;
    /*!
     * \brief createTask добавляет новую задачу
     * \param executor ссылка на коасс, следящий за выполнением инструкций
     * \param id номер задачи
     * \return указатель на класс задчи
     */
    std::shared_ptr<SimpleTask> createTask(std::shared_ptr<InstructionsExecutor> &executor, const u_char id = 1) noexcept(false);
private:

    u_char m_currentStep = 1;
    bool m_fileEnded = false;
    std::vector<std::string> m_insrtuctionVector;
    TaskConfig m_config;
    InstructionsCreator iCreator;
    InstructionsParser iParser;
};

#endif // TASKCREATOR_H
