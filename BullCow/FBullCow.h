#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCow {


public:
	FBullCow(); //constructor
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWorldLength() const;

	bool IsGameWon() const;
	bool CheckGuessValidity(FString) const;

	void Reset(); //TODO Make a more rich return value
	FBullCowCount SubmitGuess(FString);


private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};