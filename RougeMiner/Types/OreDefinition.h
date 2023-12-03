#pragma once
class OreDefinition {
public:
	OreDefinition();
	OreDefinition(double weight);

	double weight;
	int minVein; // UNUSED
	int maxVein; // UNUSED
};