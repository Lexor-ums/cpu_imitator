/**************************************************************************
**  File: OpenFileException.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 15.05.2018
**************************************************************************/
#ifndef OPENFILEEXCEPTION_H
#define OPENFILEEXCEPTION_H
#include "BaseException.h"

class OpenFileException : public IBaseExeption
{
public:
    /*!
     * \brief OpenFileException конструктор класса искллючения возникающего при
     * открытии конфига
     * \param fileName ссылка на имя файла
     */
    OpenFileException(const std::string& fileName);


    // IBaseExeption interface
public:
    /*!
     * \brief description - реализаций виртульной функции возвращающей описание ошибки
     * \return описание
     */
    std::string description() override;
private:
    const std::string m_fileName;
};

#endif // OPENFILEEXCEPTION_H
