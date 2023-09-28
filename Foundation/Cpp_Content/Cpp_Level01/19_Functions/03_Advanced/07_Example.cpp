#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

struct stPersonInfo{
  string Fullname{"Empty"};
  unsigned short Age{0};
  string City{"Empty"}, Country{"Empty"};
  float MonthlySalary;
  char Gender{'M'};
  bool isMarried{false};
};

void ReadPersonData(stPersonInfo& PersonData, string Message){
  cout<<Message + "full name: ";
  cin.ignore(1, '\n');
  getline(cin, PersonData.Fullname);

  cout<<Message + "Age: ";
  
  cin>>PersonData.Age;

  cout<<Message + "City: ";
  cin>>PersonData.City;

  cout<<Message + "Country: ";
  cin.ignore(1, '\n');
  getline(cin, PersonData.Country);

  cout<<Message + "MonthlySalary: ";
  cin>>PersonData.MonthlySalary;

  cout<<Message + "Gender: ";
  cin>>PersonData.Gender;

  cout<<"Are you married?(0 Or 1) ";
  cin>>PersonData.isMarried;
}

void PrintPersonData(stPersonInfo PersonData, string CardStyle){
  cout<<CardStyle<<"\n";

  cout<<"Name: "<<PersonData.Fullname<<"\n"
      <<"Age: "<<PersonData.Age<<"\n"
      <<"City: "<<PersonData.City<<"\n"
      <<"Country: "<<PersonData.Country<<"\n"
      <<"MonthlySalary: "<<PersonData.MonthlySalary<<"\n"
      <<"YearlySalary: "<<(PersonData.MonthlySalary * 12.0f)<<"\n"
      <<"Gender: "<<PersonData.Gender<<"\n"
      <<"Married: "<<PersonData.isMarried<<"\n";
  
  cout<<CardStyle<<endl;
}

int main()
{
  stPersonInfo PersonData1, PersonData2;
  ReadPersonData(PersonData1, "Enter your ");
  PrintPersonData(PersonData1, "*******************************");

  
  ReadPersonData(PersonData2, "Please enter your ");
  PrintPersonData(PersonData2, "///////////////////****\\\\\\\\\\\\\\\\\\\\");
  return 0;
}
