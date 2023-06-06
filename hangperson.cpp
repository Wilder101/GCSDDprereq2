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
*   hangperson.cpp
*/

#include "hangperson.h"

// Constructor
HangPerson::HangPerson(const string& fileOfWords)
{    
    // Get words to guess from data store
    getWordsFromFile(fileOfWords);
    
    // Set-up boolean array to track guessed letters
    lettersGuessed = new bool[LETTERS_IN_ALPHABET];
    
    // Initialize game
    resetGame();
}

// Destructor deallocates memory
HangPerson::~HangPerson()
{    
    delete [] lettersGuessed;
}

// Display game into method
void HangPerson::displayGameIntro()
{
    cout << "Welcome to the hangperson game ..." << endl
         << "To play, guess a letter to try to guess the word." << endl
         << "Every time you choose an incorrect letter another" << endl
         << "body part appears on the gallows. If you guess the" << endl
         << "word before you're hung, you win  :-)" << endl
         << "If you get hung, you lose  :-(" << endl << endl
         << "Time to guess..." << endl << endl;
         
         displayGameState();
}

// Play game method
int HangPerson::play()
{
    char currentCharGuess = ' ';
    int charToInt = 0;
    
    // Main game loop
    while (numberOfWrongGuesses <= MAX_TRIES)
    {      
        // Get a valid letter from the user
        currentCharGuess = submitAletter();
        
        // Convert input letter to an integer; a is 0, z is 25
        charToInt = currentCharGuess - 'a';
        
        // Check to see if letter had already been guessed
        if (lettersGuessed[charToInt] == true)
        {
            cout << endl << "You already tried this letter." << endl << endl;
        }
        else 
        {
            // Add letter to letters guessed hash 
            lettersGuessed[charToInt] = true;
            
            // Check if letter is not in the word to guess; npos is "no position" in string
            if (!(currentWord.find(currentCharGuess) != string::npos))
            {
                numberOfWrongGuesses++;
            }
            
            // Show the state of the game
            displayGameState();
            
            // Check for win or loss condition
            if (checkForWin())
            {
                cout << "Congratulations, you win!!!" << endl;
                resetGame();
                return 0;
            }
            else if (checkForLoss())
            {
                cout << "Too bad, you lose!" << endl;
                cout << "The word was ==> " << currentWord << endl;
                resetGame();
                return 0;
            }
        }
    }

    return 1;    // catch-all return
}

// Get user input to play again
bool HangPerson::playAgain()
{
    // Local variable for user input
    string userInput = "";
    
    cout << "Do you want to play again? (y/n): ";
    cin >> userInput;
    
    if (userInput == "y" || userInput == "Y")
    {
        cout << endl;
        displayGameState();
        return true;
    }
    else
    {
        return false;
    }
}

// Display game state
void HangPerson::displayGameState()
{
    // Show the gallows
    displayGallows();
    
    // Letters guessed
    cout << "Letters guessed already => ";
    for (int i = 0; i < LETTERS_IN_ALPHABET; i++)
    {
        if (lettersGuessed[i])
        {
            cout << char(i + 'a') << " ";    // cast an int to a char
        }
    }
    cout << endl;
    
    // Wrong guesses
    cout << "Number of wrong guesses => " << numberOfWrongGuesses << endl;
    
    // Word so far
    cout << "The word so far => ";
    for (int i = 0; i < currentWord.length(); i++)
    {
        char tempChar = currentWord[i];
        if (lettersGuessed[tempChar - 'a'])
        {
            cout << tempChar;
        }
        else
        {
            cout << "-";
        }
    }
    
    cout << endl << endl;
}

