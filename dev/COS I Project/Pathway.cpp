#include "Pathway.h"

Pathway::Pathway(Direction _direction, RoomLabel _label) :
	direction(_direction),
	label(_label)
{}

Direction Pathway::GetDirection() const { return direction; }
RoomLabel Pathway::GetLabel() const { return label; }

