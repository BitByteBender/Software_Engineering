#include <iostream>

using std::cout;
using std::endl;
using std::string;

enum enGender{Male = 1, Female = 2};
enum enMaritalStatus {Single, Married, Divorced, Widowed};
enum enBrand{ PalmerJhonson, Pershing, Azimut, Riva, Sunseeker, Ferretti, Oceanco, BlackPearl};

struct stPersonInfo{
  string FirstName{"Empty"}, MiddleName{"Empty"}, LastName{"Empty"};
  unsigned short Age{0};
  string City{"Empty"}, Country{"Empty"};
  float MonthlySalary{0.00f}, YearlySalary{MonthlySalary * 12.00f};
  enGender Gender;
  enMaritalStatus MaritalStatus;
  enBrand Yacht;
};


int main()
{
  stPersonInfo Person1, Person2, Person3;
  string PrintStars{"**************************"};
  
  
  cout<<PrintStars<<"\n"
      <<"Fullname: "<<Person1.FirstName + " " + Person1.LastName<<"\n"
      <<"Age: "<<Person1.Age<<"\n"
      <<"City: "<<Person1.City<<"\n"
      <<"Country: "<<Person1.Country<<"\n"
      <<"MonthlySalary: "<<Person1.MonthlySalary<<"\n"
      <<"YearlySalary: "<<Person1.YearlySalary<<"\n"
      <<"Gender: "<<(Person1.Gender = enGender::Male)<<"\n"
      <<"MaritalStatus: "<<(Person1.MaritalStatus = enMaritalStatus::Single)<<"\n"
      <<"Yacht Owned: "<<(Person1.Yacht = enBrand::Azimut)<<"\n"
      <<PrintStars<<"\n";

  Person2.FirstName = "Michael";
  Person2.MiddleName = "Empty";
  Person2.LastName = "Saylor";
  Person2.Age = 54;
  Person2.Country = "United States Of America";
  Person2.City = "California";
  Person2.MonthlySalary = 100000;
  Person2.YearlySalary = Person2.MonthlySalary * 12.0f;
  Person2.Gender = enGender::Male;
  Person2.MaritalStatus = enMaritalStatus::Married;
  Person2.Yacht = enBrand::PalmerJhonson;


  cout<<PrintStars<<"\n"
      <<"Fullname: "<<Person2.FirstName + " " + Person2.LastName<<"\n"
      <<"Age: "<<Person2.Age<<"\n"
      <<"City: "<<Person2.City<<"\n"
      <<"Country: "<<Person2.Country<<"\n"
      <<"MonthlySalary: "<<Person2.MonthlySalary<<"\n"
      <<"YearlySalary: "<<Person2.YearlySalary<<"\n"
      <<"Gender: "<<Person2.Gender<<"\n"
      <<"MaritalStatus: "<<Person2.MaritalStatus<<"\n"
      <<"Yacht Owned: "<<Person2.Yacht<<"\n"
      <<PrintStars<<"\n";

  Person3.FirstName = "Luffy";
  Person3.MiddleName = "D.";
  Person3.LastName = "Monkey";
  Person3.Age = 19;
  Person3.City = "Tokyo";
  Person3.Country = "Japan";
  Person3.MonthlySalary = 1010000;
  Person3.YearlySalary = Person2.MonthlySalary * 12.0f;
  Person3.Gender = enGender::Male;
  Person3.MaritalStatus = enMaritalStatus::Single;
  Person3.Yacht = enBrand::BlackPearl;

  cout<<PrintStars<<"\n"
      <<"Fullname: "<<Person3.LastName + " " + Person3.MiddleName + " " + Person3.FirstName<<"\n"
      <<"Age: "<<Person3.Age<<"\n"
      <<"City: "<<Person3.City<<"\n"
      <<"Country: "<<Person3.Country<<"\n"
      <<"MonthlySalary: "<<Person3.MonthlySalary<<"\n"
      <<"YearlySalary: "<<Person3.YearlySalary<<"\n"
      <<"Gender: "<<Person3.Gender<<"\n"
      <<"MaritalStatus: "<<Person3.MaritalStatus<<"\n"
      <<"Yacht Owned: "<<Person3.Yacht<<"\n"
      <<PrintStars<<endl;
    
  return 0;
}
