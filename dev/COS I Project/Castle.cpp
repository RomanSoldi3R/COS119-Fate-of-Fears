#include "Castle.h"


Castle::Castle() :
	currentRoom(ENTRANCE),
	lastRoom(WILDERNESS),
	facing(NORTH)
{
	floorplan.push_back(Room("Entrance Hall", {
		Pathway(WEST, WESTWING),
		Pathway(NORTH, ROOM1),
		Pathway(EAST, EASTWING),
		Pathway(UP, GRANDSTAIRCASE)
	}));

	visited.push_back(currentRoom);

	castleRooms = {
		"Great Hall",
		"Library",
		"Chapel",
		"Alchemist's Lab",
		"Armory",
		"Study",
		"Portrait Gallery",
		"Observatory",
		"Map Room",
		"Music Room",
	};

	std::shuffle(castleRooms.begin(), castleRooms.end(), Helper::Engine());

	floorplan.push_back(Room(castleRooms[ROOM1 - 1], {
		Pathway(WEST, ROOM2),
		Pathway(NORTH, BANQUETHALL),
		Pathway(EAST, ROOM3),
		Pathway(SOUTH, ENTRANCE)
	}));
	floorplan.push_back(Room(castleRooms[ROOM2 - 1], {
		Pathway(NORTH, ROOM4),
		Pathway(EAST, ROOM1),
		Pathway(SOUTH, WESTWING)
	}));
	floorplan.push_back(Room(castleRooms[ROOM3 - 1], {
		Pathway(WEST, ROOM1),
		Pathway(NORTH, ROOM5),
		Pathway(SOUTH, EASTWING)
	}));
	floorplan.push_back(Room(castleRooms[ROOM4 - 1], {
		Pathway(EAST, BANQUETHALL),
		Pathway(SOUTH, ROOM2),
		Pathway(UP, WESTTOWER)
	}));
	floorplan.push_back(Room(castleRooms[ROOM5 - 1], {
		Pathway(WEST, BANQUETHALL),
		Pathway(SOUTH, ROOM3)
	}));
	floorplan.push_back(Room(castleRooms[ROOM6 - 1], {
		Pathway(EAST, GRANDSTAIRCASE)
	}));
	floorplan.push_back(Room(castleRooms[ROOM7 - 1], {
		Pathway(WEST, MASTERBEDROOM),
		Pathway(EAST, ROOM8),
		Pathway(SOUTH, GRANDSTAIRCASE)
	}));
	floorplan.push_back(Room(castleRooms[ROOM8 - 1], {
		Pathway(WEST, ROOM7),
		Pathway(NORTH, ROOM9)
	}));
	floorplan.push_back(Room(castleRooms[ROOM9 - 1], {
		Pathway(WEST, ROOM10),
		Pathway(SOUTH, ROOM8),
		Pathway(UP, EASTTOWER)
	}));
	floorplan.push_back(Room(castleRooms[ROOM10 - 1], {
		Pathway(WEST, DRESSINGROOM),
		Pathway(NORTH, MIRRORHALL),
		Pathway(EAST, ROOM9)
	}));
	floorplan.push_back(Room("Grand Staircase", {
		Pathway(WEST, ROOM6),
		Pathway(NORTH, ROOM7),
		Pathway(DOWN, ENTRANCE)
	}));
	floorplan.push_back(Room("West Wing", {
		Pathway(NORTH, ROOM2),
		Pathway(EAST, ENTRANCE)
	}));
	floorplan.push_back(Room("East Wing", {
		Pathway(WEST, ENTRANCE),
		Pathway(NORTH, ROOM3),
		Pathway(EAST, GUARDROOM)
	}));
	floorplan.push_back(Room("Kitchen", {
		Pathway(SOUTH, BANQUETHALL)
	}));
	floorplan.push_back(Room("Banquet Hall", {
		Pathway(WEST, ROOM4),
		Pathway(NORTH, KITCHEN),
		Pathway(EAST, ROOM5),
		Pathway(SOUTH, ROOM1)
	}));
	floorplan.push_back(Room("West Tower", {
		Pathway(DOWN, ROOM4)
	}));
	floorplan.push_back(Room("Guard Room", {
		Pathway(WEST, EASTWING),
		Pathway(DOWN, DUNGEON)
	}));
	floorplan.push_back(Room("Dungeon", {
		Pathway(DOWN, CATACOMBS),
		Pathway(UP, GUARDROOM)
	}));
	floorplan.push_back(Room("Catacombs", {
		Pathway(UP, DUNGEON)
	}));
	floorplan.push_back(Room("Master Bedroom", {
		Pathway(WEST, NURSERY),
		Pathway(NORTH, DRESSINGROOM),
		Pathway(EAST, ROOM7)
	}));
	floorplan.push_back(Room("Nursery", {
		Pathway(EAST, MASTERBEDROOM)
	}));
	floorplan.push_back(Room("Dressing Room", {
		Pathway(EAST, ROOM10),
		Pathway(SOUTH, MASTERBEDROOM)
	}));
	floorplan.push_back(Room("East Tower", {
		Pathway(DOWN, ROOM9)
	}));
	floorplan.push_back(Room("Hall of Mirrors", {
		Pathway(NORTH, THRONEROOM),
		Pathway(SOUTH, ROOM10)
	}));
	floorplan.push_back(Room("Throne Room", {
		Pathway(SOUTH, MIRRORHALL)
	}));

}

