#include <iostream>

using std::cout;
using std::endl;

short CalculateAge(short Years, short Age){ 
  return Age + Years;
}

void PrintData(short Age, short Years, short CurrentAge){
  cout<<"Your Age: "<<Age<<"\n";
  cout<<"Years Added: "<<Years<<"\n";
  cout<<"Your Age in "<<Years<<" years is: "<<CurrentAge<<endl;
}

int main()
{
  short Age{30};
  short Years{5};
  PrintData(Age, Years, CalculateAge(Years, Age));
  return 0;
}
