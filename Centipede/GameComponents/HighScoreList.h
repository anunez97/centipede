// High Score List

#ifndef _HighScoreList
#define _HighScoreList

#include <list>
#include "Font.h"
#include "TEAL/CommonElements.h"

class ScoreEntry;

class HighScoreList : public GameObject
{
public:
	HighScoreList();
	HighScoreList(HighScoreList& other) = delete;
	HighScoreList& operator=(HighScoreList& other) = delete;
	~HighScoreList();

	virtual void Draw();
	virtual void Destroy();
	virtual void TextEntered(sf::Uint32 UnicodeValue);

	void Display();
	void WriteScore(int score, std::string initials, sf::Vector2f pos);
	void RemoveList();
	void UpdateList(int p1score, int p2score);

	int GetHighScore();

private:
	std::list<Glyph*> hslist;
	std::list<Glyph*> text;
	std::list<Glyph*> CurrentHighScore;
	std::string highscoretext;

	ScoreEntry* pHead;
	ScoreEntry* newEntry;
	std::string newInitials;
	Font TextFont;
	sf::Vector2f nextPos;
	sf::Vector2f entryPos;
	int entrylength;
	int listlength;
	int initiallength;
	int initialcount;
	int scorelength;
	int row;
	int col;
	int nextScore;
};

#endif _HighScoreList