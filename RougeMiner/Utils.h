#pragma once
#include <SFML/System/Vector2.hpp>
#include "Types/OreDefinition.h"
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <random>

class Utils {
public:
	
	static float lerp(float a, float b, float f);
	static int largest(int arr[], int n);
	static sf::Vector2f aspectRatio();
	static void SetSeed(int seed);
	// Get random integer from a range (seed independent)
	static int GetRandomRange(int min, int max);
	// Get random integer from a range (seed dependent)
	static int GetRandomRangeSeed(int min, int max);
	static void RegisterOres(const std::map<std::string, OreDefinition>& oreMap);
	static std::string GetRandomOre();
private:
	static std::vector<std::string> oreNames;
	static std::vector<double> oreWeights;
	static std::mt19937 rng;
};