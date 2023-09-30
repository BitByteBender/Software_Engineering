#include <iostream>

using std::cout;
using std::endl;
using std::cin;

short ReadNumber(){
  short Number{0};

  cout<<"Enter a number: ";
  cin>>Number;

  return Number;
}

short CalculateSum(short Num1, short Num2){
  return Num1 + Num2;
}

float CalculateAvg(short Num1, short Num2){
  return CalculateSum(Num1, Num2) / 2.0f;
}

void PrintSum(short Sum, float Avg, float Array[4]){
  cout<<"Sum is: "<<Sum<<"\n";
  cout<<"Avg is: "<<Avg<<"\n";
  cout<<"Array at index 0: "<<Array[0]
      <<"\nArray at index 1: "<<Array[1]
      <<"\nArray at index 2: "<<Array[2]
      <<"\nArray at index 3: "<<Array[3]<<endl;
}

int main()
{
  short Num1 = ReadNumber();
  short Num2 = ReadNumber();

  short Sum = CalculateSum(Num1, Num2);
  float Avg = CalculateAvg(Num1, Num2);
  float Arr[4] = {float(Num1), float(Num2), float(Sum), Avg};
  PrintSum(Sum, Avg, Arr);
  return 0;
}
