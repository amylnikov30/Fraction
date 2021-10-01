# Fraction
Easy-to-use Fraction Library for C++ (C# implementation will be added later in the C# Branch)


## Documentation

### `Fraction` struct:

### Fields:

`float numerator` : Numerator of the fraction. </br>
`float denominator` : Denominator of the fraction. </br>

### Constructors:</br>
`Fraction()` : Initialises `numerator` and `denominator` to 0 and doesn't use pi.</br>
`Fraction(const float f)` : Implicit cast from a `float`.</br>
`Fraction(float numerator, float denominator)` : Main initialiser.</br>
`Fraction(const char* s)` Implicit cast from a c-style string.</br>
`Fraction(const Fraction& other)` Default copy constructor.</br>
</br>

### Operators:</br>
`Fraction* operator +(Fraction& other)` : Adds left value to right value. Equivalent method: `Add(Fracton& other)`. </br>
`Fraction* operator -(Fraction& other)` : Subtracts right value from left value. Equivalent method: `Subtract(Fracton& other)`. </br>
`Fraction* operator *(Fraction& other)` : Multiplies left value by right value. Equivalent method: `Multiply(Fracton& other)`. </br>
`Fraction* operator /(Fraction& other)` : Divides left value by right value. Equivalent method: `Divide(Fracton& other)`. </br>
- Multiplication of const char* by const char* can be used but an implicit Fraction cast must be used. See [Examples](#Examples) for more details. </br>


### Methods:</br>
`void Reduce()` : Reduces the fraction.</br>
`std::string ToString()` : Returns a human-readable string of the fraction in fraction notation and uses pi when necessary.</br>
`static std::string InTermsOfPI(float radians)` : Takes a radian value and returns a string in fraction notation in terms of pi.</br>
`static Fraction* FromString(const char* s)` : Returns a fraction from a string in fraction notation. </br>

## Examples

```cpp
#include <iostream>
#include "Fraction.h"

int main()
{
    Fraction a = Fraction(1, 2);
    Fraction b = "1/4";
    Fraction c = 2.f;

    std::cout << a * b << std::endl;
    std::cout << b * c << std::endl;
    std::cout << (Fraction)"1/4" + (Fraction)"1/2" << std::endl;
}
```

### Result:
```bash
1/8
1/2
3/4
```