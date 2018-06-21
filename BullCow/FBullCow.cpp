#include "FBullCow.h"

using int32 = int;

FBullCow::FBullCow() { Reset(); }

int32 FBullCow::GetMaxTries() const { return MyMaxTries; }
int32 FBullCow::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCow::IsGameWon() const { return false; }

void FBullCow::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "Planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

bool FBullCow::CheckGuessValidity(FString)
{
	return false;
}

FBullCowCount FBullCow::SubmitGuess(FString)
{	
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++) {
		for (int32 j = 0; j < HiddenWordLength; j++) {

		}
	}

	return BullCowCount;
}
