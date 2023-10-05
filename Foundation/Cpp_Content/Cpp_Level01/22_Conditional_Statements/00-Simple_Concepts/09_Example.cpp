#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned short Day{0};

  cout<<"Enter a day(1-7): ";
  cin>>Day;

  if (Day == 1) {
    cout<<"Sunday"<<endl;
  }else if(Day == 2){
    cout<<"Monday"<<endl;
  }else if(Day == 3){
    cout<<"Tuesday"<<endl;
  }else if(Day == 4){
    cout<<"Wednesday"<<endl;
  }else if(Day == 5){
    cout<<"Thursday"<<endl;
  }else if(Day == 6){
    cout<<"Friday"<<endl;
  }else{
    cout<<"Saturday"<<endl;
  }
  return 0;
}
