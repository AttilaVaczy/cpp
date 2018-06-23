#pragma once
#include "FBullCow.h"
#include <map>

// To make syntax Unreal friendly
#define TMap std::map
using int32 = int;

FBullCow::FBullCow() { Reset(); } // Default constructor

int32 FBullCow::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCow::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCow::IsGameWon() const { return bGameIsWon; }

int32 FBullCow::GetMaxTries() const {
	TMap<int32, int32> WordLengthToMaxTries{ {3,4}, { 4,7 }, { 5,10 }, { 6,15 }, { 7,20 } };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCow::Reset()
{
	const FString HIDDEN_WORD = "camel"; // This must be an isogram

	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

EGuessStatus FBullCow::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Word_Length;
	}
	else
	{
		return EGuessStatus::Ok;
	}
}

FBullCowCount FBullCow::SubmitValidGuess(FString Guess)
{	
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();

	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCow::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; }
	
	TMap<char, bool> LetterSeen;
	for (auto Letter : Word)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) {
			return false;
		}
		else {
			LetterSeen[Letter] = true;
		}
	}
	return true;
}

bool FBullCow::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter)) {
			return false;
		}
	}
	return true;
}
