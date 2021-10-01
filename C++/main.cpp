#include "Fraction.h"
#include <iostream>

int main()
{
    Fraction a = Fraction(1, 4);
    Fraction b = 2.f;
    Fraction c = "1(pi)/3";
    
    std::cout << c << std::endl;
}