// Score Entry

#include "ScoreEntry.h"

ScoreEntry::ScoreEntry()
	:score(0), initials(""), pPrev(0), pNext(0)
{
}

ScoreEntry::ScoreEntry(int score, std::string initials)
	:score(score), initials(initials), pPrev(0), pNext(0)
{
}

void ScoreEntry::SetPrev(ScoreEntry* entry)
{
	pPrev = entry;
}

void ScoreEntry::SetNext(ScoreEntry* entry)
{
	pNext = entry;
}

void ScoreEntry::SetScore(int score)
{
	this->score = score;
}

void ScoreEntry::SetInitials(std::string initials)
{
	this->initials = initials;
}

ScoreEntry* ScoreEntry::GetNext()
{
	return pNext;
}

ScoreEntry* ScoreEntry::GetPrev()
{
	return pPrev;
}

int ScoreEntry::GetScore()
{
	return score;
}

std::string ScoreEntry::GetInitials()
{
	return initials;
}

