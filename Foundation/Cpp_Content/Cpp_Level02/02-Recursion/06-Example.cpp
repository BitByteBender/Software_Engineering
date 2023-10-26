#include <iostream>

using std::cout;
using std::endl;

short func(short);

int main()
{
  short x{6};
  printf("%d\n", func(x));
  return 0;
}

short func(short x)
{
  if (x == 0) {
    return (3);
  }
  else
  {
    return (7 + func(x - 2));
  }
}
