#include "Hangman.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    string answer;
    string yes = "y";
    string  no = "n";
    vector<string> words = {"cat" , "boy"};
    Hangman game = Hangman(words);
    game.startGame();

    while (true){
        cout<< "Are you ready to start a game of Hangmane" << endl;
        cout <<"Reply with y or n: ";
        cin >> answer;

        if (answer == yes){
            game.startGame();
        }
        else if (answer == no){
            cout << "Goodbye" << endl;
            break;
        }
        else{
            cout << "Please enter a valid answer" << endl;
        }

    }


}