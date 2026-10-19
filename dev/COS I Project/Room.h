#pragma once
#include "Pathway.h"
#include <string>
#include <vector>


class Room
{
	std::string roomName;
	std::vector<Pathway> paths;

public:

	Room(std::string _roomName, std::vector<Pathway> _paths);

	std::string GetRoomName() const;
	const std::vector<Pathway>& GetPaths() const;					// whats returned is read-only(const)

};

