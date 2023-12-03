#include "OreDefinition.h"

OreDefinition::OreDefinition() {
	this->weight = 0;
	this->minVein = 0;
	this->maxVein = 0;
}

OreDefinition::OreDefinition(double weight)
{
	this->weight = weight;
	this->minVein = 0;
	this->maxVein = 0;
}
