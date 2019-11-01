#pragma once

#include "../EngineInclude.h"

#include "Componants/PlayerInputs.h"
#include "Componants/PlayerPhysics.h"
#include "Componants/PlayerGraphics.h"

typedef Object<PlayerInputs, PlayerPhysics, PlayerGraphics> Player;