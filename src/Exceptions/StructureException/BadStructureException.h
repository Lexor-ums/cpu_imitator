/**************************************************************************
**  File: BadStructureException.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 22.05.2018
**************************************************************************/
#ifndef BADSTRUCTUREEXCEPTION_H
#define BADSTRUCTUREEXCEPTION_H
#include "BaseException.h"

class BadStructureException : public IBaseExeption
{
public:
    /*!
     * \brief BadStructureException конструктор класса исключения, возникающего при отсутствии
     * закрывающей задачу инструкции
     */
    BadStructureException();

    // IBaseExeption interface
public:
    /*!
     * \brief description - реализаций виртульной функции возвращающей описание ошибки
     * \return описание
     */
    std::string description() override;
};

#endif // BADSTRUCTUREEXCEPTION_H
