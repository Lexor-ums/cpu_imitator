/**************************************************************************
**  File: BaseExeption.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 15.05.2018
**************************************************************************/
#ifndef BASEEXEPTION_H
#define BASEEXEPTION_H
#include <iostream>
#include <exception>

class IBaseExeption
{
public:
    /*!
     * \brief IBaseExeption интерфейс класса исключений
     */
    IBaseExeption();
    virtual ~IBaseExeption();
    /*!
     * \brief description - реализаций виртульной функции возвращающей описание ошибки
     * \return описание
     */
    virtual std::string description() = 0;
};

#endif // BASEEXEPTION_H
