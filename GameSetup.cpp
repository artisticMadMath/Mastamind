#include "GameSetup.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// ---------- CONSTRUCTOR ---------- //
GameSetup::GameSetup() {
   SetGameWord(SelectRandWord());
   cout << GetGameWord() << endl; // TEST - FIXME
}

// ---------- MUTATORS ---------- //
void GameSetup::SetGameWord(string word) {
   GAME_WORD = word;
}

string GameSetup::SelectRandWord() {
   int randNum;
   int lineNum = 0;
   int fileNumOfLines;
   ifstream wordList;
   string line;
   string selectedWord;

   srand(static_cast<int>(time(0)));
   fileNumOfLines = GetNumOfLines();
   randNum = rand() % fileNumOfLines - 1;

   wordList.open("nameList.rtf");

   if (!wordList.is_open()) {
      cout << "Names list text file cannot open." << endl;
      cout << "Exiting program." << endl;
      exit(0);
   }

   while (getline(wordList, line)) {
      lineNum++;
      if (lineNum == randNum) {
         selectedWord = line;
         break;
      }
   }
   selectedWord = RemoveWS(selectedWord);

   wordList.close();
   return selectedWord;
}

// ---------- PRINTING ---------- //
void GameSetup::PrintInstructions() {

   string instructions;

   instructions =
   " ---- Welcome to MASTAMIND! ---- \n"
   "   Game Objective:\n"
   "     [x] A 4-lettered name will be selected from a list,"
      " and your goal is to guess that name.\n"
   "     [x] You can enter a guess";

   cout << instructions << endl;

/*
   cout << """*** Welcome to MASTAMIND ***""" << endl;
   cout << """ Game Objective: """ << endl;
   cout << """   test""" << endl;
 */
}

// ---------- HELPERS ---------- //
int GameSetup::GetNumOfLines() {
   ifstream wordList;
   string line;
   int numLines = 0;

   wordList.open("nameList.rtf");
   while (getline(wordList, line)) {
      numLines++;
   }
   wordList.close();

   return numLines;
}

string GameSetup::RemoveWS(string word) {
   string wordNoWS;
   char currChar;

   for (int i = 0; i < word.size(); i++) {
      currChar = word.at(i);
      if (currChar != '\\') {
         wordNoWS += currChar;
      }
   }

   return wordNoWS;
}

