// Score Entry

#ifndef _ScoreEntry
#define _ScoreEntry

class ScoreEntry
{
public:
	ScoreEntry();
	ScoreEntry(ScoreEntry& other) = delete;
	ScoreEntry& operator=(ScoreEntry& other) = delete;
	~ScoreEntry() = default;

	ScoreEntry(int score, std::string initials);

	void SetPrev(ScoreEntry* entry);
	void SetNext(ScoreEntry* entry);

	void SetScore(int score);
	void SetInitials(std::string initials);

	ScoreEntry* GetPrev();
	ScoreEntry* GetNext();

	int GetScore();
	std::string GetInitials();

private:
	ScoreEntry* pPrev;
	ScoreEntry* pNext;
	int score;
	std::string initials;
};

#endif _ScoreEntry