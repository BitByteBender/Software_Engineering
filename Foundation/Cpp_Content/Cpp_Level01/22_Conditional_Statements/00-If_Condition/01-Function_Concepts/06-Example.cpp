#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void ReadNum(unsigned short &PIN, std::string Message){
  cout<<Message;
  cin>>PIN;
}

bool CheckPinCode(unsigned short PIN){
  return (PIN == 1234);
}

void PrintResult(unsigned short PIN, long int  Balance, std::string ValidationText){
  if (CheckPinCode(PIN)) {
    cout<<"Your Balance: "<<Balance<<endl;
  }else{
    cout<<ValidationText<<endl;
  }
}

int main()
{
  unsigned short PIN{0};
  ReadNum(PIN, "Enter your pin code: ");
  PrintResult(PIN, 999999, "Wrong PIN"); 
  return 0;
}
