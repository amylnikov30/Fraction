#include "Fraction.h"
#include <iostream>

int main()
{
    Fraction a = Fraction(1, 4);
    Fraction b = 2.f;
    Fraction c = "1/3"; 
    
//    Fraction* x = a * "1/2";
//    Fraction* y = a * "1/4";
    
    std::cout << a + b << std::endl;
}