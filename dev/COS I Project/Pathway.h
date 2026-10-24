#pragma once
#include "PathwayEnums.h"


class Pathway
{
	Direction direction;
	RoomLabel label;

public:

	Pathway(Direction _direction, RoomLabel _label);

	Direction GetDirection() const;
	RoomLabel GetLabel() const;

};

