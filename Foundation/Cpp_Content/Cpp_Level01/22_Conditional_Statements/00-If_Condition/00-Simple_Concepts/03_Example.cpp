#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned short Mark1{0}, Mark2{0}, Mark3{0};
  float CalculateAverage{0.0f};
  
  cout<<"Enter Mark1: ";
  cin>>Mark1;

  cout<<"Enter Mark2: ";
  cin>>Mark2;

  cout<<"Enter Mark3: ";
  cin>>Mark3;

  CalculateAverage = (Mark1 + Mark2 + Mark3) / 3.0f;

  if (CalculateAverage>=85) {
    cout<<"Average Marks: "<<CalculateAverage<<" --Yes--> Pass"<<endl;
  }else{
    cout<<"Average Marks: "<<CalculateAverage<<" --Sorry!--> Fail"<<endl;
  }
  
  return 0;
}
