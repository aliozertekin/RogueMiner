#pragma once
#include "ClassBase.h"

class Barbarian : public ClassBase {
public:
	Barbarian() {
		Name = "Barbarian";
		Description = "High defence but low attack character.";
		Health = 5;
		Stamina = 2;
	}
	
};