#ifndef Game_h
#define Game_h

#include "GameSetup.h"
#include <string>
using namespace std;

class Game {

   GameSetup currGame = GameSetup();

private:
   int WORD_SIZE = 4;
   int numGuesses;

public:
   // CONSTRUCTOR
   Game();

   // ACCESSORS
   int GetNumGuesses() { return numGuesses; }

   // MUTATORS
   void RaiseNumGuesses() { numGuesses++; }

   // USER GUESS FUNCTIONS
   void GetUserGuess();
   bool IsGuessValid(string guess);
   void CompareGuess(string guess);

   // HELPER FUNCTIONS
   string GuessUppercase(string guess);
   string ResultAsterisks(string guess);
   string ResultHyphens(string guess);
   bool CheckGuessChar(string guess);
};

#endif /* Game_h */
