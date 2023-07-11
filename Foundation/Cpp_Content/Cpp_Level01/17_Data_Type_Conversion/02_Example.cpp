#include <iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

int main()
{
  string Number{"7824.9562"};
  
  int FirstNum{0};
  float SecondNum{0.0f};
  double ThirdNum{0};
  

  FirstNum = stoi(Number); 
  cout<<FirstNum<<"\n";

  SecondNum = stof(Number); 
  cout<<SecondNum<<"\n";

  ThirdNum = stod(Number);
  cout<<ThirdNum<<endl;
  
  return 0;
}
