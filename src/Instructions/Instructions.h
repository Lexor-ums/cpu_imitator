/**************************************************************************
**  File: Instructions.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 15.05.2018
**************************************************************************/
#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include "BaseInstruction.h"
#include "SharedMemory.h"

struct AssignementInstruction: public IBaseInstruction
{
public:
    /*!
     * \brief AssignementInstruction конструктор класса инструкции, отвечаещей за установку значения
     * \param param  адрес переменной
     * \param value значение перменнойй
     * \param exec время выполения
     */
    AssignementInstruction(u_char param, u_char value, u_char exec = 1);
    ~AssignementInstruction() override{}
    // IBaseInstruction interface
    void execNext() override;
    u_char execTime() const override;

private:
    u_char m_param;
    u_char m_value;
    u_char m_execTime;
};

struct PrintInstruction: public IBaseInstruction
{
public:
    /*!
     * \brief PrintInstruction конструктор класса инструкции, отвечающей  за выводж значения переменной
     * \param param переменная
     * \param exec время выполения инструкции
     */
    PrintInstruction(u_char param, u_char exec = 1);
    ~PrintInstruction() override{}
    // IBaseInstruction interface
    void execNext() override;
    u_char execTime() const override;

private:
    u_char m_param;
    u_char m_execTime;
};

struct LockInstruction: public IBaseInstruction
{
public:
    LockInstruction(u_char exec = 1);
    ~LockInstruction() override{}
    // IBaseInstruction interface
    void execNext() override;
    u_char execTime() const override;
    void setExecTime(const u_char &execTime);

private:
    u_char m_execTime;
};

struct UnlockInstruction: public IBaseInstruction
{
public:
    UnlockInstruction(u_char exec = 1);
    ~UnlockInstruction() override{}
    // IBaseInstruction interface
    void execNext() override;
    u_char execTime() const override;

private:
    u_char m_execTime;
};

struct EndInstruction: public IBaseInstruction
{
public:
    EndInstruction(u_char exec = 1);
    ~EndInstruction() override{}
    // IBaseInstruction interface
    void execNext() override;
    u_char execTime() const override;

private:
    u_char m_execTime;
};
#endif // INSTRUCTIONS_H
