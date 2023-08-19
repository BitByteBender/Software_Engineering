#include <iostream>

using namespace std;

int ReadNumber(){
  int Seconds{0};
  cout<<"How many seconds? :";
  cin>>Seconds;
  return Seconds;
}

void ReverseTaskDuration(int Seconds){
  short Days = (Seconds / (24 * 3600));
  short Hours = (Seconds % (24*3600) / 3600);
  short Mins = ((Seconds % 3600) / 60);
  short RemainingSeconds = (Seconds % 60);
  cout<<Days<<":"<<Hours<<":"<<Mins<<":"<<RemainingSeconds<<endl;
}



int main()
{
  int Seconds = ReadNumber();
  ReverseTaskDuration(Seconds);
  return 0;
}
