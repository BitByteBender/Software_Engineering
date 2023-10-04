#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void ReadData(unsigned short& Age, bool& HasDriverLicense){
  cout<<"Enter your age: ";
  cin>>Age;

  cout<<"Do you have a driver license(Enter 1=True Or 0=False)? ";
  cin>>HasDriverLicense;
}

bool Checker(unsigned short Age, bool HasDriverLicense){
  return Age>19 && HasDriverLicense;
}

std::string CheckResult(unsigned short Age, bool HasDriverLicense){
  if (Checker(Age, HasDriverLicense)){
    return "Hired\n";
  }else{
    return "Rejected\n";
  }
}

void PrintResult(unsigned short Age, bool HasDriverLicense){
  cout<<"Result: "<<CheckResult(Age, HasDriverLicense);
}

int main()
{
  unsigned short Age{0};
  bool HasDriverLicense{false};

  ReadData(Age, HasDriverLicense);
  PrintResult(Age, HasDriverLicense);
  return 0;
}
