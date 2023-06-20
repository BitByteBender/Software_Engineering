#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
  string AddSignPlusNewLine{" +\n"}; 
  int FirstNumber = 50, SecondNumber = 20, ThirdNumber = 15, FourthNumber = 15;
  cout<<FirstNumber<<AddSignPlusNewLine
      <<SecondNumber<<AddSignPlusNewLine
      <<ThirdNumber<<AddSignPlusNewLine<<FourthNumber
      <<"\n\n-----------------------\n\n";
  
  int Sum = FirstNumber + SecondNumber + ThirdNumber + FourthNumber;
  cout<<"Total= "<<Sum<<endl;
  
  return 0;
}
