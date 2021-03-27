#include "companiesregister.h"

CompaniesRegister& CompaniesRegister::instance()
{
    static CompaniesRegister companiesRegister;
    return companiesRegister;
}

void CompaniesRegister::addCompany(ICompany* company)
{
    if(!companies_.contains(company))
        companies_.push_back(company);
}

void CompaniesRegister::removeCompany(ICompany* company)
{
    companies_.removeOne(company);
}

ICompany* CompaniesRegister::getICompany(int i)
{
    return companies_[i];
}

int CompaniesRegister::getSize()
{
    return companies_.size();
}

CompaniesRegister::~CompaniesRegister()
{
    qDeleteAll(companies_);
    companies_.clear();
}
