#include <iostream>

using std::cout;
using std::endl;

int main()
{
  short Alpha{50}, Beta{70};

  cout<<"Alpha + Beta = "<<Alpha + Beta<<"\n";
  cout<<"Alpha - Beta = "<<Alpha - Beta<<"\n";
  cout<<"Alpha * Beta = "<<Alpha * Beta<<"\n";
  cout<<"Alpha / Beta = "<<Alpha / Beta<<"\n";
  cout<<"Alpha % Beta = "<<Alpha % Beta<<"\n";

  cout<<"\n\n*************************************\n\n";
  float Delta{71.0f}, Epsilon{95.0f};

  cout<<"Delta + Epsilon = "<<Delta + Epsilon<<"\n";
  cout<<"Delta - Epsilon = "<<Delta - Epsilon<<"\n";
  cout<<"Delta * Epsilon = "<<Delta * Epsilon<<"\n";
  cout<<"Delta / Epsilon = "<<Delta / Epsilon<<"\n";
 
  return 0;
}
