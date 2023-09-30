#include <iostream>

using std::cout;
using std::endl;
using std::to_string;

short SummingStrings(std::string Str1, std::string Str2){
  return stoi(Str1) + stoi(Str2);
}

void PrintSum(short Sum, std::string strArr[4]){
  cout<<"Sum is: "<<Sum<<"\n";
  cout<<"At position 0: "<<strArr[0]
      <<"\nAt position 1: "<<strArr[1]
      <<"\nAt position 2: "<<strArr[2]
      <<"\nAt position 3: "<<strArr[3]<<endl;
}

int main()
{
  std::string strNum1 = "15";
  std::string strNum2 = "35";
  std::string strArr[4] = {strNum1, strNum2, to_string(SummingStrings(strNum1, strNum2)),
							    to_string(stoi(strNum1) * 2)};
  PrintSum(SummingStrings(strNum1, strNum2), strArr);
  return 0;
}
