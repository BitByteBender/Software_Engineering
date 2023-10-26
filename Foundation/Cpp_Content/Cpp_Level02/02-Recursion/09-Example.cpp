#include <iostream>

using std::cout, std::endl;

void Odd(short);
void Even(short);
short Func(short);

int main()
{
  short n{1};
  Func(n);
  return 0;
}

void Odd(short Num)
{
  printf("%d ", (Num + 1));
}

void Even(short Num)
{
  printf("%d ", (Num - 1));
}

short Func(short Num)
{

  if (Num > 10)
  {
    cout<<endl;
    return 0;
  }
  else
  {
    if (Num % 2 != 0) {
      Odd(Num);
      return (Func(Num + 1));
    }
    else
    {
      Even(Num);
      return (Func(Num + 1));
    }
  }
}
