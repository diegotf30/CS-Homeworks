#include <string>
#include <iostream>
#include <fstream>

#include <cstdlib> //rand() & srand()
#include <ctime> //time()

#include "Hangman.h"

using namespace std;

ifstream ifInput;
string sWords[20]; /*All the words are 7 characters long*/

int main()
{
	srand(NULL); //Seed for random sequence.
	int iRandom; //Random number from 1-20
	Hangman *hangman;
	string sCurrWord;
	char cLetter, cCont;

    ifInput.open("words.txt");

    if (!ifInput) ///Fusible
	{
        cout << "ERROR: File not Found" << endl;
        return 404;
	}

	int iNumWords = 0;
    do
	{
        ifInput >> sWords[iNumWords];
        iNumWords++;
	}
	while( !ifInput.eof() );

	do
	{
		iRandom = rand() % iNumWords - 1;

		sCurrWord = sWords[iRandom];  ///Takes the next word of the string array
		hangman = new Hangman(sCurrWord);

		cout << "Guess the word!" << endl;
		hangman->draw();

		while (hangman->continueGame())
		{
			cout << "Enter the letter: ";
			cin >> cLetter;
			hangman->validatesLetter(cLetter);
			hangman->draw();
		}

		if(hangman->wonGame())
		{
			cout << "Congrats!!! You guessed the word!!!"<< endl;
		}
		else
		{
			cout << "Sorry. The word was: " << sCurrWord << endl;
		}

		delete hangman; ///Destroys the instance of hangman.

		cout << "\nWanna play again? y/n"<< endl;
		cin >> cCont;

   } while(cCont == 'y' || cCont == 'Y');

   return 0;
}
/* EJERCICIO:
       Modifica el programa para que tome la lista de palabras de diferentes longitudes desde el archivo "palabras.txt".
       No sabemos cuantas palabras contiene el archivo.
       La longitud máxima de una palabra sería 15.
       Una secuencia distinta de numeros aleatorios puede establecerse con: srand (time(NULL)).
       En cada ocasión, la palabra debe seleccionarse al azar (rand() % listSize).
       La cantidad de intentos fallidos debe mantenerse siempre en 7.
       No debe repetirse una misma palabra a un jugador en la sesión.
*/
