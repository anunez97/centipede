// High Score List

#include "HighScoreList.h"
#include "Grid.h"
#include "Settings.h"
#include "PlayerManager.h"
#include "ScoreEntry.h"

#include "HUD.h"
#include "CentralManager.h"

HighScoreList::HighScoreList()
	:entrylength(10), listlength(8), scorelength(6), row(2), col(10), initiallength(3), initialcount(0), nextPos(sf::Vector2f(0.0f, 0.0f)), 
	entryPos(sf::Vector2f(0.0, 0.0f))
{
	highscoretext = "HIGH SCORES";

	ScoreEntry* tmp;
	ScoreEntry* curr;
	pHead = new ScoreEntry(100, "ABC");
	curr = pHead;

	tmp = new ScoreEntry(60, "DEF");
	curr->SetNext(tmp);
	tmp->SetPrev(curr);
	curr = tmp;

	tmp = new ScoreEntry(50, "GHI");
	curr->SetNext(tmp);
	tmp->SetPrev(curr);
	curr = tmp;

	tmp = new ScoreEntry(40, "JKL");
	curr->SetNext(tmp);
	tmp->SetPrev(curr);
	curr = tmp;

	tmp = new ScoreEntry(30, "MNO");
	curr->SetNext(tmp);
	tmp->SetPrev(curr);
	curr = tmp;

	tmp = new ScoreEntry(20, "PQR");
	curr->SetNext(tmp);
	tmp->SetPrev(curr);
	curr = tmp;

	tmp = new ScoreEntry(10, "STU");
	curr->SetNext(tmp);
	tmp->SetPrev(curr);
	curr = tmp;

	tmp = new ScoreEntry(1, "VWX");
	curr->SetNext(tmp);
	tmp->SetPrev(curr);
	curr = tmp;
}

HighScoreList::~HighScoreList()
{
}

void HighScoreList::Display()
{
	nextPos = sf::Vector2f(Grid::gridtoPixels(col), Grid::gridtoPixels(row));

	for (size_t i = 0; i < highscoretext.length(); i++)
	{
		PlayerManager::GetCurrentGrid()->UpdateCellState(Grid::pixelstoGrid(nextPos.x), 
			Grid::pixelstoGrid(nextPos.y), Grid::CellState::BLOCKED);
		text.push_back(TextFont.GetGlyph(highscoretext.at(i), nextPos));
		nextPos.x += TextFont.CellWidth();
	}

	ScoreEntry* curr = pHead;

	nextPos.x = Grid::gridtoPixels(col);
	while (curr != 0)
	{
		nextPos.y += TextFont.CellHeight();
		WriteScore(curr->GetScore(), curr->GetInitials(), nextPos);
		curr = curr->GetNext();
	}
	
	// Allow input for initials
	if (entryPos.x != 0)
	{
		RegisterInput(InputFlags::TextEntered);
	}
}

void HighScoreList::WriteScore(int score, std::string initials, sf::Vector2f pos)
{
	std::string scorestr = std::to_string(score);
	pos.x += TextFont.CellWidth() * (scorelength - scorestr.length());

	// Write the score
	for(size_t i = 0; i < scorestr.length(); i++)
	{
		PlayerManager::GetCurrentGrid()->UpdateCellState(Grid::pixelstoGrid(pos.x),
			Grid::pixelstoGrid(pos.y), Grid::CellState::BLOCKED);
		hslist.push_back(TextFont.GetGlyph(scorestr.at(i), pos));

		pos.x += TextFont.CellWidth();
	}

	// Space in between the score and initials
	hslist.push_back(TextFont.GetGlyph(' ', pos));
	PlayerManager::GetCurrentGrid()->UpdateCellState(Grid::pixelstoGrid(pos.x),
		Grid::pixelstoGrid(pos.y), Grid::CellState::BLOCKED);
	pos.x += TextFont.CellWidth();

	// Initials
	size_t tmp = 0;
	for (int i = 0; i < initiallength; i++)
	{
		PlayerManager::GetCurrentGrid()->UpdateCellState(Grid::pixelstoGrid(pos.x),
			Grid::pixelstoGrid(pos.y), Grid::CellState::BLOCKED);

		if (tmp < initials.size())
		{
			hslist.push_back(TextFont.GetGlyph(initials.at(i), pos));
			tmp++;
		}
		else 
			hslist.push_back(TextFont.GetGlyph(' ', pos));

		pos.x += TextFont.CellWidth();
	}

	// Checks for a new high score (entry has no initials)
	if (initials == "")
	{
		// set the pos to the first initial
		entryPos = pos;
		entryPos.x -= TextFont.CellWidth() * initiallength;
	}
}

