// Score Value

#include "CmdScoreValue.h"
#include "ScoreManager.h"

CmdScoreValue::CmdScoreValue(int val)
	:points(val)
{
}

void CmdScoreValue::Execute()
{
	ScoreManager::AddScore(points);
}