#include <iostream>

using std::cout;
using std::cin;
using std::endl;

unsigned short ReadNumber(std::string Message){
  unsigned short Num{0};
  cout<<Message;
  cin>>Num;
  return Num;
}

bool CheckAge(unsigned short Age){
  return (Age>=18 && Age <= 44);
}

void PrintResult(unsigned short Age){

  if (CheckAge(Age)) {
    cout<<"Valid Age"<<endl;
  }
  else{
    cout<<"Invalid Age"<<endl;
  }
}

int main()
{
  unsigned short Age = ReadNumber("Enter an age to check: ");
  PrintResult(Age);
  return 0;
}
