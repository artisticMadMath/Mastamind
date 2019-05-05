#ifndef GameSetup_h
#define GameSetup_h

#include <iostream>
#include <string>
using namespace std;

class GameSetup {

private:
   string GAME_WORD;
   friend class Game; // MIGHT NEED - DO NOT REMOVE JUST YET

public:
   // CONSTRUCTORS
   GameSetup();

   // ACCESSOR FUNCTIONS
   string GetGameWord() { return GAME_WORD; }

   // MUTATOR FUNCTIONS
   void SetGameWord(string word);

   // WORD SELECTION
   string SelectRandWord();

   // PRINT FUNCTIONS
   void PrintInstructions();

   // HELPER FUNCTIONS
   int GetNumOfLines();
   string RemoveWS(string word);
};

#endif /* GameSetup_h */
