#include "FBullCow.h"

using int32 = int;

FBullCow::FBullCow() { Reset(); }

int32 FBullCow::GetMaxTries() const { return MyMaxTries; }
int32 FBullCow::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCow::GetHiddenWorldLength() const { return MyHiddenWord.length(); }

bool FBullCow::IsGameWon() const { return false; }

void FBullCow::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "camel";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

bool FBullCow::CheckGuessValidity(FString) const
{
	return false;
}

FBullCowCount FBullCow::SubmitGuess(FString Guess)
{	
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
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

	return BullCowCount;
}
