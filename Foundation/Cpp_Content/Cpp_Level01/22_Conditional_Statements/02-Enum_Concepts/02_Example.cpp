#include <iostream>

using std::cout;
using std::cin;
using std::endl;

enum enYacht{Riva = 1, Pershing = 2, SunSeeker = 3};
enum enOwner{Soufiane = 200, Issam = 300, Oussama = 400, Zak = 450};

int main()
{
  enYacht Yacht1, Yacht2, Yacht3;
  enOwner Owner;

  short YachtChecker{0}, OwnerChecker{0};

  Yacht1 = enYacht::Riva;
  Yacht2 = enYacht::Pershing;
  Yacht3 = enYacht::SunSeeker;
  
  cout<<"Enter yacht number1: ";
  cin>>YachtChecker;

  cout<<"Enter owner: ";
  cin>>OwnerChecker;

  if (YachtChecker == 1 && OwnerChecker == 1) {
    cout<<"Yacht: "<<enYacht::Riva<<"<----->"<<Yacht1<<"\n";
    cout<<"Owner: "<<enOwner::Soufiane<<endl;
  }else if(YachtChecker == 2 && OwnerChecker == 2){
    cout<<"Yacht: "<<enYacht::Pershing<<"<----->"<<Yacht2<<"\n";
    cout<<"OWner: "<<enOwner::Zak<<"\n";
  }else if(YachtChecker == 3 && OwnerChecker == 3){
    cout<<"Yacht: "<<enYacht::SunSeeker<<"<------->"<<Yacht3<<"\n";
    cout<<"Owner: "<<enOwner::Oussama<<endl;
  }else{
    cout<<"Yacht: "<<enYacht::SunSeeker<<"\n";
    cout<<"Owner: "<<enOwner::Issam<<endl;
  }
  
  return 0;
}
