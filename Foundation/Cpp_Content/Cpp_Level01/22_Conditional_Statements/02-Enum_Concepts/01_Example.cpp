#include <iostream>

using std::cout;
using std::endl;
using std::cin;

enum enColor{Red = 0, Blue = 1, Green = 2, Yellow = 3};

int main()
{
  enColor Color;
  short ColorChecker{0};
  
  cout<<"Choose a number from(0 to 3): ";
  cin>>ColorChecker;

  if (ColorChecker == enColor::Red) {
    cout<<"Red"<<endl;
  }else if(ColorChecker == enColor::Blue){
    cout<<"Blue"<<endl;
  }else if(ColorChecker == enColor::Green){
    cout<<"Green"<<endl;
  }else if(ColorChecker == enColor::Yellow){
    cout<<"Yellow"<<endl;
  }else{
    cout<<"That's not a color in our color palette."<<endl;
  }

  return 0;
}
