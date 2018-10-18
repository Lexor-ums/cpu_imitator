/**************************************************************************
**  File: InstructionsCreator.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 18.05.2018
**************************************************************************/
#ifndef INSTRUCTIONSCREATOR_H
#define INSTRUCTIONSCREATOR_H
#include "Instructions.h"
#include <memory>
#include <queue>

/*!
 * \brief The AssignemetnCreator class создаёт инструкции присвоения начения переменной
 */
class AssignemetnCreator
{
public:
    static std::shared_ptr<IBaseInstruction> create(const std::string& instructionStr, u_char execTime = 1) noexcept(false);
};

/*!
 * \brief The PrintCreator class создаёт инструкции вывода значения переменной
 */
class PrintCreator
{
public:
    static std::shared_ptr<IBaseInstruction> create(const std::string& instructionStr, u_char execTime = 1);
};
/*!
 * \brief The EndCreator class создаёт инструкции завершения задачи
 */
class EndCreator
{
public:
    static std::shared_ptr<IBaseInstruction> create(const std::string& instructionStr = "", u_char execTime = 1);
};
/*!
 * \brief The LockCreator class создаёт инструкции блокировки задачи
 */
class LockCreator
{
public:
    static std::shared_ptr<IBaseInstruction> create(const std::string& instructionStr = "", u_char execTime = 1);
};
/*!
 * \brief The UnlockCreator class создаёт инструкции разблокировки задачи
 */
class UnlockCreator
{
public:
    static std::shared_ptr<IBaseInstruction> create(const std::string& instructionStr = "", u_char execTime = 1);
};

class InstructionsCreator
{
public:
    /*!
     * \brief InstructionsCreator конструктор класса, преобразующий строковое описание инструкций в программное
     */
    InstructionsCreator();
    template<class T>
    /*!
     * \brief craeteInstruction преобразует инструкции из строковог оописания в програмное
     * \param instructionStr - строковое значение
     * \param execTime - время выполнения инструкции
     * \return указатель на класс инструкции
     */
    std::shared_ptr<IBaseInstruction> craeteInstruction(const std::string& instructionStr, u_char execTime = 1) noexcept(false)
    {
        return T::create(instructionStr, execTime);
    }
};

#endif // INSTRUCTIONSCREATOR_H
