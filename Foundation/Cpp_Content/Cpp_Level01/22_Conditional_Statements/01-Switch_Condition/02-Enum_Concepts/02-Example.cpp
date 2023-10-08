#include <iostream>

using std::cout;
using std::endl;
using std::cin;

enum enDays{Mon = 0, Tue = 1, Wed = 2, Thurs = 3, Fri = 4, Sat = 5, Sun = 6};

int main()
{
  enDays Day;
  short DayPicker{0};
  std::string CardStyle{"\n*********************\n"};
  

  cout<<"Choose a day: ";
  cout<<CardStyle;
  cout<<"(0) Monday\n";
  cout<<"(1) Tuesday\n";
  cout<<"(2) Wednesday\n";
  cout<<"(3) Thursday\n";
  cout<<"(4) Friday\n";
  cout<<"(5) Saturday\n";
  cout<<"(6) Sunday\n";
  cout<<CardStyle;
  cout<<"You choose? ";
  cin>>DayPicker;

  Day = (enDays)DayPicker;

  switch (Day) {
  case enDays::Mon:
    cout<<"Monday"<<endl;
    break;
  case enDays::Tue:
    cout<<"Tuesday"<<endl;
    break;
  case enDays::Wed:
    cout<<"Wednesday"<<endl;
    break;
  case enDays::Thurs:
    cout<<"Thursday"<<endl;
    break;
  case enDays::Fri:
    cout<<"Friday"<<endl;
    break;
  case enDays::Sat:
    cout<<"Saturday"<<endl;
    break;
  case enDays::Sun:
    cout<<"Sunday"<<endl;
    break;
  default:
  cout<<"Invalid Entry"<<endl;
  }
  
  return 0;
}
