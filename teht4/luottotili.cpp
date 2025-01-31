#include "luottotili.h"
#include "pankkitili.h"


Luottotili::Luottotili(string o, double l) : Pankkitili(o), luottoraja(l)
{

}

bool Luottotili::deposit(double sum)
{
    if(sum > 0 && (saldo + sum) <= 0)
    {
        saldo += sum;
        return true;
    }
    else
    {
        return false;
    }

}

bool Luottotili::withdraw(double sum)
{
    if((saldo - sum) >= -luottoraja)
    {
        saldo -= sum;
        return true;
    }
    else
    {
        return false;
    }
}
