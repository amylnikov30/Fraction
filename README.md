# Fraction
Easy-to-use Fraction Library for C++


## Documentation

`Fraction` class:

### Constructors:</br>
`Fraction()` </br>
`Fraction(float numerator, float denominator)`</br>
`Fraction(const char* s)`</br>
`Fraction(const Fraction& other)`</br>
#### Constructor with implicit cast from `float` will be added later ####</br>
</br>
### Operators:</br>
`operator +(Fraction& other)`</br>
`operator -(Fraction& other)`</br>
`operator *(Fraction& other)`</br>
`operator /(Fraction& other)`</br>
#### Multiplication of `const char*` by `const char*` in fraction form will be added later</br>
</br>
### Methods:</br>
`void Reduce()`</br>
`std::string ToString()`</br>
`std::string InTermsOfPI(float radians)`</br>
`static Fraction* FromString(const char* s)`</br>
