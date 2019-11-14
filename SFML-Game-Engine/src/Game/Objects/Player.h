#pragma once

#include "../EngineInclude.h"

#include "Componants/PlayerInputs.h"
#include "Componants/PlayerPhysics.h"
#include "Componants/PlayerGraphics.h"

class Player : public Object <Player, PlayerInputs, PlayerPhysics, PlayerGraphics> {
	//For constructor
	using Object::Object;
};