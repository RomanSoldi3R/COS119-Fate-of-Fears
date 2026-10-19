#include "Room.h"

Room::Room(std::string _roomName, std::vector<Pathway> _paths) :
	roomName(_roomName),
	paths(_paths)
{}

std::string Room::GetRoomName() const { return roomName; }
const std::vector<Pathway>& Room::GetPaths() const { return paths; }

