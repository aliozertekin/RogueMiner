#include "Utils.h"
#include <iomanip>
#include <iostream>
#include <map>
#include <random>

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
