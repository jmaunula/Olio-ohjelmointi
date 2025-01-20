#include "chef.h"
#include <iostream>

using namespace std;

Chef::Chef(string n) : chefName(n)
{
    cout <<"Chef " <<getName() <<" constructor" <<endl;
}

Chef::~Chef()
{
    cout <<"Chef " <<getName() <<" destructor" <<endl;

}

string Chef::getName()
{
    return chefName;
}

int Chef::makeSalad(int numOfIngredients)
{
    int portions = 0;
    int counter = 0;

    for (int i = 0; i < numOfIngredients; ++i)
    {
        counter++;
        if(counter == 5)
        {
            counter = 0;
            portions++;
        }
    }
    return portions;
}

int Chef::makeSoup(int numOfIngredients)
{
    int portions = 0;
    int counter = 0;

    for (int i = 0; i < numOfIngredients; ++i)
    {
        counter++;
        if(counter == 3)
        {
            counter = 0;
            portions++;
        }
    }
    return portions;
}
