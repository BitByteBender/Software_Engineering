#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  char MyChar{'A'};
  int MyNumber{0};

  cout<<"Enter a char: ";
  cin>>MyChar;

  cout<<"Enter a number: ";
  cin>>MyNumber;

  cout<<"My char is: "<<MyChar<<"\nMy number: "<<MyNumber<<endl;
  return 0;
}
