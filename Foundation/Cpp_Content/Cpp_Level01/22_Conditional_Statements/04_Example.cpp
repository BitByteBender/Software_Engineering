#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned short Age{0};

  cout<<"How old are you?\n";
  cin>>Age;

  if (Age>=18 && Age<=34) {
    cout<<"Valid Age"<<endl;
  }else{
    cout<<"Invalid Age"<<endl;
  }
  
  return 0;
}
