#ifndef COMPANYTYPE3_H
#define COMPANYTYPE3_H

#include "icompany.h"

class CompanyType3: public ICompany
{
public:
    CompanyType3();

    CompanyType3(QString name, QVector<QString> &owners, double income, double area, int employeesNumber);

    double getTax() override;

    COMPANY_TYPE getCompanyType() override;
};

#endif // COMPANYTYPE3_H
