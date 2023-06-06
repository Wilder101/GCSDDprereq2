# GCSDD prereq 2
This project is an implementation of a University of Washington | Bothell (UWB), School of Science, Technology, Engineering, & Mathematics, Graduate Certificate in Software Design and Development (GCSDD), Prerequisite Sample Coursework number two of four.

## Hangperson Game (CLI)
Written primarily on June 4, 2023 in C++, this is a sample assignment from UWB Computing & Software Systems (CSS) 142: Programming Competency Self-Assessment: Second Assessment -- "Hangperson Game," a Command Line Interface (CLI) word guessing game. See "CSS142-SampleCoursework.pdf" for the program specification.

*Note: implemented in C++ rather than Java as per GCSDD curriculum.*

## References
[UWB STEM Graduate Certificate Prerequisite Sample Coursework](https://www.uwb.edu/stem/graduate/gcsdd/sample-coursework) 
[UWB GCSDD Overview](https://www.uwb.edu/stem/graduate/gcsdd)


## Sample runs
Two sample runs of the program: 
```
Welcome to the hangperson game ...
To play, guess a letter to try to guess the word.
Every time you choose an incorrect letter another
body part appears on the gallows. If you guess the
word before you're hung, you win  :-)
If you get hung, you lose  :-(

Time to guess...

|-----|-
|
|
|
|
|__________

Letters guessed already => 
Number of wrong guesses => 0
The word so far => ----

Choose a letter => o
|-----|-
|
|
|
|
|__________

Letters guessed already => o 
Number of wrong guesses => 0
The word so far => -o--

Choose a letter => x
|-----|-
|     O
|
|
|
|__________

Letters guessed already => o x 
Number of wrong guesses => 1
The word so far => -o--

Choose a letter => 3

Invalid. Don't you know your ABCs? Try again.

Choose a letter => l
|-----|-
|     O
|
|
|
|__________

Letters guessed already => l o x 
Number of wrong guesses => 1
The word so far => -ol-

Choose a letter => o

You already tried this letter.

Choose a letter => a
|-----|-
|     O
|
|
|
|__________

Letters guessed already => a l o x 
Number of wrong guesses => 1
The word so far => -ola

Choose a letter => h
|-----|-
|     O
|
|
|
|__________

Letters guessed already => a h l o x 
Number of wrong guesses => 1
The word so far => hola

Congratulations, you win!!!
Do you want to play again? (y/n): y

|-----|-
|
|
|
|
|__________

Letters guessed already => 
Number of wrong guesses => 0
The word so far => ----

Choose a letter => x
|-----|-
|     O
|
|
|
|__________

Letters guessed already => x 
Number of wrong guesses => 1
The word so far => ----

Choose a letter => z
|-----|-
|     O
|     |
|
|
|__________

Letters guessed already => x z 
Number of wrong guesses => 2
The word so far => ----

Choose a letter => p
|-----|-
|     O
|    \|
|
|
|__________

Letters guessed already => p x z 
Number of wrong guesses => 3
The word so far => ----

Choose a letter => y
|-----|-
|     O
|    \|/
|
|
|__________

Letters guessed already => p x y z 
Number of wrong guesses => 4
The word so far => ----

Choose a letter => m
|-----|-
|     O
|    \|/
|     |
|
|__________

Letters guessed already => m p x y z 
Number of wrong guesses => 5
The word so far => ----

Choose a letter => n
|-----|-
|     O
|    \|/
|     |
|    /
|__________

Letters guessed already => m n p x y z 
Number of wrong guesses => 6
The word so far => ----

Choose a letter => q
|-----|-
|     O
|    \|/
|     |
|    / \ 
|__________

Letters guessed already => m n p q x y z 
Number of wrong guesses => 7
The word so far => ----

Too bad, you lose!
The word was ==> hola
Do you want to play again? (y/n): n

Thanks for playing!
```
