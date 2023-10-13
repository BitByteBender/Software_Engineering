#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  short i{0}, PIN{0}, userBalance{7500};
  string Text{"Wrong PIN!"};
  
  cout<<"Enter n: ";
  cin>>PIN;

  i = 0;

  while (i < 3 || PIN != 1234) {

    if (PIN != 1234)
    {
      if (i < 2)
      {
	cout<<"Re-enter your PIN code: ";
	cin>>PIN;
      }
      else
      {
	cout<<"Wrong PIN"<<endl;
	break;
      }
    }
    else
    {
      cout <<"Your Balance is: "<<userBalance<<endl;
      break;
    }
    i++;
  }
  
  
  return 0;
}
