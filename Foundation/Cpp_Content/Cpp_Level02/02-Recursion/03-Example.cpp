#include <iostream>

short _pow(short Base, short Power)
{
  if (Power == 0)
  {
    return (1);
  }
  else
  {
    
    return (Base * _pow(Base, (Power - 1)));
  }
}

int main()
{
  std::cout<<_pow(5, 5)<<std::endl;
  return 0;
}
 
