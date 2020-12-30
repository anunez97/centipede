// Score by Distance

#include "CmdScoreByDistance.h"
#include "ScoreManager.h"

CmdScoreByDistance::CmdScoreByDistance(int dist, int val)
	:distance(dist), points(val)
{

}

void CmdScoreByDistance::Execute()
{
	ScoreManager::AddScore(points);
}