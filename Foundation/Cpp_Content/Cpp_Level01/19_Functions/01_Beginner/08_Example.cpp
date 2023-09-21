#include <iostream>

using std::cout;
using std::endl;
using std::string;

void SquaredStars(){
  string Stars{"********\n"};
  cout<<Stars<<Stars<<Stars<<Stars<<endl;
}

int main()
{
  SquaredStars();
  return 0;
}
