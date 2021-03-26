#ifndef COMPANYTYPE1_H
#define COMPANYTYPE1_H

#include "icompany.h"

class CompanyType1: public ICompany
{
public:
    CompanyType1();

    CompanyType1(QString name, QVector<QString> &owners, double income, double area, int employeesNumber);

    double getTax() override;

    COMPANY_TYPE getCompanyType() override;
};

#endif // COMPANYTYPE1_H
