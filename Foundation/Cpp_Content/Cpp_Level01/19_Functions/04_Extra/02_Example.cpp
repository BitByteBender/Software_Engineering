#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

short ReadNumber(string Message){
  
  short Number{0};

  cout<<Message;
  cin>>Number;

  return Number;
  
}

string CheckInfos(short Age, bool HasDriverLicense, bool HasRecommendation){
  
  if (HasRecommendation) {
    return "Hired";
  }else{
    if(Age >= 20 && HasDriverLicense){
      return "Hired";
    }else{
      return "Rejected";
    }
  }

}

void PrintDecision(short Age, bool HasDriverLicense, bool HasRecommendation){
  cout<<"You have been "<<CheckInfos(Age, HasDriverLicense, HasRecommendation)<<endl;
}

int main()
{
  short Age = ReadNumber("Enter your Age: ");
  bool HasDriverLicense = ReadNumber("Do you have a driver license(0/1): ");
  bool HasRecommendation = ReadNumber("Do you have any recommendations(0/1): ");

  PrintDecision(Age, HasDriverLicense, HasRecommendation);
  return 0;
}
