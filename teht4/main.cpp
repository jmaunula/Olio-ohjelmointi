#include <iostream>
#include "asiakas.h"

using namespace std;

int main()
{
    Asiakas asiakas1("Pena", 1000);
    asiakas1.talletus(2500);
    asiakas1.luotonNosto(300);
    asiakas1.showSaldo();
    cout <<endl;

    Asiakas asiakas2("Jorma", 2000);
    asiakas2.luotonNosto(100);
    asiakas2.showSaldo();
    asiakas1.tiliSiirto(500, asiakas2);
    cout <<endl;
    asiakas1.showSaldo();
    cout <<endl;
    asiakas2.showSaldo();
    return 0;
}
