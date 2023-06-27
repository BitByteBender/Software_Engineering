#include <iostream>

using std::cout;
using std::endl;


int main()
{
  short Alpha{15}, Beta{10};

  Alpha += Beta; // Alpha = Alpha + Beta
  cout<<"Alpha = "<<Alpha<<"\n";

  Alpha -= Beta; // Alpha = Alpha - Beta;
  cout<<"Alpha = "<<Alpha<<"\n";

  Alpha *= Beta; // Alpha = Alpha * Beta;
  cout<<"Alpha = "<<Alpha<<"\n";

  Alpha /= Beta; // Alpha = Alpha / Beta;
  cout<<"Alpha = "<<Alpha<<"\n";

  Alpha %= Beta; //Alpha = Alpha % Beta;
  cout<<"Alpha = "<<Alpha<<endl;
  
  return 0;
}
