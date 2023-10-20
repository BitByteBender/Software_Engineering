#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct stTaskDuration
{
  unsigned short Days{0};
  unsigned short Hours{0};
  unsigned short Minutes{0};
  unsigned int Seconds{0};
};

float ReadNumber(string Message)
{
  float Num{0.0f};

  cout<<"How many "<<Message;
  cin>>Num;

  return Num;
}

void ReadData(stTaskDuration *TD)
{
  TD->Days = ReadNumber("days:\n-> ");
  TD->Hours = ReadNumber("hours:\n-> ");
  TD->Minutes = ReadNumber("minutes:\n-> ");
  TD->Seconds = ReadNumber("secs:\n-> ");
}

float CalcSeconds(stTaskDuration TD)
{
  return ((TD.Days * 24 * 3600) + (TD.Hours * 3600) + (TD.Minutes * 60) + (TD.Seconds));
}

void PrintSeconds(float Result)
{
  cout<<Result<<endl;
}

int main()
{
  stTaskDuration TD, *pTD{nullptr};
  pTD = &TD;
  float Result{0}, *pResult = &Result;
  
  ReadData(pTD);
  *pResult = CalcSeconds(*pTD);

  PrintSeconds(*pResult);
  return 0;
}
