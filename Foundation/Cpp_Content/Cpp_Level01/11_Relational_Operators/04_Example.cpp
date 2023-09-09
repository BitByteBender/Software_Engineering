#include <iostream>

using std::cout;
using std::endl;

int main()
{
  short X{0}, Z{0};

  std::string Phrase{"Please enter number "};

  cout<<Phrase + " X: ";
  std::cin>>X;

  cout<<Phrase + " Z: ";
  std::cin>>Z;

  cout<<"X == Z => "<<(X == Z)<<"\n";
  cout<<"X != Z => "<<(X != Z)<<"\n";
  cout<<"X < Z => "<<(X < Z)<<"\n";
  cout<<"X > Z => "<<(X > Z)<<"\n";
  cout<<"X <= Z => "<<(X <= Z)<<"\n";
  cout<<"X >= Z => "<<(X >= Z)<<endl;
  
  return 0;
}
