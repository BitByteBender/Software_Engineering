#include <iostream>

using std::cout;
using std::endl;

short A{999};

short CalculateSum(){
  short A = 5, Sum = 0;
  return Sum = A + 50;
}

void PrintSum(short Sum){
  Sum = CalculateSum();
  cout<<"The sum is: "<<Sum<<endl;
}

int main()
{
  short A = 78;
  cout<<"Local A: "<<A<<"\n";
  PrintSum(CalculateSum());

  cout<<"Global A: "<<::A<<"\n";

  ::A++;
  cout<<"Global A incremented by 1: "<<::A<<endl;
  return 0;
}
