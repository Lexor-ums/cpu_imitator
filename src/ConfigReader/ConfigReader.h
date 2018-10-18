/**************************************************************************
**  File: ConfigReader.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 15.05.2018
**************************************************************************/
#ifndef CONFIGREADER_H
#define CONFIGREADER_H
#include "OpenFileException.h"
#include "ParseException.h"
#include <vector>

class ConfigReader
{
public:
    /*!
     * \brief ConfigReader конструктор класса отвечающего за считывание конфигурациооного файла
     * \param fileName - сслылка на имя файла
     * \param v - ссылка на вектор считаных строковых инструкций
     */
    ConfigReader(const std::string &fileName, std::vector<std::string>& v) noexcept(false);

private:
    /*!
     * \brief readFile - Функция чтения конфигурационного файла.
     * \param fileName - сслылка на имя файла
     * \param v - ссылка на вектор считаных строковых инструкций
     */
    void readFile(const std::string& fileName, std::vector<std::string> &v) noexcept(false);
};

#endif // CONFIGREADER_H
