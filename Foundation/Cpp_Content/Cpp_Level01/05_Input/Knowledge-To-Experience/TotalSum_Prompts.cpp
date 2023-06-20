#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  //User Prompts
  cout<<"Enter firstnumber: ";
  int FirstNumber{0};
  cin>>FirstNumber;

  cout<<"Enter secondnumber: ";
  int SecondNumber{0};
  cin>>SecondNumber;

  cout<<"Enter thirdnumber: ";
  int ThirdNumber{0};
  cin>>ThirdNumber;

  cout<<"Enter fourthnumber: ";
  int FourthNumber{0};
  cin>>FourthNumber;

  cout<<"Enter fifthnumber: ";
  int FifthNumber{0};
  cin>>FifthNumber;

  std::string PlusSignAndNewLine{" +\n"};
  int TotalSum = FirstNumber + SecondNumber + ThirdNumber + FourthNumber + FifthNumber;

  //Output
  cout<<FirstNumber<<PlusSignAndNewLine
      <<SecondNumber<<PlusSignAndNewLine
      <<ThirdNumber<<PlusSignAndNewLine
      <<FourthNumber<<PlusSignAndNewLine
      <<FifthNumber;
  
  cout<<"\n\n---------------------------\n\n"<<TotalSum<<endl;
  return 0;
}
