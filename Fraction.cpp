#include "Fraction.h"
#include "Utils.h"

#pragma region Constructors

Fraction::Fraction()
{
    numerator = 0;
    denominator = 0;
    inTermsOfPi = false;
}

Fraction::Fraction(float numerator, float denominator, bool inTermsOfPi)
{
    this->numerator = numerator;
    this->denominator = denominator;
    this->inTermsOfPi = inTermsOfPi;
}

Fraction::Fraction(const char *s)
{
    *this = *FromString(std::string (s));
}

Fraction::Fraction(const float f)
{
    numerator = f;
    denominator = 1;
}

#pragma endregion

#pragma region Operators

#pragma endregion

#pragma region Mathematical Operations

Fraction* Fraction::Add(Fraction other)
{
    float _denominator = this->denominator * other.denominator;
    float _numerator = this->numerator * other.denominator + other.numerator * this->denominator;
    
    Fraction* result = new Fraction(_numerator, _denominator);
    result->Reduce();
    
    return result;
}

Fraction* Fraction::Subtract(Fraction other)
{
    return Add(-other);
}


Fraction* Fraction::Multiply(Fraction other)
{
    auto result = Fraction(this->numerator * other.numerator, this->denominator * other.denominator);
    result.Reduce();
    
    return &result;
}

Fraction* Fraction::Divide(Fraction other)
{
    float _denominator = other.denominator;
    other.denominator = other.numerator;
    other.numerator = _denominator;
    
    return Multiply(other);
}

void Fraction::Reduce()
{
    for (float i = numerator * denominator; i >= 1; i--)
    {
        if ((fmod(denominator, i) == 0) && (fmod(numerator, i) == 0))
        {
            denominator /= i;
            numerator /= i;
        }
    }
}

#pragma endregion

#pragma region String operations

Fraction* Fraction::FromString(std::string input)
{
    const char* pi = "(pi)";
    const char slash = '/';
    
    const int splitPosition = input.find(slash);
    
    if (splitPosition == -1) return new Fraction();
    

    std::string  s_numerator = input.substr(0, splitPosition);
    std::string  s_denominator = input.substr(splitPosition + 1, input.size()-1);
    
    const int piPosition = s_numerator.find(pi);


    if (piPosition != -1)
    {
        s_numerator = s_numerator.erase(piPosition + strlen(pi));
        
        return new Fraction(std::stof(s_numerator) * PI, std::stof(s_denominator), true);
    }
    
    return new Fraction(std::stof(s_numerator), std::stof(s_denominator));
}

std::string Fraction::InTermsOfPI(float radians)
{
    const float degrees = radians * (180 / PI);
    
    float numerator = degrees;
    float denomator = 180;
    
    Fraction* result = new Fraction(numerator, denomator);
    result->Reduce();
    
    const std::string s_numerator = std::to_string(result->numerator);
    const std::string s_denominator = std::to_string(result->denominator);
    
    return s_numerator + "(pi)/" + s_denominator;
}

std::string Fraction::ToString()
{
    if (inTermsOfPi) return InTermsOfPI(numerator/denominator);
    
    std::string s_numerator = std::to_string(std::round(numerator, 3));
    s_numerator.erase (s_numerator.find_last_not_of('0'), std::string::npos );

    if (denominator == 1) return s_numerator;
    std::string  s_denominator = std::to_string(std::round(denominator, 3));
    s_denominator.erase (s_denominator.find_last_not_of('0'), std::string::npos );
    
    return s_numerator + '/' + s_denominator;
}

#pragma endregion