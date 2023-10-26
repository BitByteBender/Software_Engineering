#include <iostream>

using std::cout, std::endl;

short n{1};

void Odd(), Even();

int main()
{
  Odd(), Even();
  cout<<endl;
  return 0;
}

void Odd()
{
  if (::n <= 20) {
    printf("%d ", ::n+1);
    ::n++;
    Even();
  }
  return;
}

void Even()
{
  if (::n <= 20) {
    printf("%d ", ::n-1);
    ::n++;
    Odd();
  }
  return;
}
