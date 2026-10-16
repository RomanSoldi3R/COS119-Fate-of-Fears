#pragma once
#include "Room.h"
#include <string>
#include <vector>
#include "Helper.h"
#include "Hero.h"


class Castle
{
	RoomLabel currentRoom;
	std::vector<Room> floorplan;
	std::vector<std::string> castleRooms;
	std::vector<RoomLabel> visited;
	RoomLabel lastRoom;
	Direction facing;

public:

	Castle();
	
	bool HasVisited(RoomLabel _label) const;
	void InView();
	void Move(int index);

	RoomLabel GetCurrentRoom() const;

};

