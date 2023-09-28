#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
  string ArrayName[3] = {"Soufiane", "Carl", "Cleveland"};

  cout<<"1st Index: "<<ArrayName[0]<<"\n";
  cout<<"2nd Index: "<<ArrayName[1]<<"\n";
  cout<<"3rd Index: "<<ArrayName[2]<<"\n\n";

  //Strings are an array of characters ;)
  cout<<"1st char at index 0: "<<ArrayName[0][0]<<"\n";
  cout<<"1st char at index 1: "<<ArrayName[1][0]<<"\n";
  cout<<"1st char at index 2: "<<ArrayName[2][0]<<endl;
  return 0;
}
