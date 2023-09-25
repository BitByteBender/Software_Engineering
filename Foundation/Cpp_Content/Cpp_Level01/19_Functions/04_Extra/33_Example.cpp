#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void SwapFunc(short &A, short &B){
  short TempVar = A;
  A = B;
  B = TempVar;
}

void PrintResult(short A, short B){
  cout<<"Before Swap ->\nA: "<<A<<"\n";
  cout<<"B: "<<B<<"\n";
  SwapFunc(A, B);
  cout<<"After Swap ->\nA: "<<A<<"\n";
  cout<<"B: "<<B<<"\n";
}

int main()
{
  short A{0}, B{0};

  cout<<"Enter A: ";
  cin>>A;

  cout<<"Enter B: ";
  cin>>B;

  PrintResult(A, B);

  cout<<"After Swap ->\nA: "<<A<<"\nB: "<<B<<endl;
  SwapFunc(A, B);
  
  cout<<"After Swap ->\nA: "<<A<<"\nB: "<<B<<endl;
  
  return 0;
}
