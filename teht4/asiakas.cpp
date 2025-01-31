#include "asiakas.h"
#include <iostream>


Asiakas::Asiakas(string n, double l)
{
    nimi = n;
    kayttotili = new Pankkitili(n);
    cout <<"Pankkitili luotu asiakkaalle " <<n <<endl;
    luottotili = new Luottotili(n, l);
    cout << "Luottotili luotu asiakkaalle " <<n <<", "
         << "luottoraja on " <<l <<endl;
    cout <<"Asiakkuus luotu asiakkaalle " <<n <<endl;
}

string Asiakas::getNimi()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    cout <<nimi <<" kayttotilin saldo: " <<kayttotili->getBalance() <<endl;
    cout <<nimi <<" luottotilin saldo: "<<luottotili->getBalance() <<endl;
}

bool Asiakas::talletus(double sum)
{
    kayttotili->deposit(sum);
    cout <<nimi <<" kayttotili talletus " <<sum <<endl;
    return true;
}

bool Asiakas::nosto(double sum)
{
    kayttotili->withdraw(sum);
    cout <<nimi <<" kayttotili nosto " <<sum <<endl;
    return true;
}

bool Asiakas::luotonMaksu(double sum)
{
    luottotili->deposit(sum);
    cout <<nimi <<" luottotili talletus " <<sum <<endl;
    return true;
}

bool Asiakas::luotonNosto(double sum)
{
    luottotili->withdraw(sum);
    cout <<nimi <<" luottotili nosto " <<sum <<endl;
    return true;
}

bool Asiakas::tiliSiirto(double sum, Asiakas & a)
{
    cout <<"Tilisiirto " <<sum <<" " <<nimi <<"lta " <<a.getNimi() <<"lle" <<endl;
    kayttotili->withdraw(sum);
    a.kayttotili->deposit(sum);
    return true;
}
