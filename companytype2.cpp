#include "companytype2.h"

CompanyType2::CompanyType2()
{

}

CompanyType2::CompanyType2(QString name, QVector<QString> &owners, double income, double area, int employeesNumber)
    :ICompany(name,owners,income,area,employeesNumber)
{

}

double CompanyType2::getTax()
{
    return (income_+employeesNumber_)/area_;
}

CompanyType2::COMPANY_TYPE CompanyType2::getCompanyType()
{
    return COMPANY_TYPE::TYPE2;
}
