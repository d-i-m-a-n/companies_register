#include <QCoreApplication>
#include <QString>
#include <QVector>
#include <iostream>

#include "companiesregister.h"
#include "companytype1.h"
#include "companytype2.h"
#include "companytype3.h"



void printCompaniesInfoByType(ICompany::COMPANY_TYPE companyType)
{
    CompaniesRegister& companiesRegister = CompaniesRegister::instance();
    ICompany* company_ptr = nullptr;
    int size = companiesRegister.getSize();

    std::cout << "Info about TYPE" << companyType+1 << " companies:\n";
    for(int i = 0; i < size; i++)
    {
        company_ptr = companiesRegister.getICompany(i);
        if(company_ptr->getCompanyType() == companyType)
        {
            std::cout << "Name: " << company_ptr->getName().toStdString() << std::endl;
            std::cout << "Owners: ";
            QVector<QString> owners = company_ptr->getOwners();
            while(!owners.isEmpty())
            {
                std::cout << owners.front().toStdString() << ", ";
                owners.pop_front();
            }
            std::cout << std::endl;
            std::cout << "Income: " << company_ptr->getIncome() << std::endl;
            std::cout << "Tax: " << company_ptr->getTax() << std::endl;
            std::cout << "Area: " << company_ptr->getArea() << std::endl;
            std::cout << "Employees: " << company_ptr->getEmployeesNumber() << std::endl;
            std::cout << "------------------------------------------------------------\n";
        }
    }

}

void printCompaniesInfoByOwner(QString owner)
{
    CompaniesRegister& companiesRegister = CompaniesRegister::instance();
    ICompany* company_ptr = nullptr;
    int size = companiesRegister.getSize();

    std::cout << owner.toStdString() << " owns: ";
    for(int i = 0; i < size; i++)
    {
        company_ptr = companiesRegister.getICompany(i);
        if(company_ptr->getOwners().contains(owner))
        {
            std::cout << company_ptr->getName().toStdString() << ", ";
        }
    }
    std::cout << std::endl;
}

void printAverageValuesForAllTypes()
{
    CompaniesRegister& companiesRegister = CompaniesRegister::instance();
    ICompany* company_ptr = nullptr;
    int size = companiesRegister.getSize();
    int countCompanies[3] = {0, 0, 0};
    int countIncome[3] = {0, 0, 0};
    int countArea[3] = {0, 0, 0};
    int countTax[3] = {0, 0, 0};
    int countEmployees[3] = {0, 0, 0};

    for(int i = 0; i < size; i++)
    {
        company_ptr = companiesRegister.getICompany(i);

        countCompanies[company_ptr->getCompanyType()]++;
        countArea[company_ptr->getCompanyType()] += company_ptr->getArea();
        countIncome[company_ptr->getCompanyType()] += company_ptr->getIncome();
        countTax[company_ptr->getCompanyType()] += company_ptr->getTax();
        countEmployees[company_ptr->getCompanyType()] += company_ptr->getEmployeesNumber();
    }

    std::cout << "AVG values for TYPE1 companies:\n";
    std::cout << "income: " << countIncome[ICompany::TYPE1]/countCompanies[ICompany::TYPE1] << std::endl;
    std::cout << "tax: " << countTax[ICompany::TYPE1]/countCompanies[ICompany::TYPE1] << std::endl;
    std::cout << "area: " << countArea[ICompany::TYPE1]/countCompanies[ICompany::TYPE1] << std::endl;
    std::cout << "employees: " << countEmployees[ICompany::TYPE1]/countCompanies[ICompany::TYPE1] << std::endl;
    std::cout << "------------------------------------------------------------\n";

    std::cout << "AVG values for TYPE2 companies:\n";
    std::cout << "income: " << countIncome[ICompany::TYPE2]/countCompanies[ICompany::TYPE2] << std::endl;
    std::cout << "tax: " << countTax[ICompany::TYPE2]/countCompanies[ICompany::TYPE2] << std::endl;
    std::cout << "area: " << countArea[ICompany::TYPE2]/countCompanies[ICompany::TYPE2] << std::endl;
    std::cout << "employees: " << countEmployees[ICompany::TYPE2]/countCompanies[ICompany::TYPE2] << std::endl;
    std::cout << "------------------------------------------------------------\n";

    std::cout << "AVG values for TYPE3 companies:\n";
    std::cout << "income: " << countIncome[ICompany::TYPE3]/countCompanies[ICompany::TYPE3] << std::endl;
    std::cout << "tax: " << countTax[ICompany::TYPE3]/countCompanies[ICompany::TYPE3] << std::endl;
    std::cout << "area: " << countArea[ICompany::TYPE3]/countCompanies[ICompany::TYPE3] << std::endl;
    std::cout << "employees: " << countEmployees[ICompany::TYPE3]/countCompanies[ICompany::TYPE3] << std::endl;
    std::cout << "------------------------------------------------------------\n";

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    try {
        CompaniesRegister& companiesRegister = CompaniesRegister::instance();

        QVector<QString> c1_owners;
        QVector<QString> c2_owners;
        QVector<QString> c3_owners;
        QVector<QString> c4_owners;
        QVector<QString> c5_owners;

        c1_owners.push_back(QString("c1_owner1"));
        c1_owners.push_back(QString("multi_owner"));

        c2_owners.push_back(QString("c2_owner1"));
        c2_owners.push_back(QString("c2_owner2"));

        c3_owners.push_back(QString("c3_owner1"));
        c3_owners.push_back(QString("c3_owner2"));
        c3_owners.push_back(QString("c3_owner3"));
        c3_owners.push_back(QString("multi_owner"));

        c4_owners.push_back(QString("c4_owner1"));
        c4_owners.push_back(QString("c4_owner2"));

        c5_owners.push_back(QString("c5_owner1"));
        c5_owners.push_back(QString("multi_owner"));

        companiesRegister.addCompany(new CompanyType1(QString("c1_t1"),c1_owners,12.34,56.78,90));
        companiesRegister.addCompany(new CompanyType2(QString("c2_t2"),c2_owners,333.231,100,30));
        companiesRegister.addCompany(new CompanyType1(QString("c3_t1"),c3_owners,2930,92.3,5));
        companiesRegister.addCompany(new CompanyType3(QString("c4_t3"),c4_owners,999.99,30,20));
        companiesRegister.addCompany(new CompanyType2(QString("c5_t2"),c5_owners,110.01,125.8,11));



        printCompaniesInfoByType(ICompany::TYPE1);
        std::cout << std::endl;
        printCompaniesInfoByType(ICompany::TYPE2);
        std::cout << std::endl;
        printCompaniesInfoByType(ICompany::TYPE3);
        std::cout << std::endl;
        printCompaniesInfoByOwner("multi_owner");
        std::cout << std::endl;
        printAverageValuesForAllTypes();


    } catch (QString error) {
        std::cout << error.toStdString() << std::endl;
    }



    return a.exec();
}
