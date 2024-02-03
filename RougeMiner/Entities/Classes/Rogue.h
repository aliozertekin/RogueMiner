#pragma once
#include "ClassBase.h"

class Rouge : public ClassBase {
public:
	Rouge() {
		Name = "Rogue";
		Description = "Low defence but fast attack character.";
		Health = 2;
		Stamina = 5;
	}

};