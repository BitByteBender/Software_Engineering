#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
  unsigned short Age{0};
  bool HasDriverLicense{false};

  cout<<"How old are you?\n";
  cin>>Age;

  cout<<"Do you have driver license(Enter false=0 or true=1)?\n";
  cin>>HasDriverLicense;

  if (Age>21 && HasDriverLicense) {
    cout<<"Hired"<<endl;
  }else{
    cout<<"Rejected"<<endl;
  }
  
  return 0;
}
