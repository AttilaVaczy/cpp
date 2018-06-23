#include "FBullCow.h"

using int32 = int;

FBullCow::FBullCow() { Reset(); }

int32 FBullCow::GetMaxTries() const { return MyMaxTries; }
int32 FBullCow::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCow::GetHiddenWorldLength() const { return MyHiddenWord.length(); }
bool FBullCow::IsGameWon() const { return bGameIsWon; }

void FBullCow::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "camel";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

//testCommitMail

EGuessStatus FBullCow::CheckGuessValidity(FString Guess) const
{
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWorldLength())
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
