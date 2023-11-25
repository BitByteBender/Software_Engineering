#include <iostream>

unsigned int pow(unsigned short base, unsigned short exponent)
{
  unsigned short i = 0, expo = 1;

  for (i = 0; i < exponent; i++) {
    expo *= base;
  }

  return (expo);
}
