# Fraction
Easy-to-use Fraction Library for C++


## Documentation

`Fraction` class:

###Constructors:
`Fraction()`
`Fraction(float numerator, float denominator)`
`Fraction(const char* s)`
`Fraction(const Fraction& other)`
Constructor with implicit cast from `float` will be added later

###Operators
`operator +(Fraction& other)`
`operator -(Fraction& other)`
`operator *(Fraction& other)`
`operator /(Fraction& other)`
String-string multiplication in fraction form will be added later

###Methods
`void Reduce()`
`std::string ToString()`
`std::string InTermsOfPI(float radians)`
`static Fraction* FromString(const char* s)`
