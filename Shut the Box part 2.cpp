//This is either a 1 person or 2 person game.
//At the start of the game all numbers are open, showing the numerals 1 to 9.
//The object of the game is to shut all of the numbers.The person that shuts
//all the numbers on their turn wins the game.

//During the game, each player plays in turn.A player begins his or her turn
//by throwing or rolling dice.
//After throwing the dice, the player then "shuts" (toggles)either the number
//that equals the total number of dots or the values of the two die.
//For example, if the roll is 3 and 5, the player may either close the number 8,
//or 3 AND 5.  If a number is already shut then it will become reopened.

//If a player rolls doubles :
//1 player : The player can choose to do nothing(shut then open the same number)
//or toggle the box represented by the sum of the die.
//For example, if you roll double 2's, you can choose to toggle the 4 box.

//2 player : The player has the same options as a 1 person game, but they also get
//another turn.
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <ctime>
using namespace std;



int main() {

    string answer = {};
    ifstream myfile;

    cout << "Would you like to read the game instructions?";
    cin >> answer;
    if (answer == "yes") {
        string myText;
        myfile.open("shutTheBoxInstructions.txt", ios::in);
        if (myfile.is_open()) {
            string line;
            while (getline(myfile, line)) {  
                myText += line + "\n";
            }
            myfile.close();
            cout << myText;
        }
    }
    
    string rollAnswer = {};
    system("pause");
    cout << "Would you like to roll two dice? ";
    cin >> rollAnswer; 
    if (rollAnswer == "yes") {
        unsigned dice[2];
        srand(time(0));        
        dice[0] = rand() % 6 + 1;
        dice[1] = rand() % 6 + 1;
        string rollCheck = {};
        cout << "Rolled: " << dice[0] << " and " << dice[1] << endl;
        cout << "Would you like to combine the rolls or split?";
        cin >> rollCheck;
        if (rollCheck == "combine") {
            if (dice[0] + dice[1] < 10) {
            cout << "Your sum is " << dice[0] + dice[1] << endl;
            } 
            if (dice[0] + dice[1] > 10) {
                cout << "Your rolls are split, using " << dice[0] << " and " << dice[1] << endl;
            }

        } else {
                cout << "Your rolls are split, using " << dice[0] << " and " << dice[1] << endl;
        }
    }
    
    return 0;  
}