// Offset Collection

#include "OffsetCollection.h"

const std::vector<sf::Vector3f> OffsetCollection::LeftForwardSlow =
{
	sf::Vector3f(-1.0f, 0.0f, 0.0f),
	sf::Vector3f(-1.0f, 0.0f, 0.0f),
	sf::Vector3f(-1.0f, 0.0f, 0.0f),
	sf::Vector3f(-1.0f, 0.0f, 0.0f),
	sf::Vector3f(-1.0f, 0.0f, 0.0f),
	sf::Vector3f(-1.0f, 0.0f, 0.0f),
	sf::Vector3f(-1.0f, 0.0f, 0.0f),
	sf::Vector3f(-1.0f, 0.0f, 0.0f),
	sf::Vector3f(-1.0f, 0.0f, 0.0f),
	sf::Vector3f(-1.0f, 0.0f, 0.0f),
	sf::Vector3f(-1.0f, 0.0f, 0.0f),
	sf::Vector3f(-1.0f, 0.0f, 0.0f),
	sf::Vector3f(-1.0f, 0.0f, 0.0f),
	sf::Vector3f(-1.0f, 0.0f, 0.0f),
	sf::Vector3f(-1.0f, 0.0f, 0.0f),
	sf::Vector3f(-1.0f, 0.0f, 0.0f)
};

const std::vector<sf::Vector3f> OffsetCollection::LeftForwardMedium = 
{
	sf::Vector3f(-2.0f, 0.0f, 0.0f),
	sf::Vector3f(-2.0f, 0.0f, 0.0f),
	sf::Vector3f(-2.0f, 0.0f, 0.0f),
	sf::Vector3f(-2.0f, 0.0f, 0.0f),
	sf::Vector3f(-2.0f, 0.0f, 0.0f),
	sf::Vector3f(-2.0f, 0.0f, 0.0f),
	sf::Vector3f(-2.0f, 0.0f, 0.0f),
	sf::Vector3f(-2.0f, 0.0f, 0.0f)
};

const std::vector<sf::Vector3f> OffsetCollection::LeftForwardFast =
{
	sf::Vector3f(-4.0f, 0.0f, 0.0f),
	sf::Vector3f(-4.0f, 0.0f, 0.0f),
	sf::Vector3f(-4.0f, 0.0f, 0.0f),
	sf::Vector3f(-4.0f, 0.0f, 0.0f)
};

const std::vector<sf::Vector3f> OffsetCollection::RightForwardSlow =
{
	sf::Vector3f(1.0f, 0.0f, 0.0f),
	sf::Vector3f(1.0f, 0.0f, 0.0f),
	sf::Vector3f(1.0f, 0.0f, 0.0f),
	sf::Vector3f(1.0f, 0.0f, 0.0f),
	sf::Vector3f(1.0f, 0.0f, 0.0f),
	sf::Vector3f(1.0f, 0.0f, 0.0f),
	sf::Vector3f(1.0f, 0.0f, 0.0f),
	sf::Vector3f(1.0f, 0.0f, 0.0f),
	sf::Vector3f(1.0f, 0.0f, 0.0f),
	sf::Vector3f(1.0f, 0.0f, 0.0f),
	sf::Vector3f(1.0f, 0.0f, 0.0f),
	sf::Vector3f(1.0f, 0.0f, 0.0f),
	sf::Vector3f(1.0f, 0.0f, 0.0f),
	sf::Vector3f(1.0f, 0.0f, 0.0f),
	sf::Vector3f(1.0f, 0.0f, 0.0f),
	sf::Vector3f(1.0f, 0.0f, 0.0f)
};

const std::vector<sf::Vector3f> OffsetCollection::RightForwardMedium =
{
	sf::Vector3f(2.0f, 0.0f, 0.0f),
	sf::Vector3f(2.0f, 0.0f, 0.0f),
	sf::Vector3f(2.0f, 0.0f, 0.0f),
	sf::Vector3f(2.0f, 0.0f, 0.0f),
	sf::Vector3f(2.0f, 0.0f, 0.0f),
	sf::Vector3f(2.0f, 0.0f, 0.0f),
	sf::Vector3f(2.0f, 0.0f, 0.0f),
	sf::Vector3f(2.0f, 0.0f, 0.0f)
};

const std::vector<sf::Vector3f> OffsetCollection::RightForwardFast =
{
	sf::Vector3f(4.0f, 0.0f, 0.0f),
	sf::Vector3f(4.0f, 0.0f, 0.0f),
	sf::Vector3f(4.0f, 0.0f, 0.0f),
	sf::Vector3f(4.0f, 0.0f, 0.0f)
};

