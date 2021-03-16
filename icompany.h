#ifndef ICOMPANY_H
#define ICOMPANY_H

#include <QVector>
#include <QString>

class ICompany
{
    enum COMPANY_TYPE
    {
        TYPE1,
        TYPE2,
        TYPE3
    };

public:
    ICompany();

    ICompany(QString name, QVector<QString> &owners, double income, double area, int employeesNumber);

    void setName(QString name);

    void setOwners(QVector<QString> &owners);

    void setIncome(double income);

    void setArea(double area);

    void setEmployeesNumber(int employeesNumber);

    QString getName();

    QVector<QString> getOwners();

    double getIncome();

    double getArea();

    int getEmployeesNumber();

    virtual COMPANY_TYPE getCompanyType() = 0;

    virtual double getTax() = 0;

private:

    QString name_;
    QVector<QString> owners_;
    double income_;
    double area_;
    int employeesNumber_;

};

#endif // ICOMPANY_H
