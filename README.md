# Fraction
Easy-to-use Fraction Library for C++ (C# implementation will be added later in the C# Branch)


## Documentation

### `Fraction` class:

### Constructors:</br>
`Fraction()` </br>
`Fraction(float numerator, float denominator)`</br>
`Fraction(const char* s)`</br>
`Fraction(const Fraction& other)`</br>
- Constructor with implicit cast from `float` will be added later</br>
</br>

### Operators:</br>
`operator +(Fraction& other)`</br>
`operator -(Fraction& other)`</br>
`operator *(Fraction& other)`</br>
`operator /(Fraction& other)`</br>
<<<<<<< HEAD
- Multiplication of const char* by const char* can be used but an implicit Fraction cast must be used. See [Examples](#Examples) for more details</br>


### Methods:</br>
`void Reduce()`</br>
`std::string ToString()`</br>
`std::string InTermsOfPI(float radians)`</br>
`static Fraction* FromString(const char* s)`</br>

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