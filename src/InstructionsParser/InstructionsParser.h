/**************************************************************************
**  File: InstructionsParser.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 22.05.2018
**************************************************************************/
#ifndef INSTRUCTIONSPARSER_H
#define INSTRUCTIONSPARSER_H
#include <iostream>
#include "TaskConfig.h"

/*!
 * \brief The InstructionsParser class разбирает конфигурацинный файл
 */
class InstructionsParser
{
public:
    InstructionsParser();
    /*!
     * \brief getConfig  разбирает строку настройки программы
     * \param confStr строка с настройками
     * \return структура настроек программы
     */
    TaskConfig getConfig(const std::string& confStr) noexcept(false);
    /*!
     * \brief tryEnd проверяет, является ли строка инструкций по завершени. задачи
     * \param commandLine строковое значение инструкции
     * \return  true в случае успеха
     */
    bool tryEnd(std::string commandLine);
    /*!
     * \brief tryAssignement проверяет, является ли строка инструкций по присвоению
     * значения переменной
     * \param commandLine строковое значение инструкции
     * \return true в случае успеха
     */
    bool tryAssignement(std::string commandLine);
    /*!
     * \brief tryLock проверяет, является ли строка инструкций по блокитровке
     * \param commandLine строковое значение инструкции
     * \return true в случае успеха
     */
    bool tryLock(std::string commandLine);
    /*!
     * \brief tryUnlock проверяет, является ли строка инструкций по разблокировке задачи
     * \param commandLine строковое значение инструкции
     * \return true в случае успеха
     */
    bool tryUnlock(std::string commandLine);
    /*!
     * \brief tryPrint проверяет, является ли строка инструкций по выводу значения переменной
     * \param commandLine строковое значение инструкции
     * \return true в случае успеха
     */
    bool tryPrint(std::string commandLine);
};

#endif // INSTRUCTIONSPARSER_H
