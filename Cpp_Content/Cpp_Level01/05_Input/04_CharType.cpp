#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  string Prompt{"Enter a character? "};
  cout<<Prompt;

  char a{'a'}, b{'d'}, c{'a'}, d{'m'};
  cin>>a;
  
  Prompt = "Enter a character? ";
  cout<<Prompt;
  cin>>b;
  
  Prompt = "Enter a character? ";
  cout<<Prompt;
  cin>>c;

  Prompt = "Enter a character? ";
  cout<<Prompt;
  cin>>d;
  
  cout<<a<<b<<c<<d<<"\n";
  return 0;
}
