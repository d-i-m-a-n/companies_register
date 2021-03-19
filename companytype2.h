#ifndef COMPANYTYPE2_H
#define COMPANYTYPE2_H

#include "icompany.h"

class CompanyType2: public ICompany
{
public:
    CompanyType2();

    CompanyType2(QString name, QVector<QString> &owners, double income, double area, int employeesNumber);

    double getTax() override;

    COMPANY_TYPE getCompanyType() override;
};

#endif // COMPANYTYPE2_H
