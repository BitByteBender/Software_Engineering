#include <iostream>

using std::cout;
using std::endl;

int main()
{
  short Num1{10}, Num2{5}, Num3{2};

  cout<<"Num1: "<<Num1<<"\nNum2: "<<Num2<<"\nNum3: "<<Num3<<"\n\n";

  Num3 = 3;//3
  Num1 = Num3 + Num2;//8 - 3 - 5
  cout<<"Num1: "<<Num1<<"\nNum2: "<<Num2<<"\nNum3: "<<Num3<<"\n\n";
  
  Num2 = Num1 + (++Num1);//18 - 9 - 9
  Num3 = Num1;//9
  cout<<"Num1: "<<Num1<<"\nNum2: "<<Num2<<"\nNum3: "<<Num3<<"\n\n";
  
  short Num4 = (++Num1) + (Num1++);//20 - 11
  cout<<"Num1: "<<Num1<<"\nNum2: "<<Num2<<"\nNum3: "<<Num3<<"\nNum4: "<<Num4<<"\n\n";

  return 0;
}
