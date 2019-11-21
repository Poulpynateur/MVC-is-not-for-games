#pragma once

#include <SFML/Graphics.hpp>

#include "../../../Engine/Entities/Components/ComponentGraphics.h"

class Player;
class PlayerGraphics : public ComponentGraphics<Player> {

public:
	
	PlayerGraphics();

	void update(Player* parent) override;
};