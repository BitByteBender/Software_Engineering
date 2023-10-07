#include <iostream>

using std::cout;
using std::endl;
using std::cin;

enum enColors{Red = 1, Blue = 2, Green = 3};

int main()
{
  enColors Color = enColors::Red;
  short NumColor{0};
  
  cout<<"Please choose a color: "<<"\n"
      <<"(1) Red\n(2) Blue\n(3) Green\n"
      <<"Your choice: ";
  cin>>NumColor;

  if (NumColor == enColors::Red) {
    cout<<"Color: "<<"Red "<<"----> "<<enColors::Red<<endl;
  }else if(NumColor == enColors::Blue){
    cout<<"Color: "<<"Blue "<<"----> "<<enColors::Blue<<endl;
  }else if(NumColor == enColors::Green){
    cout<<"Color: "<<"Green "<<"----> "<<enColors::Green<<endl;
  }else{
    cout<<"Sorry! We don't have this color in our color palettes.";
  }
    
  return 0;
}
