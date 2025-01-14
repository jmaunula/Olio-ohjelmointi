#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Game::Game(int maxNum)
{
    maxNumber = maxNum;
    // cout << "Enter a maximum number" << endl;
    // cin >> maxNumber;
    srand(time(nullptr));
    randomNumber = rand() % maxNumber +1;
    numOfGuesses = 1;
    cout << "GAME CONSTRUCTOR: Object initialized with a maximum number " << maxNumber << endl;
    //cout << "Random number: " << randomNumber << endl;
    cout << "Guess a number between " << 1 << " and " << maxNumber << endl;
}

Game::~Game()
{
    cout << "GAME DESTRUCTOR: Object cleared from stack memory" << endl;
}

void Game::play()
{
    while (playerGuess != randomNumber)
    {

        cin >> playerGuess;
        if(playerGuess < randomNumber)
        {
            cout << "The number is higher" << endl;
            numOfGuesses++;
        }
        if(playerGuess > randomNumber)
        {
            cout << "The number is lower" << endl;
            numOfGuesses++;
        }
        if(playerGuess == randomNumber)
        {
            cout << "You guessed the right number!" << endl;
            printGameResult();
        }

    }
}

void Game::printGameResult()
{
    cout << "It took " << numOfGuesses << " guesses. "<< endl;
}
