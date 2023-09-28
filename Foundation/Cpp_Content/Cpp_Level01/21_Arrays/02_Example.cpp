#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
  //strings are an array of characters
  string Text{"ALX Software Engineer Student"};

  cout<<"At position 0: "<<Text[0]<<"\n";
  cout<<"At position 1: "<<Text[1]<<"\n";
  cout<<"At position 2: "<<Text[2]<<"\n";
  cout<<"At position 3: "<<Text[3]<<"\n";
  cout<<"At position 4: "<<Text[4]<<"\n";
  cout<<"At position 13: "<<Text[13]<<"\n";
  cout<<"At position 21: "<<Text[21]<<"\n";
  cout<<"At position 22: "<<Text[22]<<"\n";
  cout<<"At position 23: "<<Text[23]<<"\n";
  cout<<"At position 24: "<<Text[24]<<"\n";
  cout<<"At position 25: "<<Text[25]<<"\n";
  cout<<"At position 26: "<<Text[26]<<"\n";
  cout<<"At position 27: "<<Text[27]<<"\n";
  cout<<"At position 28: "<<Text[28]<<"\n\n";

  cout<<"Short(Output): "
      <<Text[0]<<Text[1]<<Text[2]<<Text[3]<<Text[4]
      <<Text[13]<<Text[21]<<Text[22]<<Text[23]<<Text[24]
      <<Text[25]<<Text[26]<<Text[27]<<Text[28]<<endl;
  return 0;
}

