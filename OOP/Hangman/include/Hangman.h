///Programmer: Guillermo Jimenez
///Date: September 2016

#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <iostream>
using namespace std;

///Assume the word is 7 characters long
///The program ends when there are 7 strikes
class Hangman{
private:
   string sWord;    ///Word to guess.
   string sTries; 	///Which letters have been guessed.
   string sX;       ///Replaces the letters not guessed with 'X'.
   int iGuessed;   	///Total letters guessed
   int iStrikes;    ///Total mistakes.
public:
   Hangman();
   Hangman(string sInput);
   virtual ~Hangman();
   bool wonGame(); 		///Have all the letters been guessed?
   bool continueGame(); ///Have all the letters been found or have there been 7 strikes?
   void validatesLetter(char cLetter); ///Searches for all the occurrences of a letter in the word.
   void draw();
};

#endif //HANGMAN
