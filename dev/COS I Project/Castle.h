#pragma once
#include "Room.h"
#include <string>
#include <vector>
#include "Helper.h"
#include "Hero.h"
#include "Art.h"


class Castle
{
	RoomLabel currentRoom;
	std::vector<Room> floorplan;
	std::vector<std::string> castleRooms;
	std::vector<RoomLabel> visited;
	RoomLabel lastRoom;
	Direction facing;
	std::vector<Pathway> choices;

public:

	Castle();
	
	bool HasVisited(RoomLabel _label) const;
	void InView(const Hero& _hero);
	void Move(int index);

	RoomLabel GetCurrentRoom() const;

};

