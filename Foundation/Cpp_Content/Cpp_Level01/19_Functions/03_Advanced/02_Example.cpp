#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int Salary(float MonthlySalary, short Months){
 
  return float(Months * MonthlySalary);
}

void infos(){
  
  string Card{"*******************************\n"}, FirstName{"Soufiane"}, LastName{"Sadgali"};
  short Age{59};
  string Country{"UAE"}, City{"Dubai"};
  float MonthlySalary{7500.59f}, YearlySalary{float(Salary(MonthlySalary, 12))};
  char Gender{'M'};
  bool isMarried{false};

  cout<<Card
      <<"Fullname: "<<FirstName + " " + LastName<<"\n"
      <<"Age: "<<Age<<"\n"
      <<"Country: "<<Country<<"\n"
      <<"City: "<<City<<"\n"
      <<"MonthlySalary: $"<<MonthlySalary<<"\n"
      <<"YearlySalary: $"<<YearlySalary<<"\n"
      <<"Gender: "<<Gender<<"\n"
      <<"Married: "<<isMarried<<"\n"
      <<Card;
  cout<<endl;
}

int main()
{
  infos();
  return 0;
}
