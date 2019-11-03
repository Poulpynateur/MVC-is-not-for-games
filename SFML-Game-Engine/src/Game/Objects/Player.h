#pragma once

#include "../EngineInclude.h"

#include "Componants/PlayerInputs.h"
#include "Componants/PlayerPhysics.h"
#include "Componants/PlayerGraphics.h"

class Player : public Object <PlayerInputs, PlayerPhysics, PlayerGraphics> {
	using Object::Object;
};