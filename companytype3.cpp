#include "companytype3.h"

CompanyType3::CompanyType3()
{

}

CompanyType3::CompanyType3(QString name, QVector<QString> &owners, double income, double area, int employeesNumber)
    :ICompany(name,owners,income,area,employeesNumber)
{

}

double CompanyType3::getTax()
{
    return (employeesNumber_+area_)/income_;
}

CompanyType3::COMPANY_TYPE CompanyType3::getCompanyType()
{
    return COMPANY_TYPE::TYPE3;
}
