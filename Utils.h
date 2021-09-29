#pragma once

#include <cmath>


namespace std
{
    float round(float x, int places)
    {
        const float powerOf10 = pow(10, places);
        x = (int)(x * powerOf10) / powerOf10;
        return x;
    }
}