#include <iostream>

using std::cout;
using std::endl;
using std::string;

struct stAddress{
  string State{"New-York"};
  string Country{"USA"};
  string Street{"st01, Time Square, Penthouse"};
  string Phone{"+123456789"};
};

struct stPerson{
  string FirstName{"Mohammed"}, MiddleName{"Ali"}, LastName{"Blake"};
  unsigned short Age{21};
  stAddress Address;
  float MonthlySalary{2536.45f};
  char Gender{'M'};
  bool isMarried{false};
};

stPerson ReadCard(stPerson &Person, string FirstName, string MiddleName, string LastName, short Age, float Salary, string State, string Country, string Phone, string Street, char Gender, bool isMarried){
  
  Person.FirstName = FirstName;
  Person.MiddleName = MiddleName;
  Person.LastName = LastName;
  Person.Age = Age;
  Person.MonthlySalary = Salary;
  Person.Address.State = State;
  Person.Address.Country = Country;
  Person.Address.Street = Street;
  Person.Address.Phone = Phone;
  Person.Gender = Gender;
  Person.isMarried = isMarried;
  
  return Person;
}

float CalculateYearlySalary(stPerson Person){
  //stPerson Person;
  return Person.MonthlySalary * 12.0f;
}

void DisplayCard(stPerson Person){
  string Card{"***************************"};

  cout<<Card<<"\n";

  cout<<"Name: "<<Person.FirstName + " " + Person.MiddleName + " " + Person.LastName<<"\n";
  cout<<"Age: "<<Person.Age<<"\n";
  cout<<"City: "<<Person.Address.State<<"\n";
  cout<<"Country: "<<Person.Address.Country<<"\n";
  cout<<"Street: "<<Person.Address.Street<<"\n";
  cout<<"Phone: "<<Person.Address.Phone<<"\n";
  cout<<"Monthly Salary: "<<Person.MonthlySalary<<"\n";
  cout<<"Yearly Salary: "<<CalculateYearlySalary(Person)<<"\n";
  cout<<"Gender: "<<Person.Gender<<"\n";
  cout<<"Marital Status: "<<Person.isMarried<<"\n";
  
  cout<<Card<<endl;
}

int main()
{
  stPerson Person1, Person2;
  DisplayCard(Person1);

  ReadCard(Person2, "Sou", "Sad", "Gali", 15, 7500.30f, "Marbella", "Spain", "St01, Malibu", "+9871237",'M', 1);
  DisplayCard(Person2);
  return 0;
}