// Display the gallows method
void HangPerson::displayGallows()
{
    // Display top row regardess of state
    cout << "|-----|-" << endl;
    
    // Display gallows row 2
    if (numberOfWrongGuesses == 0)
    {
        cout << "|" << endl;
    }
    else 
    {
        cout << "|     O" << endl;
    }
    
    // Display gallows row 3
    if (numberOfWrongGuesses <= 1)
    {
        cout << "|" << endl;
    }
    else if (numberOfWrongGuesses == 2)
    {
        cout << "|     |" << endl;
    }
    else if (numberOfWrongGuesses == 3)
    {
        cout << "|    \\|" << endl; 
    }
    else
    {
        cout << "|    \\|/" << endl;
    }
    
    // Display gallows row 4
    if (numberOfWrongGuesses <= 4)
    {
        cout << "|" << endl;
    }
    else
    {
        cout << "|     |" << endl;
    }
    
    // Display gallows row 5
    if (numberOfWrongGuesses <= 5)
    {
        cout << "|" << endl;
    }
    else if (numberOfWrongGuesses == 6)
    {
        cout << "|    /" << endl;
    }
    else 
    {
        cout << "|    / \\ " << endl;
    }
    
    // Display bottom row regardless of state
    cout << "|__________" << endl << endl;
    
    // Reference Gallows art
    //    |-----|- 
    //    |     O
    //    |    -|/ 
    //    |     | 
    //    |    / - 
    //    |__________
    
}

// Get Words From File method
int HangPerson::getWordsFromFile(const string& fileOfWords)
{
    // Prepare to read the words data file
    ifstream inFile;
    inFile.open(fileOfWords);
    string inputWord = "";
    
    // Check for file opening failure
    if (inFile.fail())
    {
        cout << "Error opening " << fileOfWords << " file." << endl;
        return 1;           // terminate gracefully
    }
    
    // Build vector of words from file
    while(!inFile.eof())
    {
        inFile >> inputWord;
        words.push_back(inputWord);
    }

    // Assign a random current word from the file of words
    currentWord = getRandomWord();
    
    return 0;
}

// Get a random word from the words available
string HangPerson::getRandomWord()
{
    // Seed the random number generator
    random_device rd;
    mt19937 gen(rd());

    // Generate a random index within the vector size
    uniform_int_distribution<size_t> distribution(0, words.size() - 1);
    size_t randomIndex = distribution(gen);

    // Return the random element
    return words[randomIndex];
}

// Reset Game method
void HangPerson::resetGame()
{
    // Initialization
    numberOfWrongGuesses = 0;
    
    // reset letters guessed hash structure
    for (int i = 0; i < LETTERS_IN_ALPHABET; i++)
    {
        lettersGuessed[i] = false;
    }
}

// Submit a letter method, with validation
char HangPerson::submitAletter()
{
    string userGuessString = "";
    char userGuess = ' ';
    bool isValidGuess = false;
    
    // Get user input
    do {
        cout << "Choose a letter => ";
        cin >> userGuessString;
        
        // Check for valid input and process
        if (userGuessString.length() != 1)
        {
            cout << "Please enter a single character of the alphabet." << endl;
            cout << "You entered: " << userGuessString << endl << endl;
            isValidGuess = false;
        }
        else
        {
            userGuess = userGuessString[0];    // use the given character
            userGuess = tolower(userGuess);    // tolower to make game play easier
            
            // Check for valid single character input
            if (isalpha(userGuess)) 
            {
                isValidGuess = true;
            } 
            else 
            {
                cout << endl << "Invalid. Don't you know your ABCs? Try again." << endl << endl;
                isValidGuess = false;
            }
        }
    } while (!isValidGuess);
    
    return userGuess;
}

// Check for win method
bool HangPerson::checkForWin() 
{   
    // Check each character in word to guess
    for (int i = 0; i < currentWord.length(); i++) 
    {
        char currentWordChar = currentWord[i];
        
        // Check to see if letter has not been guessed
        if (!lettersGuessed[currentWordChar - 'a'])      
        {
            return false;
        }
    }
    
    return true;
}

// Check for loss method
bool HangPerson::checkForLoss()
{
    if (numberOfWrongGuesses == MAX_TRIES)
    {
        return true;
    }
    else
    {
        return false;
    }
}
