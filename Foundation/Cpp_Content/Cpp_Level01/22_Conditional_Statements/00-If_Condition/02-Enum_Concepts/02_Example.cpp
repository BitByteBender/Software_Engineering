#include <iostream>

using std::cout;
using std::cin;
using std::endl;

enum enYacht{Riva = 1, Pershing = 2, SunSeeker = 3};
enum enOwner{Soufiane = 200, Issam = 300, Oussama = 400, Zak = 450};

int main()
{
  enYacht Yacht;
  enOwner Owner;
  short YachtChecker{0}, OwnerChecker{0};
  
  cout<<"Enter yacht number1: ";
  cin>>YachtChecker;

  cout<<"Enter owner: ";
  cin>>OwnerChecker;

  Yacht = (enYacht) YachtChecker;
  Owner = (enOwner) OwnerChecker;
  

  if (Yacht == enYacht::Riva && Owner == enOwner::Soufiane) {
    cout<<"Yacht: "<<"Riva"<<"\n";
    cout<<"Owner: "<<"Soufiane"<<endl;
  }else if(Yacht == enYacht::Pershing && Owner == enOwner::Zak){
    cout<<"Yacht: "<<"Pershing"<<"\n";
    cout<<"OWner: "<<"Zak"<<"\n";
  }else if(Yacht == enYacht::SunSeeker && Owner == enOwner::Oussama){
    cout<<"Yacht: "<<"Sunseeker"<<"\n";
    cout<<"Owner: "<<"Oussama"<<endl;
  }else{
    cout<<"Yacht: "<<"Sunseeker"<<"\n";
    cout<<"Owner: "<<"Issam"<<endl;
  }
  
  return 0;
}
