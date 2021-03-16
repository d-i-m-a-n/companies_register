#include "icompany.h"

ICompany::ICompany()
{

}

ICompany::ICompany(QString name, QVector<QString> &owners, double income, double area, int employeesNumber)
{
    if (!name.isEmpty())
        name_ = name;
    else
        throw QString("нет названия компании");

    if (!owners.isEmpty())
        owners_ = owners;
    else
        throw QString("нет владельцев");

    income_ = income;

    if (area >= 0)
        area_ = area;
    else
        throw QString("площадь меньше 0");

    if (employeesNumber >= 0)
        employeesNumber_ = employeesNumber;
    else
        throw QString("кол-во сотрудников меньше 0");
}

void ICompany::setName(QString name)
{
    if (!name.isEmpty())
        name_ = name;
    else
        throw QString("нет названия компании");
}

void ICompany::setOwners(QVector<QString> &owners)
{
    if (!owners.isEmpty())
        owners_ = owners;
    else
        throw QString("нет владельцев");
}

void ICompany::setIncome(double income)
{
    income_ = income;
}

void ICompany::setArea(double area)
{
    if (area >= 0)
        area_ = area;
    else
        throw QString("площадь меньше 0");
}

void ICompany::setEmployeesNumber(int employeesNumber)
{
    if (employeesNumber >= 0)
        employeesNumber_ = employeesNumber;
    else
        throw QString("кол-во сотрудников меньше 0");
}

QString ICompany::getName()
{
    return name_;
}

QVector<QString> ICompany::getOwners()
{
    return owners_;
}

double ICompany::getIncome()
{
    return income_;
}

double ICompany::getArea()
{
    return area_;
}

int ICompany::getEmployeesNumber()
{
    return employeesNumber_;
}
