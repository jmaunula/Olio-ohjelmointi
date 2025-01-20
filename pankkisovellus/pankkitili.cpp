#include "pankkitili.h"
#include <iostream>
#include <string>

using namespace std;

Pankkitili::Pankkitili(string n, string t, double s):tilinomistaja(n), tilinumero(t), saldo(s)
{
}

void Pankkitili::talleta(double s)
{
    saldo += s;
}

void Pankkitili::nosta(double s)
{
    saldo -= s;
}

void Pankkitili::tulostaTilitiedot()
{
    cout << "Tilinomistaja = " <<tilinomistaja <<endl;
    cout << "Tilinumero = " <<tilinumero <<endl;
    cout << "Saldo = " <<saldo <<endl;
}

string Pankkitili::getTilinumero()
{
    return tilinumero;
}

double Pankkitili::getSaldo()
{
    return saldo;
}

bool Pankkitili::siirra(Pankkitili &tili, double s)
{
    if(saldo - s < 0)
    {
        return false;
    }
    else
    {
        return true;
        tili.talleta(s);
    }


}
