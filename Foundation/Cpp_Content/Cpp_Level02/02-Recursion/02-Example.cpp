#include <iostream>

using std::cout, std::endl;

short calc_pow(short a, short b, short Result = 1)
{

  if (b == 0) {
    return (Result);
  }
  
  Result *= a;
  return calc_pow(a, (b - 1), Result);
}

void _pow(int a, int b)
{
  cout<<calc_pow(a, b)<<endl;
}

int main()
{
  _pow(5, 4);
  return 0;
}
