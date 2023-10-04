#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned short PIN{0}, Balance{11450};

  cout<<"Enter ATM PIN Code: ";
  cin>>PIN;
  
  if (PIN == 1234) {
    cout<<"Your Balance is: $"<<Balance<<endl;
  }else{
    cout<<"Wrong PIN!"<<endl;
  }
  
  return 0;
}
