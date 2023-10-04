#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void ReadMarks(unsigned short& Num, std::string Message){
  cout<<Message;
  cin>>Num;
}

float CalculateAverage(unsigned short Mark1, unsigned short Mark2, unsigned short Mark3){
  return (Mark1 + Mark2 + Mark3) / 3.0f;
}

bool CheckAvg(unsigned short Mark1, unsigned short Mark2, unsigned short Mark3){
  return CalculateAverage(Mark1, Mark2, Mark3)>=50;
}

void PrintResult(unsigned short Mark1, unsigned short Mark2, unsigned short Mark3){
  float Average = CalculateAverage(Mark1, Mark2, Mark3);
  
  if (CheckAvg(Mark1, Mark2, Mark3)) {
    cout<<"Average: "<<Average<<" ---> Pass"<<endl;
  }else{
    cout<<"Average: "<<Average<<" ---> Fail"<<endl;
  }
}

int main()
{
  unsigned short Mark1{0}, Mark2{0}, Mark3{0};
  ReadMarks(Mark1, "Enter Mark1: ");
  ReadMarks(Mark2, "Enter Mark2: ");
  ReadMarks(Mark3, "Enter Mark3: ");
  PrintResult(Mark1, Mark2, Mark3);
  return 0;
}
