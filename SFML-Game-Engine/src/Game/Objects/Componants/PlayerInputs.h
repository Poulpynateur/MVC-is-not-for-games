#pragma once

#include "../../EngineInclude.h"

class Player;
class PlayerInputs {
public:
	void update(Player* parent, World* world);
};