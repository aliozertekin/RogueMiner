#include "Utils.h"

std::vector<std::string> Utils::oreNames;
std::vector<double> Utils::oreWeights;
std::mt19937 Utils::rng;

float Utils::lerp(float a, float b, float f)
{
    return a + f * (b - a);
}

int Utils::largest(int arr[], int n)
{
    int i;

    // Initialize maximum element
    int max = arr[0];

    // Traverse array elements
    // from second and compare
    // every element with current max
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            return i;
}

void Utils::SetSeed(int seed) {
    rng.seed(seed);
}

int Utils::GetRandomRange(int min, int max) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(min, max);

    return dist(mt);
}

int Utils::GetRandomRangeSeed(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);

    return dist(rng);
}

void Utils::RegisterOres(const std::map<std::string, OreDefinition>& oreMap) {
    oreNames.clear();
    oreWeights.clear();

    double totalWeight = 0.0;
    for (const auto& pair : oreMap) {
        oreNames.push_back(pair.first);
        oreWeights.push_back(pair.second.weight);
        totalWeight += pair.second.weight;
    }

    if (totalWeight != 0.0) {
        for (auto& weight : oreWeights) {
            weight /= totalWeight;
        }
    }
}

std::string Utils::GetRandomOre() {
    std::discrete_distribution<> distribution(oreWeights.begin(), oreWeights.end());
    int index = distribution(rng);
    return oreNames[index];
}