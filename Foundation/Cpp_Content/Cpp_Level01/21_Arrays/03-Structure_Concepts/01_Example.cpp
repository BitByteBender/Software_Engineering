#include <iostream>

using std::cout;
using std::endl;
using std::string;

struct strHumanData{
  string Name{"Empty"};
  unsigned short Age{0};
  string City{"Empty"}, Country{"Empty"}, Planet{"Empty"};
};

void PrintHumanData(strHumanData Human[4]){
  
  cout<<"Name: "<<Human[0].Name<<"\n"
      <<"Age: "<<Human[0].Age<<"\n"
      <<"City: "<<Human[0].City<<"\n"
      <<"Country: "<<Human[0].Country<<"\n"
      <<"Planet: "<<Human[0].Planet<<"\n\n";

  cout<<"Name: "<<Human[1].Name<<"\n"
      <<"Age: "<<Human[1].Age<<"\n"
      <<"City: "<<Human[1].City<<"\n"
      <<"Country: "<<Human[1].Country<<"\n"
      <<"Planet: "<<Human[1].Planet<<"\n\n";

  cout<<"Name: "<<Human[2].Name<<"\n"
      <<"Age: "<<Human[2].Age<<"\n"
      <<"City: "<<Human[2].City<<"\n"
      <<"Country: "<<Human[2].Country<<"\n"
      <<"Planet: "<<Human[2].Planet<<"\n\n";
  
  cout<<"Name: "<<Human[3].Name<<"\n"
      <<"Age: "<<Human[3].Age<<"\n"
      <<"City: "<<Human[3].City<<"\n"
      <<"Country: "<<Human[3].Country<<"\n"
      <<"Planet: "<<Human[3].Planet<<endl;
}

int main()
{
  strHumanData HumanData[4];
  
  HumanData[0].Name = "Soufiane Sadg";
  HumanData[0].Age = 56;
  HumanData[0].City = "M01";
  HumanData[0].Country = "Mars01-M999";
  HumanData[0].Planet = "Mars";
  
  HumanData[1].Name = "Carl Birk";
  HumanData[1].Age = 29;
  HumanData[1].City = "Johannesburg";
  HumanData[1].Country = "South Africa";
  HumanData[1].Planet = "Earth";

  HumanData[2].Name = "Oussama Atif";
  HumanData[2].Age = 34;
  HumanData[2].City = "Temara";
  HumanData[2].Country = "Morocco";
  HumanData[2].Planet = "Earth";
  
  HumanData[3].Name = "Cleveland Ataafi";
  HumanData[3].Age = 28;
  HumanData[3].Country = "Ghana";
  HumanData[3].Planet = "Earth02";
  
  PrintHumanData(HumanData);
  return 0;
}
