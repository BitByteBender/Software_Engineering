#include <iostream>

using std::cout;
using std::endl;
using std::cin;

enum enColors{Red = 0, Blue, Green};

void ReadHeader(std::string CardStyler){
  cout<<"Pick your color: ";
  cout<<CardStyler
      <<"(0) Red\n"
      <<"(1) Blue\n"
      <<"(2) Green\n"
      <<CardStyler<<endl;
}

unsigned short ReadPositiveNumber(std::string Message){
  short Picker{0};
  
  cout<<Message;
  cin>>Picker;

  return Picker;
}

enColors ReadEnums(unsigned short Picker){
  enColors Color;
  return Color = (enColors)Picker;
}

std::string CheckColors(enColors Color){
  switch (Color){
  case enColors::Red:
    return "Red";
  case enColors::Blue:
    return "Blue";
  case enColors::Green:
    return "Green";
  default:
    return "Wrong Color!";
  }
}

void PrintColor(std::string ColorChoice){
  cout<<"Your chosen color: "<<ColorChoice<<endl;
}

int main(void)
{
  ReadHeader("\n************************\n");
  unsigned short Picker = ReadPositiveNumber("Choose a color: ");
  PrintColor(CheckColors(ReadEnums(Picker)));
  return 0;
}
