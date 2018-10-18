/**************************************************************************
**  File: parseexception.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 16.05.2018
**************************************************************************/
#ifndef PARSEEXCEPTION_H
#define PARSEEXCEPTION_H
#include "BaseException.h"

class ParseException : public IBaseExeption
{
public:
    /*!
     * \brief ParseException конструктор класса исключения, возникающего при ошибке
     * в разборе инструкции
     * \param badStr номер неразобраной строки в конфиге
     */
    ParseException(unsigned char badStr);

    // IBaseExeption interface
public:
    /*!
     * \brief description - реализаций виртульной функции возвращающей описание ошибки
     * \return описание
     */
    std::string description() override;
private:
    unsigned char m_badString = 0;
};

#endif // PARSEEXCEPTION_H