//                        [Throne Room]   <- BOSS (fixed)
//                              |
//                        [Mirror Hall]
//                              |              (up: East Tower)
//		[Dressing Room]----[Music Room]-----------[Map Room]
//				|                                      |
// [Nursery]--[Master Bedroom]--[Portrait Gallery]--[Observatory]
//                                   |
//                   [Study]--[Grand Staircase]
//                                   |
//                        (down: Entrance Hall)


//                        [Kitchen]
//	(up: West Tower)          |
//	[Alchemist's Lab]--[Banquet Hall]--[Armory]
//       |                    |           |
//   [Library]--------[Great Hall]---[Chapel]
//       |                    |           |
//  [West Wing]-----[Entrance Hall]--[East Wing]--[Guard Room]
//                            |                        |
//               (up: Grand Staircase)         (down: Dungeon)
//												       |
// 												   [Dungeon]
//												       |
//												  [Catacombs]


bool Castle::HasVisited(RoomLabel _label) const
{
	for (const auto& room : visited)
	{
		if (_label == room)
		{
			return true;
		}
	}
		return false;
}


void Castle::InView()
{
	std::cout << floorplan[currentRoom].GetRoomName() << std::endl;

	int number = 1;

	for (const auto& door : floorplan[currentRoom].GetPaths())
	{
		if (door.GetLabel() == lastRoom)
		{
			std::cout << "\t" << number++ << ". Go back to the " << floorplan[lastRoom].GetRoomName() << std::endl;
		}
		else if (HasVisited(door.GetLabel()))
		{
			std::cout << "\t" << number++ << ". " << floorplan[door.GetLabel()].GetRoomName() << std::endl;
		}
		else
		{
			if (door.GetDirection() == (facing + 3) % 4)
			{
				std::cout << "\t" << number++ << ". Left" << std::endl;
			}
			else if (door.GetDirection() == facing)
			{
				std::cout << "\t" << number++ << ". Forward" << std::endl;
			}
			else if (door.GetDirection() == (facing + 1) % 4)
			{
				std::cout << "\t" << number++ << ". Right" << std::endl;
			}
			else if (door.GetDirection() == (facing + 2) % 4)
			{
				std::cout << "\t" << number++ << ". Behind" << std::endl;
			}
			else if (door.GetDirection() == UP)
			{
				std::cout << "\t" << number++ << ". Ascend" << std::endl;
			}
			else if (door.GetDirection() == DOWN)
			{
				std::cout << "\t" << number++ << ". Descend" << std::endl;
			}
		}
	}	
}


void Castle::Move(int index)
{
	if (index >= 0 && index < floorplan[currentRoom].GetPaths().size())
	{
		const Pathway& door = floorplan[currentRoom].GetPaths()[index];
		RoomLabel destination = door.GetLabel();

		lastRoom = currentRoom;
		currentRoom = destination;
		
		if (door.GetDirection() == UP)
		{
			facing = NORTH;
		}
		else if (door.GetDirection() == DOWN)
		{
			facing = SOUTH;
		}
		else
		{
			facing = door.GetDirection();
		}

		if (!HasVisited(currentRoom))
		{
			visited.push_back(currentRoom);
		}
	}
}

RoomLabel Castle::GetCurrentRoom() const { return currentRoom; }





