#pragma once

#include "../../EngineInclude.h"

class Player;
class PlayerInputs : public ComponentInputs<Player> {
public:
	void update(Player* parent, IWorld* world) override;
};