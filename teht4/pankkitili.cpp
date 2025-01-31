#include "pankkitili.h"
#include <iostream>

Pankkitili::Pankkitili(string o) : omistaja(o)
{

}

double Pankkitili::getBalance()
{
    return saldo;
}

bool Pankkitili::deposit(double sum)
{
    if(sum > 0)
    {
        saldo += sum;
        return true;
    }
    else
        return false;
}

bool Pankkitili::withdraw(double sum)
{
    if(saldo - sum >= 0)
    {
        saldo -= sum;
        return true;
    }
    else
        return false;
}
