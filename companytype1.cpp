#include "companytype1.h"

CompanyType1::CompanyType1()
{

}

CompanyType1::CompanyType1(QString name, QVector<QString> &owners, double income, double area, int employeesNumber)
    :ICompany(name,owners,income,area,employeesNumber)
{

}

double CompanyType1::getTax()
{
    return (income_+area_)/employeesNumber_;
}

CompanyType1::COMPANY_TYPE CompanyType1::getCompanyType()
{
    return COMPANY_TYPE::TYPE1;
}
