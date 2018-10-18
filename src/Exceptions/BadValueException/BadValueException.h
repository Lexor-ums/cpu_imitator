/**************************************************************************
**  File: BadBalueBxception.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 22.05.2018
**************************************************************************/
#ifndef BADBALUEBXCEPTION_H
#define BADBALUEBXCEPTION_H
#include "BaseException.h"

class BadValueException : public IBaseExeption
{
public:
    /*!
     * \brief BadValueException Конструктор класса исключения, возникающего при
     * попытке установить значение переменной выше допустимого
     * \param givenValue установленное значание
     * \param position позиция ошибочной строки в конфиге
     */
    BadValueException(u_char givenValue, u_char position = 0);

    // IBaseExeption interface
public:
    /*!
     * \brief description - реализаций виртульной функции возвращающей описание ошибки
     * \return описание
     */
    std::string description() override;
    /*!
     * \brief givenValue функциф возвращает устанавливаемое значание переменной
     * \return значание переменной
     */
    u_char givenValue() const;
private:
    u_char m_givenValue;
    u_char m_pos;
};

#endif // BADBALUEBXCEPTION_H

