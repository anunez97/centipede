// Offset Collection

#ifndef _OffsetCollection
#define _OffsetCollection

#include "TEAL/CommonElements.h"
#include "Settings.h"

class OffsetCollection
{
public:
	OffsetCollection() = default;
	OffsetCollection(OffsetCollection& other) = delete;
	OffsetCollection& operator=(OffsetCollection& other) = delete;
	~OffsetCollection() = default;

	static const std::vector<sf::Vector3f> LeftForwardSlow;
	static const std::vector<sf::Vector3f> RightForwardSlow;
	static const std::vector<sf::Vector3f> UpToLeftSlow;
	static const std::vector<sf::Vector3f> UpToRightSlow;
	static const std::vector<sf::Vector3f> DownToLeftSlow;
	static const std::vector<sf::Vector3f> DownToRightSlow;

	static const std::vector<sf::Vector3f> LeftForwardMedium;
	static const std::vector<sf::Vector3f> RightForwardMedium;
	static const std::vector<sf::Vector3f> UpToLeftMedium;
	static const std::vector<sf::Vector3f> UpToRightMedium;
	static const std::vector<sf::Vector3f> DownToLeftMedium;
	static const std::vector<sf::Vector3f> DownToRightMedium;

	static const std::vector<sf::Vector3f> LeftForwardFast;
	static const std::vector<sf::Vector3f> RightForwardFast;
	static const std::vector<sf::Vector3f> UpToLeftFast;
	static const std::vector<sf::Vector3f> UpToRightFast;
	static const std::vector<sf::Vector3f> DownToLeftFast;
	static const std::vector<sf::Vector3f> DownToRightFast;
};

#endif _OffsetCollection