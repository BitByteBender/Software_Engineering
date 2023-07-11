#include <iostream>
#include <string>
#include <typeinfo>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

int main()
{
  string st1 = "43.22";
  int Num1;
  double Num2;
  float Num3;

  Num1 = stoi(st1);
  cout<<Num1<<"->"<<typeid(Num1).name()<<"\n";

  Num2 = stod(st1);
  cout<<Num2<<"->"<<typeid(Num2).name()<<"\n";

  Num3 = stof(st1);
  cout<<Num3<<"->"<<typeid(Num3).name()<<"\n";

  int N1 = 20;
  float N2 = 33.5f;
  double N3 = 55.23;

  string st2, st3, st4;

  st2 = to_string(N1);
  st3 = to_string(N2);
  st4 = to_string(N3);

  cout<<st2<<"->"<<typeid(st2).name()<<"\n"<<st3<<"->"<<typeid(st3).name()<<"\n"<<st4<<"->"<<typeid(st4).name()<<endl;
  return 0;
}
