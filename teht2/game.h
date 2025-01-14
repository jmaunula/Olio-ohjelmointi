#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game(int);
    ~Game();
    void play();

private:
    void printGameResult();
    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;
};

#endif // GAME_H


// Konstruktorissa parametrinä annetaan maksimiarvo,
// mille välille 1-maxNumber peli arpoo arvattavan luvun.

// Play()-jäsenfunktioon toteutetaan peli

// printGameResult()-jäsenfunktiosta kutsutaan
// kun peli on päättynyt. Se tulostaa oikean
// vastauksen ja kuinka monta arvausta siihen tarvittiin.
