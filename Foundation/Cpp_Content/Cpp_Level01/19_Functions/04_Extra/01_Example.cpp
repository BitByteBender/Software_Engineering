#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct strHiringInfos
{
  short Age{0};
  bool HasDriverLicense{false};
  
};

strHiringInfos MessageReader(){
  strHiringInfos HiringInfos;
  cout<<"Enter your age: ";
  cin>>HiringInfos.Age;

  cout<<"Do you have a driving license(0 / 1): ";
  cin>>HiringInfos.HasDriverLicense;
  return HiringInfos;
}


void OutputDecision(strHiringInfos HiringInfos){
  (HiringInfos.Age >= 19 && HiringInfos.HasDriverLicense) ? cout<<"Hired"<<endl : cout<<"Rejected"<<endl;
}

int main()
{
  OutputDecision(MessageReader());
  return 0;
}
