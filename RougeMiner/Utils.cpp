#include "Utils.h"

float Utils::lerp(float a, float b, float f)
{
    return a + f * (b - a);
}
