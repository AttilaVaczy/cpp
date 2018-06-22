#include <iostream>
#include <string>
#include "FBullCow.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetGuess();
void PlayGame();
bool AskToPlayAgain();

FBullCow BCGame; //Instantiate of a new game

//the entry point for the application
int main()
{
	bool bPlayAgain = false;
	PrintIntro();
	do { 
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);
	return 0;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	for (int32 count = 1; count <= MaxTries; count++) {
		if (count) {
			FText Guess = GetGuess();
			FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
			std::cout << "Bulls = " << BullCowCount.Bulls;
			std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
			std::cout << std::endl;
		}
	}
	// TODO summarise game here
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}

FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();

	// get a guess from the player
	std::cout << "Try " << CurrentTry << ". Enter your guess: " << std::endl;
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;

}

void PrintIntro()
{
	// introduce the game
	std::cout << "Welcome to Cows and Bulls, a fun word game" << std::endl;
	std::cout << "Can you guess the letter " << BCGame.GetHiddenWorldLength();
	std::cout << " isogram i'm thinking of\n";
	std::cout << std::endl;
	return;
}