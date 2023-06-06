#ifndef HANGPERSON_H
#define HANGPERSON_H

/*  Wilder Molyneux
*   University of Washington | Bothell (UWB)
*   Graduate Certificate in Software Design and Development (GCSDD)
*   Prerequisite Sample Coursework
*   June 04, 2023
* 
*   Dr. Emily M. Bender Rule: C++
* 
*   From UWB Computing & Software Systems (CSS) 142:
*   Programming Competency Self-Assessment: Second Assessment (two of four)
*   "Hangperson Game"
*   
*   hangperson.h
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <vector>
#include <random>
using namespace std;

// HangPerson class declaration
class HangPerson 
{
  public:
    HangPerson(const string& fileOfWords);        // Constructor
    ~HangPerson();                                // Destructor 
    
    // Public methods
    void displayGameIntro();
    int  play();
    bool playAgain();
    void displayGameState();
    
  private:
    // Private variables
    int numberOfWrongGuesses;
    bool* lettersGuessed;
    vector<string> words;
    string currentWord;
    
    // Static constants
    static const int MAX_TRIES = 7;               // Maximum tries in game
    static const int LETTERS_IN_ALPHABET = 26;    // Number of letters
    
    // Helper methods
    void displayGallows();
    int  getWordsFromFile(const string& fileOfWords);
    string getRandomWord();                       
    void resetGame();                             // Reinitialize game
    char submitAletter();                         // User char input
    bool checkForWin(); 
    bool checkForLoss(); 
};

#endif
