#include <iostream>
#include "cmath"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::to_string;

int ReadPositiveNumber(string Message)
{
  int *ptrNum = new int;

  cout<<Message;
  cin>>*ptrNum;

  int result = *ptrNum;
  delete ptrNum;
  return (result);
}

bool isPalindrome(int *ptrNum)
{
  string NumHolder = to_string(*ptrNum);
  short RemainStart = 0, RemainEnd = 0, Base = 10;
  int Num1 = *ptrNum, Num2 = *ptrNum;
  long unsigned int Length = NumHolder.length();
  
  while (*ptrNum > 0 && Length >= 1) {
    //for tracing & testing
    cout<<"RemainEnd: "<<RemainEnd<<" | Num1: "<<Num1;
    cout<<" | RemainStart: "<<RemainStart<<" | Num2: "<<Num2;
    cout<<" | ptrNum: "<<*ptrNum<<"\n";
    
    RemainEnd = (Num1 % 10);
    Num1 = (Num1 / 10);
  
    RemainStart = (Num2 / (int)pow(Base, (Length - 1)));
    Num2 = (Num2 % (int)pow(Base, (Length - 1)));
  
    if ((RemainStart - RemainEnd) != 0) {
      return (0);
    }
    
    Length --;
  }

  return (1);
}

void Print_PalindromeOrNot(int Num)
{
  if (isPalindrome(&Num)) {
    cout<<"Yes, is a palindrome.\n";
  }
  else
  {
    cout<<"No, is not a palindrome.\n";
  }
  cout<<endl;
}

int main()
{
  int Num = ReadPositiveNumber("Enter a number: ");
  Print_PalindromeOrNot(Num);
  return 0;
}
