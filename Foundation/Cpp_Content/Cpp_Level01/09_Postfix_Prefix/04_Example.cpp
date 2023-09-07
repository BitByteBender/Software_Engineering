#include <iostream>

using std::cout;
using std::endl;

int main()
{
  short Num1{78}, Num2{2}, Num3{15};

  cout<<"Num1: "<<Num1<<"\nNum2: "<<Num2<<"\nNum3: "<<Num3<<"\n\n";

  Num3 = Num1++;//Num3 = 78 */* Num1= 79
  Num2 = ++Num1;//Num2 = 80 */* Num1 = 80
  cout<<"Num1: "<<Num1<<"\nNum2: "<<Num2<<"\nNum3: "<<Num3<<"\n\n";
  
  short Num4 = Num2++;//Num4 = 80 */* Num2 = 81

  cout<<"Num1: "<<Num1<<"\nNum2: "<<Num2<<"\nNum3: "<<Num3<<"\nNum4: "<<Num4<<"\n\n";
  
  Num4 = ++Num1; //Num4 = 81 */* Num1 = 81
  Num1 = --Num3; //Num1 = 77 */* Num3 = 77
  Num3 = Num2--; //Num3 = 81 */* Num2= 80

  cout<<"Num1: "<<Num1<<"\nNum2: "<<Num2<<"\nNum3: "<<Num3<<"\nNum4: "<<Num4<<endl;

  return 0;
}
