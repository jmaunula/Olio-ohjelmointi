#include <chef.h>
#include <iostream>

using namespace std;

int main()
{

    Chef chef1("Pena");
    Chef chef2("Jami");

    int saladIngredients = 10;
    int soupIngredients = 9;
    int saladPortions = chef1.makeSalad(saladIngredients);
    int soupPortions = chef1.makeSoup(soupIngredients);

    cout <<"Chef " <<chef1.getName() <<" with " <<saladIngredients
         <<" ingredients makes " <<saladPortions <<" portions of salad" <<endl;

    cout <<"Chef " <<chef1.getName() <<" with " <<soupIngredients
         <<" ingredients makes " <<soupPortions <<" portions of soup" <<endl;


    return 0;
}
