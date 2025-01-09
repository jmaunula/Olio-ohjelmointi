#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game(int, int);

int main()
{
    int guesses = game(1, 20);
    cout <<"Arvauksia meni: " << guesses << endl;

    return 0;
}

int game(int minNum, int maxNum)
{
    srand(time(nullptr));
    int randomNumber = minNum + rand() % (maxNum - minNum +1);
    int userInput = 0;
    int guessCount = 1;

    cout << "Arvaa satunnaisluku valilla " << minNum << "-" << maxNum << endl;
    //cout << randomNumber << endl;

    while(userInput != randomNumber)
    {
        cin >> userInput;
        if(userInput == randomNumber)
        {
            cout << "Oikea numero" << endl;
        }
        if (userInput < randomNumber)
        {
            cout << "Luku on suurempi" << endl;
            guessCount++;
        }
        if (userInput > randomNumber)
        {
            cout << "Luku on pienempi" << endl;
            guessCount++;
        }
    }

    return guessCount;
}
