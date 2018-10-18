/**************************************************************************
**  File: sharedmemory.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 15.05.2018
**************************************************************************/
#ifndef SHAREDMEMORY_H
#define SHAREDMEMORY_H
#include <map>
#include <iostream>

/*!
 * \brief The SharedMemory class синглтон, имитируещей память для хранения переменных
 */

class SharedMemory
{
public:
    /*!
     * \brief instance
     * \return ссылка на экземпляр класса
     */
    static SharedMemory& instance();
    /*!
     * \brief getParam возвращает значение хранимой переменной
     * \param key адрес переменной
     * \return значение
     */
    u_char getParam(u_char key) const;
    /*!
     * \brief setParam узтанавливает значение хранимой переменной
     * \param key адрес переменной
     * \param value значение
     */
    void setParam(u_char key, u_char value);
    /*!
     * \brief initValues инициализирует начальное значение всех переменных
     */
    void initValues();
private:
    SharedMemory();
    ~SharedMemory();
    std::map<u_char, u_char> m_paramsState;
    bool m_initialized = false;

};

#endif // SHAREDMEMORY_H
