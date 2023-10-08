#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

enum enMonths{Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6, Jul = 7, Aug = 8, Sept = 9, Oct = 10, Nov = 11, Dec = 12};

int main(void)
{
  enMonths Month;
  short MonthPicker{0};
  string CardStyler{"\n************************\n"};
  
  cout<<"Pick a month: ";
  cout<<CardStyler;
  cout<<"(1) January\n"
      <<"(2) February\n"
      <<"(3) March\n"
      <<"(4) April\n"
      <<"(5) May\n"
      <<"(6) June\n"
      <<"(7) July\n"
      <<"(8) August\n"
      <<"(9) September\n"
      <<"(10) October\n"
      <<"(11) November\n"
      <<"(12) December\n"
      <<CardStyler;
  cout<<"Your pick? ";
  cin>>MonthPicker;

  Month = (enMonths) MonthPicker;
  
  switch (Month){
  case enMonths::Jan:
    cout<<"January"<<endl;
    break;
  case enMonths::Feb:
    cout<<"February"<<endl;
    break;
  case enMonths::Mar:
    cout<<"March"<<endl;
    break;
  case enMonths::Apr:
    cout<<"April"<<endl;
    break;
  case enMonths::May:
    cout<<"May"<<endl;
    break;
  case enMonths::Jun:
    cout<<"June"<<endl;
    break;
  case enMonths::Jul:
    cout<<"July"<<endl;
    break;
  case enMonths::Aug:
    cout<<"August"<<endl;
    break;
  case enMonths::Sept:
    cout<<"September"<<endl;
    break;
  case enMonths::Oct:
    cout<<"October"<<endl;
    break;
  case enMonths::Nov:
    cout<<"November"<<endl;
    break;
  case enMonths::Dec:
    cout<<"December"<<endl;
    break;
  default:
    cout<<"Wrong Month!"<<endl;
      
  }
    
  return 0;
}
