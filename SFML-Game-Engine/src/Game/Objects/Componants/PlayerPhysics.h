#pragma once

#include "../../EngineInclude.h"

class Player;
class PlayerPhysics : public ComponentPhysics<Player> {

public:

	PlayerPhysics();

	void update(Player* parent, IWorld* world) override;
};