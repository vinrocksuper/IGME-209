#pragma once

/// <summary>
/// Draws ASCII art of gallows depending on # of incorrect guesses
/// </summary>
/// <param name="guessLimit"> Max number of guesses </param>
void ShowGallows(int guessLimit);

///
/// Stores properly guessed letters in an arr
/// shows which have been correctly guessed.
/// 
void ShowSolved(char word[], char guesses[]);

