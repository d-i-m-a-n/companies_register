#ifndef COMPANIESREGISTER_H
#define COMPANIESREGISTER_H

#include <QVector>

#include <icompany.h>

class CompaniesRegister
{
public:
    static CompaniesRegister& instance();

    void addCompany(ICompany* company);

    void removeCompany(ICompany* company);

    ICompany* getICompany(int i);

    int getSize();

    ~CompaniesRegister();

private:
    CompaniesRegister() = default;
    CompaniesRegister(const CompaniesRegister &companiesRegister) = delete;
    CompaniesRegister& operator = (const CompaniesRegister &companiesRegister) = delete;

    QVector<ICompany*> companies_;
};

#endif // COMPANIESREGISTER_H
