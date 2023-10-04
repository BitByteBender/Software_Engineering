#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned short Mark{0};

  cout<<"Enter your mark: ";
  cin>>Mark;

  if (Mark>=85) {
    cout<<"Pass"<<endl;
  }else{
    cout<<"Fail!"<<endl;
  }
  
  return 0;
}
