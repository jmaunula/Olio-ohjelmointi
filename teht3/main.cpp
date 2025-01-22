#include <chef.h>
#include "italianchef.h"
#include <iostream>


using namespace std;

int main()
{
    int saladItems = 10;
    int saladItems2 = 20;
    int soupItems = 9;

    Chef chef("Pena");

    cout <<"Chef " <<chef.getName() <<" with " <<saladItems
         <<" ingredients makes " <<chef.makeSalad(saladItems) <<" portions of salad" <<endl;

    cout <<"Chef " <<chef.getName() <<" with " <<soupItems
         <<" ingredients makes " <<chef.makeSoup(soupItems) <<" portions of soup" <<endl;

    cout <<"" <<endl;

    ItalianChef italianChef("Alberto");

    cout <<"ItalianChef " <<italianChef.getName() <<" with " <<saladItems2
         <<" ingredients makes " <<italianChef.makeSalad(saladItems2) <<" portions of salad" <<endl;
    italianChef.askSecret("pizza", 10, 10);
    return 0;
}
