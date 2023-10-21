#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void ReadPIN(short &PIN)
{
  unsigned short counter{0};
  
  do {
    if (counter > 0 && counter < 3 && PIN != 1234)
    {
      cout<<"Re-Enter a correct pin code ";
      cout<<"("<<abs(2 - counter)<<" Attempts left)\n-> ";
      cin>>PIN;
    }
    else
    {
      cout<<"Enter the pin code: ";
      cin>>PIN;
    }
    counter++;
  } while (counter < 3 && PIN != 1234);

}

void PrintResult(short PIN)
{
  if (PIN == 1234) {
    cout<<"Your balance is: 7500"<<endl;
  }else {
    cout<<"Wrong PIN"<<endl;
  }
}

int main()
{
  short PIN{0};
  
  ReadPIN(PIN);
  PrintResult(PIN);
  return 0;
}
