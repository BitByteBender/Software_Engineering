#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  bool X{false}, Y{true};
  cout<<"Assign to 'X' 1 or 0: ";
  cin>>X;

  cout<<"Assign to 'Y' 1 or 0: ";
  cin>>Y;

  cout<<"X:"<<X<<" && Y:"<<Y<<"--> "<<(X && Y)<<"\n";
  cout<<"X:"<<X<<" || Y:"<<Y<<"--> "<<(X || Y)<<"\n";
  cout<<"!(X:"<<X<<" && Y:"<<Y<<")--> "<<!(X && Y)<<"\n";
  cout<<"!(X:"<<X<<" || Y:"<<Y<<")--> "<<!(X || Y)<<"\n";
    
  return 0;
}
