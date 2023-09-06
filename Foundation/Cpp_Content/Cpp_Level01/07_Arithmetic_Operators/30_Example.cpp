#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  short A{0};
  const float PI{3.14f};
  float Area{0};

  cout<<"Enter A: ";
  cin>>A;

  Area = PI * ((A * A) /  (2 * 2));
  cout<<Area<<endl;
  return 0;
}
