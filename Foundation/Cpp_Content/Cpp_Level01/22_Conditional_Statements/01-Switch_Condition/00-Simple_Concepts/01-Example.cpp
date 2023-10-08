#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main(void)
{

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

  
  switch (MonthPicker){
  case 1:
    cout<<"January"<<endl;
    break;
  case 2:
    cout<<"February"<<endl;
    break;
  case 3:
    cout<<"March"<<endl;
    break;
  case 4:
    cout<<"April"<<endl;
    break;
  case 5:
    cout<<"May"<<endl;
    break;
  case 6:
    cout<<"June"<<endl;
    break;
  case 7:
    cout<<"July"<<endl;
    break;
  case 8:
    cout<<"August"<<endl;
    break;
  case 9:
    cout<<"September"<<endl;
    break;
  case 10:
    cout<<"October"<<endl;
    break;
  case 11:
    cout<<"November"<<endl;
    break;
  case 12:
    cout<<"December"<<endl;
    break;
  default:
    cout<<"Wrong Month!"<<endl;
      
  }
    
  return 0;
}