const std::vector<sf::Vector3f> OffsetCollection::UpToLeftSlow =
{
	sf::Vector3f(0.0f, -1.0f, -180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, -180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, -180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, -180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, -180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, -180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, -180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, -180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, -180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, -180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, -180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, -180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, -180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, -180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, -180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, -180.0f / 16.0f)
};

const std::vector<sf::Vector3f> OffsetCollection::UpToLeftMedium =
{
	sf::Vector3f(0.0f, -2.0f, -180.0f / 8.0f),
	sf::Vector3f(0.0f, -2.0f, -180.0f / 8.0f),
	sf::Vector3f(0.0f, -2.0f, -180.0f / 8.0f),
	sf::Vector3f(0.0f, -2.0f, -180.0f / 8.0f),
	sf::Vector3f(0.0f, -2.0f, -180.0f / 8.0f),
	sf::Vector3f(0.0f, -2.0f, -180.0f / 8.0f),
	sf::Vector3f(0.0f, -2.0f, -180.0f / 8.0f),
	sf::Vector3f(0.0f, -2.0f, -180.0f / 8.0f)
};

const std::vector<sf::Vector3f> OffsetCollection::UpToLeftFast =
{
	sf::Vector3f(0.0f, -4.0f, -180.0f / 4.0f),
	sf::Vector3f(0.0f, -4.0f, -180.0f / 4.0f),
	sf::Vector3f(0.0f, -4.0f, -180.0f / 4.0f),
	sf::Vector3f(0.0f, -4.0f, -180.0f / 4.0f)
};

const std::vector<sf::Vector3f> OffsetCollection::UpToRightSlow =
{
	sf::Vector3f(0.0f, -1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, -1.0f, 180.0f / 16.0f)
};

const std::vector<sf::Vector3f> OffsetCollection::UpToRightMedium =
{
	sf::Vector3f(0.0f, -2.0f, 180.0f / 8.0f),
	sf::Vector3f(0.0f, -2.0f, 180.0f / 8.0f),
	sf::Vector3f(0.0f, -2.0f, 180.0f / 8.0f),
	sf::Vector3f(0.0f, -2.0f, 180.0f / 8.0f),
	sf::Vector3f(0.0f, -2.0f, 180.0f / 8.0f),
	sf::Vector3f(0.0f, -2.0f, 180.0f / 8.0f),
	sf::Vector3f(0.0f, -2.0f, 180.0f / 8.0f),
	sf::Vector3f(0.0f, -2.0f, 180.0f / 8.0f)
};

const std::vector<sf::Vector3f> OffsetCollection::UpToRightFast =
{
	sf::Vector3f(0.0f, -4.0f, 180.0f / 4.0f),
	sf::Vector3f(0.0f, -4.0f, 180.0f / 4.0f),
	sf::Vector3f(0.0f, -4.0f, 180.0f / 4.0f),
	sf::Vector3f(0.0f, -4.0f, 180.0f / 4.0f)
};

const std::vector<sf::Vector3f> OffsetCollection::DownToLeftSlow =
{
	sf::Vector3f(0.0f, 1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, 1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, 1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, 1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, 1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, 1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, 1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, 1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, 1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, 1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, 1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, 1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, 1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, 1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, 1.0f, 180.0f / 16.0f),
	sf::Vector3f(0.0f, 1.0f, 180.0f / 16.0f)
};

const std::vector<sf::Vector3f> OffsetCollection::DownToLeftMedium =
{
	sf::Vector3f(0.0f, 2.0f, 180.0f / 8.0f),
	sf::Vector3f(0.0f, 2.0f, 180.0f / 8.0f),
	sf::Vector3f(0.0f, 2.0f, 180.0f / 8.0f),
	sf::Vector3f(0.0f, 2.0f, 180.0f / 8.0f),
	sf::Vector3f(0.0f, 2.0f, 180.0f / 8.0f),
	sf::Vector3f(0.0f, 2.0f, 180.0f / 8.0f),
	sf::Vector3f(0.0f, 2.0f, 180.0f / 8.0f),
	sf::Vector3f(0.0f, 2.0f, 180.0f / 8.0f)
};

const std::vector<sf::Vector3f> OffsetCollection::DownToRightFast =
{
	sf::Vector3f(0.0f, 4.0f, -180.0f / 4.0f),
	sf::Vector3f(0.0f, 4.0f, -180.0f / 4.0f),
	sf::Vector3f(0.0f, 4.0f, -180.0f / 4.0f),
	sf::Vector3f(0.0f, 4.0f, -180.0f / 4.0f)
};
