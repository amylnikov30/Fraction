#pragma once

#include <iostream>
#include <ostream>
#include <string>
#include <cmath>

#define PI 3.14159265358979323846

class Fraction
{
public:
    float numerator;
    float denominator;

    #pragma region Constructors
    
    Fraction();
    Fraction(float numerator, float denominator, bool inTermsOfPi=false);
    Fraction(const char* s);
    Fraction(const float f);
    Fraction(const Fraction& other) = default;

    #pragma endregion
    
    #pragma region Operators
    
    Fraction operator -() { this->numerator *= -1; return *this; }
    
    Fraction& operator +=(Fraction other) { *this = *Add(other); return *this; }
    Fraction& operator *=(Fraction other) { *this = *Multiply(other); return *this; }
    Fraction& operator /=(Fraction other) { *this= *Divide(other); return *this; }
    
    inline Fraction& operator =(const char* input)
    {
        *this = *FromString(std::string(input));
        return *this;
    }
    
    inline Fraction& operator =(const float* input)
    {
        *this = Fraction(*input, 1);
        return *this;
    }
    
    inline explicit operator float () { return numerator / denominator; }
    
    inline operator std::string() { return ToString(); }
    inline operator const char*() { return ToString().c_str(); }
    inline friend std::ostream& operator <<(std::ostream& ostream, Fraction& fraction)
    {
        ostream << fraction.ToString().c_str();
        return ostream;
    }
    
    inline friend std::ostream& operator <<(std::ostream& ostream, Fraction* fraction)
    {
        ostream << *fraction;
        return ostream;
    }

    #pragma endregion
    
    static Fraction* FromString(std::string input);
    static std::string InTermsOfPI(float radians);

    Fraction* Add(Fraction other);
    Fraction* Subtract(Fraction other);
    Fraction* Multiply(Fraction other);
    Fraction* Divide(Fraction other);
    
    void Reduce();
    
    std::string ToString();
    
private:
    bool inTermsOfPi;
};

inline Fraction* operator +(Fraction a, Fraction b)
{
    a += b;
    return new Fraction(a);
}

inline Fraction* operator -(Fraction a, Fraction b)
{
    a += -b;
    return new Fraction(a);
}

inline Fraction* operator *(Fraction a, Fraction b)
{
    a *= b;
    return new Fraction(a);
}

inline Fraction* operator /(Fraction a, Fraction b)
{
    a /= b;
    return new Fraction(a);
}