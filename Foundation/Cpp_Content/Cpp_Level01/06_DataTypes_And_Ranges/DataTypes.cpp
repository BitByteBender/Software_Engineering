#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  //Note: Everything by default are Signed

  int A0 = 1;//Signed int A0 = 1 (same thing) -> start from -2B To +2B
  unsigned int A1 = 2;//Takes only Positive numbers -> start from 0 To +4B+1

  short int A2 = -3;//Signed short A2 = -3 (same thing)
  unsigned short A3 = -10;//Error! out of range (Overflow)

  long int A4;//Signed long int A4;
  long long int A5;//Signed long long int A5;

  unsigned long int A6;
  unsigned long long int A7;
  
  float B0 = 15.0f;

  double C0 = 78E15;
  long double C1 = 185.9847122117;

  signed char D0 = 'a';//char D0 = 'a';
  unsigned char D1 = 'T';

  return 0;
}
