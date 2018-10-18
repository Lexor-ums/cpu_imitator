/**************************************************************************
**  File: baseinstruction.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 16.05.2018
**************************************************************************/
#ifndef BASEINSTRUCTION_H
#define BASEINSTRUCTION_H
#include <iostream>

class IBaseInstruction
{
public:
    /*!
     * \brief IBaseInstruction базовый интерфейс исполняемый процессором интрукций
     */
    IBaseInstruction()
    {}
    virtual ~IBaseInstruction(){}
    /*!
     * \brief execNext исполяет инструкцию
     */
    virtual void execNext() = 0;
    /*!
     * \brief execTime возвращает время выпонения инструкции
     * \return время в единицах
     */
    virtual u_char execTime() const = 0;
};

#endif // BASEINSTRUCTION_H
