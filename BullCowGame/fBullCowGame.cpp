#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	const FString HIDDEN_WORD = "code";
	
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}




EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) {
		return EGuessStatus::Not_Isogram;
	}
	else if (false) {
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}
}

//receives valid guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();

	// loop through all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) { 
		// compare letters against the guess
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++){
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) { //if they're in the same place
					BullCowCount.Bulls++; // incriment bulls
				} else {
					BullCowCount.Cows++; // must be a cow, incriment cows
				}
			}
		}
	}
	if (BullCowCount.Bulls == HiddenWordLength) {
		bGameIsWon = true;
	} else {
		bGameIsWon = false;
	}
	return BullCowCount;
}
