/*  Wilder Molyneux
*   University of Washington | Bothell (UWB)
*   Graduate Certificate in Software Design and Development (GCSDD)
*   Prerequisite Sample Coursework
*   June 04, 2023
* 
*   Dr. Emily M. Bender Rule: C++
* 
*   From UWB Computing & Software Systems (CSS) 142:
*   Programming Competency Self-Assessment: Second Assessment (one four)
*   "Hangperson Game"
*   
*   main.cpp
*/

#include "hangperson.h"

// Main program
int main() {
    
    // Words data file
    const string wordsFile = "data7.txt";
    
    // Instantiate a HangPerson object
    HangPerson hangGame(wordsFile);
    
    // Display an introduction on the game to the player 
    hangGame.displayGameIntro();
    
    // Continually play new games if the user desires 
    do {
        hangGame.play();
    }
    while (hangGame.playAgain());
    
    cout << endl << "Thanks for playing!" << endl;
    
    return 0;
}
