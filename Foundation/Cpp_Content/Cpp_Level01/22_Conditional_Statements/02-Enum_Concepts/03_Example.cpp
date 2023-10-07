#include <iostream>

using std::cout;
using std::endl;
using std::cin;

enum enColors{Red = 1, Blue = 2, Green = 3};

int main()
{
  enColors Color;
  short NumColor{0};
  
  cout<<"Please choose a color: "<<"\n"
      <<"(1) Red\n(2) Blue\n(3) Green\n"
      <<"Your choice: ";
  cin>>NumColor;

  Color = (enColors) NumColor;
  
  if (Color == enColors::Red) {
    cout<<"Color: "<<"Red "<<"----> "<<enColors::Red<<endl;
    system("color 4F");
  }else if(Color == enColors::Blue){
    cout<<"Color: "<<"Blue "<<"----> "<<enColors::Blue<<endl;
    system("color 1F");
  }else if(Color == enColors::Green){
    cout<<"Color: "<<"Green "<<"----> "<<enColors::Green<<endl;
    system("color 2F");
  }else{
    cout<<"Sorry! We don't have this color in our color palettes.";
  }
    
  return 0;
}
