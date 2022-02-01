#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Hangman{

    private:
        vector<string> words;
        string word;
        string guess;
        string guessWord;
        char wrongGuess = {'X'};
        int count;
        string name;
        


        int guessLetter(string word , string wordToGuess);
        void play(string word);
        void display();
        void display(string word);
        void displayPartialWord(int index );
        void end();
        void gameStatus();
        void getName(string name);
        void initalizeGuessWord(string word);
        void restartGame();

    public:
        Hangman(vector<string> words);
        void startGame();





};