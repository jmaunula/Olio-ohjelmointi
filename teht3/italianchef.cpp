#include "italianchef.h"
#include <iostream>

using namespace std;

ItalianChef::ItalianChef(string n) : Chef(n)
{
    cout <<"ItalianChef " <<getName() <<" constructor" <<endl;
}

ItalianChef::~ItalianChef()
{
    cout <<"ItalianChef " <<getName() <<" destructor" <<endl;
}

void ItalianChef::askSecret(string p, int f, int w )
{
    flour = f;
    water = w;

    if(p.compare(password) == 0)
    {
        cout <<"Password ok!" <<endl;
        cout <<"ItalianChef " <<getName() <<" with " <<f <<" flour and " <<w
             <<" water makes " <<makepizza(f, w) <<" pizza(s)" <<endl;
    }
    else
        cout <<"Wrong password!" <<endl;
}

int ItalianChef::makepizza(int f, int w)
{
    int portions = 0;
    int fcounter = 0;
    int wcounter = 0;

    for (int i = 0; i < f; ++i)
    {
        fcounter++;
        for (int i = 0; i < w; ++i)
        {
            wcounter++;
            break;
        }

        if(wcounter == 5 && fcounter == 5)
        {
            wcounter = 0;
            fcounter = 0;
            portions++;
        }

    }
    return portions;
}
