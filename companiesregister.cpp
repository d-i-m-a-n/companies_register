#include "companiesregister.h"

CompaniesRegister::CompaniesRegister()
{

}

CompaniesRegister& CompaniesRegister::instance()
{
    static CompaniesRegister companiesRegister;
    return companiesRegister;
}

void CompaniesRegister::addCompany(ICompany company)
{
    companies_.push_front(company);
}

void CompaniesRegister::removeCompany(ICompany company)
{
    companies_.removeOne(company);
}

ICompany& CompaniesRegister::getICompany(int i)
{
    return companies_[i];
}

int CompaniesRegister::getSize()
{
    return companies_.size();
}
