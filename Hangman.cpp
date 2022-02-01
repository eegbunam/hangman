#include "Hangman.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


Hangman::Hangman(vector<string> words)
{
    this->words = words;
    this->word = "";
    this->count = 12;
    this->guessWord = "";
    this-> name = "";
}

int Hangman::guessLetter(string guessedLetter , string wordToGuess)

// -1 means your guessedLetter is > 1 character
// -2 means your guessedLetter has already been guessed
// -3 means your guessedLetter is not in the word or something weird happend
{
    int index = -1;
    if(guessedLetter.length() != 1)
    {
        cout << "Please enter a single letter." << endl;
        return -1;
    }
    if(guessWord.find(guessedLetter) != string::npos)
    {
        cout << "You already guessed that letter." << endl;
        return -2;
    }
    if(wordToGuess.find(guessedLetter) != string::npos)
    {
        for(int i = 0; i < wordToGuess.size(); i++)
        {
          if ((wordToGuess[i] == guessedLetter[0]) && (guessWord[i] == '_'))
          {
            index = i;
          }
        }
        return index;
    }
    return -3;

    
}

void Hangman::play(string word)
{
    this->word = word;
    this->initalizeGuessWord(word);
    int tries = word.length()+5;
    if (tries < 12) tries = 12; 

    cout <<endl;
    cout << "We are starting a new Hangman game with a new word " << endl;
    while(tries > 0){
        string letter = "";
        cout << "You have " << tries << " tries left" << endl;
        cout << "Guess a letter: " << endl;
        cin >> letter;
        cout << endl;

        int guessedLetterIndex = this->guessLetter(letter , word);
       
        if (guessedLetterIndex > 0){  
            cout << "You guessed a letter!" << endl;
            
            cout << endl;
        }
        else if(guessedLetterIndex == -3)
        {
            cout << "You guessed a letter that is not in the word!" << endl;
            
            
        }
        displayPartialWord(guessedLetterIndex);
        tries--;
       
        if(guessWord == word){
            cout << "You win!" << endl;
            break;
        }

    }

    cout << "You lose this word! haha" << endl;
    cout << "The word was: " << word << endl;

}

void Hangman::initalizeGuessWord(string word)
{
    this->guessWord = "";
    for (int i = 0; i < word.length(); i++)
    {
        this->guessWord += "_";
    }
}

void Hangman::displayPartialWord(int index )
{
    if (index > -1)
    {
        this->guessWord[index] = this->word[index];
    }
    else
    {
        this->guessWord[index] = this->wrongGuess;
    }
    cout << "The word is now: " << this->guessWord << endl;
}

void Hangman::startGame()
{
    
    cout << "Welcome to Hangman!" << endl;
    cout << "Please enter your name: " << endl;
    cin >> this->name;
    cout << endl;
    cout << "Hello " << this->name << "! Welcome to Hangman created by Ebuka Egbunam" << endl;
    cout << endl;
    cout << "We have " << this->words.size() << " words to guess Today!" << endl;
    cout << endl;
    cout << "Let me explain the game \nEach word will have a minimum of 12 tries, \nif the word is larger then you will have " << this->words.size() << "Tries" << endl;

    for(int i = 0 ; i < words.size() ; i++)
    {
       this->play(words[i]);
    }



}

void Hangman::restartGame(){

    this->startGame();
}
