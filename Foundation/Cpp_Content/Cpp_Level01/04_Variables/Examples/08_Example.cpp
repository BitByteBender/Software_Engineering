#include <iostream>

using std::cout;
using std::endl;

int main()
{
  int FirstNum{55}, SecondNum{5}, ThirdNum{25}, FourthNum{13}, FifthNum{2}, Sum = FirstNum + SecondNum + ThirdNum + FourthNum + FifthNum;

  cout<<FirstNum<<" +\n"<<SecondNum<<" +\n"<<ThirdNum<<" +\n"<<FourthNum<<" +\n"<<FifthNum<<"\n\n-----------------------------\n\nTotal = "<<Sum<<endl;
  return 0;
}
