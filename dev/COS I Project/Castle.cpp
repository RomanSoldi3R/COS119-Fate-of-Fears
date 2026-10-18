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
	floorplan.push_back(Room("Entrance Hall 2FL", {
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


void Castle::InView(const Hero& _hero)
{
	choices.clear();						// clears the list of pathways (doors) in the vector

	std::cout << "\t \033[31m=><=><=><=><=><=><=><=><=><=><=><=><=><=><= \033[1;33m" << floorplan[currentRoom].GetRoomName() << "\033[0m\033[31m =><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m" << std::endl;

	_hero.PrintStats(false);

	int number = 1;

	std::vector<int> order = {				// an menu ordered based on which way the character is facing
			(facing + 3) % 4,
			(facing),
			(facing + 1) % 4,
			(facing + 2) % 4,
			UP,
			DOWN
	};

	for (const auto& entry : order)			// for each entry in that ordered menu...
	{
		for (const auto& door : floorplan[currentRoom].GetPaths())		// and for each door in the current room
		{
			if (door.GetDirection() == entry && door.GetLabel() != lastRoom)		// if the door matches with the menu in order of direction and is not the last room
			{
				std::string direction;
				if (entry == (facing + 3) % 4)
				{
					direction = "Left";
				}
				else if (entry == facing)
				{
					direction = "Forward";
				}
				else if (entry == (facing + 1) % 4)
				{
					direction = "Right";
				}
				else if (entry == (facing + 2) % 4)
				{
					direction = "Behind";
				}
				else if (entry == UP)
				{
					direction = "Ascend";
				}
				else if (entry == DOWN)
				{
					direction = "Descend";
				}
				if (HasVisited(door.GetLabel()))									// if the room has been visited
				{																	// print the direction and doors name
					std::cout << "\r\033[4A\033[53C" << number++ << ". " << direction << ": " << floorplan[door.GetLabel()].GetRoomName() << "\033[4B" << std::endl;
				}
				else																// else just the direction
				{
					std::cout << "\r\033[4A\033[53C" << number++ << ". " << direction << "\033[4B" << std::endl;
				}
				choices.push_back(door);											// then add it to the list "choices"
			}
		}
	}
	if (lastRoom != WILDERNESS)														// if the door behind is not empty(wilderness)
	{	
		for (const auto& door : floorplan[currentRoom].GetPaths())					// for each door in the current room
		{
			if (door.GetLabel() == lastRoom)										// and if the door label matches the last room
			{
				if (door.GetDirection() == UP)										// and if the last room was going up
				{
					std::cout << "\r\033[4A\033[53C" << number++ << ". Go back up to the " << floorplan[lastRoom].GetRoomName() << "\033[4B" << std::endl;
				}
				else if (door.GetDirection() == DOWN)								// else if the last room was going down
				{
					std::cout << "\r\033[4A\033[53C" << number++ << ". Go back down to the " << floorplan[lastRoom].GetRoomName() << "\033[4B" << std::endl;
				}
				else																// else any other direction...
				{
					std::cout << "\r\033[4A\033[53C" << number++ << ". Go back to the " << floorplan[lastRoom].GetRoomName() << "\033[4B" << std::endl;
				}
				choices.push_back(door);											// add it to the list so the last room entered is always on the bottom
			}
		}
	}
}


void Castle::Move(int index)
{
	std::string result;

	if (index >= 0 && index < choices.size())					// if the number entered is greater than or equal to 0 but less than the "choices" list
	{
		const Pathway& door = choices[index];					// player chooses the door out of the menu "choices" and that choice gets stored in "door" 
		RoomLabel destination = door.GetLabel();				// that same door asks GetLabel for the room then stores the answer in "destination"

		if (door.GetLabel() == THRONEROOM)
		{
			Helper::clearScreen();

			std::cout << "\r\033[10B\033[48C\033[31mReady To Face Your Fears?\033[0m" << std::endl;
			std::cout << "\r\033[53CEnter: Proceed" << std::endl;
			std::cout << "\r\033[52CEsc: Return Later" << std::endl;

			if (Helper::EnterEsc())
			{
				facing = SOUTH;
			}
			else
			{
				return;
			}
		}

		lastRoom = currentRoom;									// update the last room to the current room before the player leaves it
		currentRoom = destination;								// update the current room to the room chosen (destination)
		
		if (door.GetDirection() == UP)							// if the player goes upstairs
		{
			facing = NORTH;										// their orientation is set to north
		}
		else if (door.GetDirection() == DOWN)					// if the player goes downstairs
		{
			facing = SOUTH;										// their orientation is set to south
		}
		else													//else face the chosen door's direction
		{
			facing = door.GetDirection();
		}

		if (!HasVisited(currentRoom))							// if the player has not visited the current room
		{
			visited.push_back(currentRoom);						// add that room to the vector
		}

		Helper::clearScreen();
		if (door.GetDirection() == UP)
		{
			if (floorplan[currentRoom].GetRoomName() == "Entrance Hall 2FL")
			{
				result = "\r\033[10B\033[32CYou ascend the Grand Staircase to the \033[1;33m" + floorplan[currentRoom].GetRoomName() + "\033[0m\n";
			}
			if (floorplan[currentRoom].GetRoomName() == "West Tower" || floorplan[currentRoom].GetRoomName() == "East Tower")
			{
				result = "\r\033[10B\033[46CYou ascend the \033[1;33m" + floorplan[currentRoom].GetRoomName() + "\033[0m\n";
			}
			if (floorplan[lastRoom].GetRoomName() == "Dungeon")
			{
				result = "\r\033[10B\033[31CYou feel relieved as you find your way out of the \033[1;33m" + floorplan[lastRoom].GetRoomName() + "\033[0m\n";
			}
			if (floorplan[currentRoom].GetRoomName() == "Dungeon")
			{
				result = "\r\033[10B\033[32CYou remain cautious as you make your way to the \033[1;33m" + floorplan[currentRoom].GetRoomName() + "\033[0m\n";
			}
		}
		else if (door.GetDirection() == DOWN) 
		{
			if (floorplan[currentRoom].GetRoomName() == "Entrance Hall")
			{
				result = "\r\033[10B\033[33CYou descend the Grand Staircase to the \033[1;33m" + floorplan[currentRoom].GetRoomName() + "\033[0m\n";
			}
			if (floorplan[lastRoom].GetRoomName() == "West Tower" || floorplan[lastRoom].GetRoomName() == "East Tower")
			{
				result = "\r\033[10B\033[46CYou descend the \033[1;33m" + floorplan[lastRoom].GetRoomName() + "\033[0m\n";
			}
			if (floorplan[currentRoom].GetRoomName() == "Dungeon")
			{
				result = "\r\033[10B\033[30CYou hear groans and mad screams as you descend into the \033[1;33m" + floorplan[currentRoom].GetRoomName() + "\033[0m\n";
			}
			if (floorplan[currentRoom].GetRoomName() == "Catacombs")
			{
				result = "\r\033[10B\033[33CThe air fills with smells of blood and rotting flesh"
					"\r\033[2K\033[26CYou hear something very unsettling as you descend into the \033[1;33m" + floorplan[currentRoom].GetRoomName() + "\033[0m\n";
			}
		}
		else if (floorplan[currentRoom].GetRoomName() == "Entrance Hall")
		{
			result = "\r\033[10B\033[42CYou make your way to the \033[1;33m" + floorplan[currentRoom].GetRoomName() + "\033[0m\n";
		}
		else if (floorplan[currentRoom].GetRoomName() == "Alchemist's Lab")
		{
			result = "\r\033[10B\033[41CYou make your way to the \033[1;33m" + floorplan[currentRoom].GetRoomName() + "\033[0m\n";
		}
		else if (floorplan[currentRoom].GetRoomName() == "Portrait Gallery")
		{
			result = "\r\033[10B\033[41CYou make your way to the \033[1;33m" + floorplan[currentRoom].GetRoomName() + "\033[0m\n";
		}
		else if (floorplan[currentRoom].GetRoomName() == "Observatory")
		{
			result = "\r\033[10B\033[42CYou make your way to the \033[1;33m" + floorplan[currentRoom].GetRoomName() + "\033[0m\n";
		}
		else if (floorplan[currentRoom].GetRoomName() == "Banquet Hall")
		{
			result = "\r\033[10B\033[42CYou make your way to the \033[1;33m" + floorplan[currentRoom].GetRoomName() + "\033[0m\n";
		}
		else if (floorplan[currentRoom].GetRoomName() == "Master Bedroom")
		{
			result = "\r\033[10B\033[41CYou make your way to the \033[1;33m" + floorplan[currentRoom].GetRoomName() + "\033[0m\n";
		}
		else if (floorplan[currentRoom].GetRoomName() == "Dressing Room")
		{
			result = "\r\033[10B\033[41CYou make your way to the \033[1;33m" + floorplan[currentRoom].GetRoomName() + "\033[0m\n";
		}
		else if (floorplan[currentRoom].GetRoomName() == "Hall of Mirrors")
		{
			result = "\r\033[10B\033[40CYou make your way to the \033[1;33m" + floorplan[currentRoom].GetRoomName() + "\033[0m\n";
		}
		else if (floorplan[currentRoom].GetRoomName() == "Throne Room")
		{
			result = "\r\033[10B\033[48CYour \033[1;33mFate \033[0mAwaits You...\n";
		}
		else
		{
			result = "\r\033[10B\033[43CYou make your way to the \033[1;33m" + floorplan[currentRoom].GetRoomName() + "\033[0m\n";
		}

	}
	Helper::Type(result, 55);
	Helper::Pause();
}

RoomLabel Castle::GetCurrentRoom() const { return currentRoom; }





