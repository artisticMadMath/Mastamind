#include "Game.h"

#include <iostream>
#include <string>

using namespace std;

// ---------- CONSTRUCTOR ---------- //

Game::Game() {
   currGame.PrintInstructions();
   numGuesses = 0;
}

// ---------- USER GUESS FUNCTIONS ---------- //

void Game::GetUserGuess() {
   string userGuess;
   bool check;

   cout << "Please enter a " << WORD_SIZE << "-lettered guess: " << endl;
   getline(cin, userGuess);

   check = IsGuessValid(userGuess);
   if (!check) {
      GetUserGuess();
   }

   CompareGuess(userGuess);
}

bool Game::IsGuessValid(string guess) {
   if (guess.size() != WORD_SIZE) {
      cout << "Please try again: guesses can only be " <<
      WORD_SIZE << " in length." << endl;
      cout << endl;
      return false;
   }

   for (int i = 0; i < guess.size(); i++) {
      if (!(isalpha(guess.at(i)))) {
         cout << "Please try again: guesses should consist of"
         << " only letters (A-Z)." << endl;
         cout << endl;
         return false;
      }
   }

   return true;
}

void Game::CompareGuess(string guess) {
   if (guess == currGame.GetGameWord()) {
      cout << "You got it!" << endl;
      cout << "Total number of guesses: " << GetNumGuesses() << endl;
   }
   else if (!CheckGuessChar(guess)){
      cout << "Got nothing out of that guess. Try again!" << endl;
      cout << endl;
      GetUserGuess();
   }
   else {
      string result;
      result = result + ResultAsterisks(guess);

      if (!result.size()) {
         result = result + ResultHyphens(guess);
      }
      cout << result << endl;
      cout << endl;
      GetUserGuess();
   }
}

// ---------- HELPERS ---------- //

string Game::ResultAsterisks(string guess) {
   string asterisks;
   string gameWord = currGame.GetGameWord();

   for (int i = 0; i < gameWord.size(); i++) {
      if (guess.at(i) == gameWord.at(i)) {
         asterisks.append("*");
      }
   }

   return asterisks;
}

string Game::ResultHyphens(string guess) {
   string hyphens;
   string gameWord = currGame.GetGameWord();
   size_t found;
   int i = 0;

   while (i < guess.size()) {
      found = gameWord.find(guess.at(i));
      if (found != string::npos) {
         hyphens = hyphens + "-";
      }
      i++;
   }

   return hyphens;
}

bool Game::CheckGuessChar(string guess) {
   string gameWord = currGame.GetGameWord();
   size_t found;


   for (int i = 0; i < guess.size(); i++) {
      found = gameWord.find(guess.at(i));
      if (found != string::npos) {
         return true;
      }
   }
   return false;
}
