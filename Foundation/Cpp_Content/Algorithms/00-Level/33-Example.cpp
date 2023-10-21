#include <iostream>
#include "math.h"

using std::cout;
using std::endl;
using std::cin;

short ReadNumber(std::string Message)
{
  short Number{0};
  
  cout<<Message;
  cin>>Number;

 while ((Number < 18) || (Number > 45))
 {
   cout<<"Invalid Age\n"
       <<"Enter a valid age between 18 & 45: ";
   cin>>Number;  
 };
  
  return Number;
}

bool CheckAge(short Age)
{
  return (Age >= 18 && Age <= 45 ? 1 : 0);
}

void PrintArea(short Age)
{
  if (CheckAge(Age))
  {
    cout<<"Valid Age"<<endl;
  }
  else
  {
    cout<<"Invalid Age"<<endl;
  }
}

int main()
{
  short Age{0};

  Age = ReadNumber("Enter Age:  ");
  PrintArea(Age);
  return 0;
}
