#include "Hangman.h"

Hangman::Hangman()
{
    //ctor
}

Hangman::Hangman(string sInput)
{
	sWord = sInput;  ///Word to be guessed.
	sTries = "";
	sX = "XXXXXXX";
	iGuessed = 0;
	iStrikes = 0;
}

Hangman::~Hangman()
{
	//dtor
}

void Hangman::draw()
{
	string sGame[] = {"","  O", "  O\n /", "  O\n /|", "  O\n /|\\", "  O\n /|\\ \n  |", "  O\n /|\\ \n  | \n /", "  O\n /|\\ \n  | \n / \\"};
	cout << sGame[iStrikes] << endl;
	cout << "Found: " << sX << endl;
	cout << "Letters tried: " << sTries << endl;
}


///Searches for all the instances of 'cLetter' in 'sWord'.
void Hangman::validatesLetter(char cLetter){
	int iPos;
	bool bFoundLetter = false;
	///Puts the new letter in the Letters Tried
	sTries += cLetter;

	///Searches for the letter inputted in sWord.
	while((iPos = sWord.find(cLetter)) != -1)
	{
		sX[iPos] = cLetter;
		sWord[iPos] = '-';
		bFoundLetter = true;
		iGuessed++;
	}

	if (!bFoundLetter)
	{
		///The letter inputted was not in the word being guessed.
		iStrikes++;
	}
}

///The game ends when the word is guessed or there's 7 strikes
bool Hangman::continueGame()
{
	if( iStrikes < 7 && iGuessed < 7 )
		return true;

	return false;
}

bool Hangman::wonGame()
{
    ///7 can be replaced with this->sWord.length(), since every word has 7 chars.
	if(iGuessed == 7 )
		return true;

	return false;
}