void HighScoreList::RemoveList()
{
	size_t size = hslist.size();
	for (size_t i = 0; i < size; i++)
	{
		hslist.back()->MarkForDestroy();
		hslist.pop_back();
	}

	size = text.size();
	for (size_t i = 0; i < size; i++)
	{
		text.back()->MarkForDestroy();
		text.pop_back();
	}
}

void HighScoreList::UpdateList(int currscore, int nextscore)
{
	nextScore = nextscore;

	ScoreEntry* curr = pHead;
	while (curr != 0)
	{
		if (curr->GetScore() < currscore)
		{
			newEntry = new ScoreEntry;
			newEntry->SetScore(currscore);
			newEntry->SetInitials("");

			// If the largest highscore is passed
			if (curr == pHead)
			{
				pHead = newEntry;
				newEntry->SetNext(curr);
				newEntry->GetNext()->SetPrev(newEntry);
			}
			else
			{
				newEntry->SetPrev(curr->GetPrev());
				newEntry->SetNext(curr);
				newEntry->GetPrev()->SetNext(newEntry);
				newEntry->GetNext()->SetPrev(newEntry);
			}
			// to end the loop
			curr = 0;
		}
		else
			curr = curr->GetNext();
	}

	int count = 0;
	curr = pHead;
	while (curr->GetNext() != 0)
	{
		curr = curr->GetNext();
		count++;
	}

	// keeps the list at 8 entries
	if (count > 7)
	{
		curr->GetPrev()->SetNext(0);
		delete curr;
	}
	// If the list isn't updated 
	else
	{
		if (nextScore == 0)
		{
			HUD::GetCentralManager()->Enable();
		}
	}
	RemoveList();
	Display();
}

void HighScoreList::TextEntered(sf::Uint32 UnicodeValue)
{
	// if backspace is pressed
	if (UnicodeValue == 8)
	{
		// if theres an initial to backspace
		if (initialcount > 0)
		{
			hslist.back()->MarkForDestroy();
			hslist.pop_back();
			entryPos.x -= TextFont.CellWidth();
			initialcount--;
			newInitials.pop_back();
		}
	}
	// If Enter is pressed
	else if (UnicodeValue == 13)
	{
		// Have to put at least one initial
		if (initialcount > 0)
		{
			newEntry->SetInitials(newInitials);
			newInitials = "";
			RemoveList();
			Display();
			initialcount = 0;
			newEntry = 0;
			DeregisterInput();
			entryPos = sf::Vector2f(0, 0);

			if (nextScore == 0)
				HUD::GetCentralManager()->Enable();
			else
				UpdateList(nextScore, 0);
		}
	}
	else
	{
		if (initialcount >= 3)
		{
			hslist.back()->MarkForDestroy();
			hslist.pop_back();
			entryPos.x -= TextFont.CellWidth();
			initialcount--;

			newInitials.pop_back();
		}
		hslist.push_back(TextFont.GetGlyph((char)UnicodeValue, entryPos));
		entryPos.x += TextFont.CellWidth();
		newInitials.push_back((char)UnicodeValue);
		initialcount++;
	}
}

int HighScoreList::GetHighScore()
{
	return pHead->GetScore();
}

void HighScoreList::Draw() 
{
	std::list<Glyph*>::iterator it;
	for (it = hslist.begin(); it != hslist.end(); it++)
		(*it)->Draw();

	for (it = text.begin(); it != text.end(); it++)
		(*it)->Draw();
}

void HighScoreList::Destroy()
{
	ScoreEntry* tmp;
	while (pHead != 0)
	{
		tmp = pHead;
		pHead = pHead->GetNext();
		delete tmp;
	}
}