#include <iostream>

using std::cout;
using std::endl;
using std::string;

enum enGender{Male, Female};
enum enMaritalStatus{Single = 1, Married = 2, Divorced = 3, Widowed = 4};

struct strContactDetails{
  string FirstAddress{"st404, 195"},
    SecondAddress{"st405, 196"},
    Phone{"+1098752142"};
};

struct strSchoolInfo{
  string Name{"Holberton"};
  unsigned short StudentID{99}, FoundingYear{2015};
  float StudentScore{99.52f};
  strContactDetails SchoolContactDetails;
  unsigned short Ranking{1};
};

struct strPersonInfo{
  string FirstName{"Soufiane"}, MiddleName{"Empty"}, LastName{"Stallon"};
  unsigned short Age{15};
  string Country{"SouthAfrica"};
  string City{"CapeTown"};
  strContactDetails PersonContactDetails;
  strSchoolInfo School;
  enGender Gender = enGender::Male;
  enMaritalStatus MaritalStatus = enMaritalStatus::Single;
};

int main()
{
  strPersonInfo Person01, Person02;

  string PrintStars{"***************************"};

  cout<<PrintStars<<"\n"
      <<"First name: "<<Person01.FirstName<<"\n"
      <<"Last name: "<<Person01.LastName<<"\n"
      <<"Age: "<<Person01.Age<<"\n"
      <<"Country: "<<Person01.Country<<"\n"
      <<"City: "<<Person01.City<<"\n"
      <<"Gender: "<<Person01.Gender<<"\n"
      <<"MaritalStatus: "<<Person01.MaritalStatus<<"\n"
      <<"Student Phone: "<<Person01.PersonContactDetails.Phone<<"\n"
      <<"Student Address: "<<Person01.PersonContactDetails.SecondAddress<<"\n"
      <<"School Name: "<<Person01.School.Name<<"\n"
      <<"Founded In: "<<Person01.School.FoundingYear<<"\n"
      <<"StudentID: "<<Person01.School.StudentID<<"\n"
      <<"Student Score: "<<Person01.School.StudentScore<<"%\n"
      <<"School Ranking: "<<Person01.School.Ranking<<"\n"
      <<"School Phone: "<<(Person01.School.SchoolContactDetails.Phone = "+987115454")<<"\n"
      <<"School Address: "<<(Person01.School.SchoolContactDetails.FirstAddress = "Silicon Valley")<<"\n"
      <<PrintStars<<"\n";



   
  Person02.FirstName = "Huda";
  Person02.MiddleName = "Rockey";
  Person02.LastName = "Shwan";
  Person02.Age = 45;
  Person02.Country = "USA";
  Person02.City = "Oklahoma";
  Person02.Gender = enGender::Female;
  Person02.MaritalStatus = enMaritalStatus::Married;
  Person02.PersonContactDetails.Phone = "+78221854";
  Person02.PersonContactDetails.SecondAddress = "Apt85, Stage 9";
  Person02.School.Name = "Harvard";
  Person02.School.FoundingYear = 1636;
  Person02.School.StudentID = 74;
  Person02.School.StudentScore = 87.65;
  Person02.School.Ranking = 11;
  Person02.School.SchoolContactDetails.Phone = "+387114454";
  Person02.School.SchoolContactDetails.FirstAddress = "Silverado valley";

   cout<<PrintStars<<"\n"
      <<"First name: "<<Person02.FirstName<<"\n"
       <<"Middle name: "<<Person02.MiddleName<<"\n"
      <<"Last name: "<<Person02.LastName<<"\n"
      <<"Age: "<<Person02.Age<<"\n"
      <<"Country: "<<Person02.Country<<"\n"
      <<"City: "<<Person02.City<<"\n"
      <<"Gender: "<<Person02.Gender<<"\n"
      <<"MaritalStatus: "<<Person02.MaritalStatus<<"\n"
      <<"Student Phone: "<<Person02.PersonContactDetails.Phone<<"\n"
      <<"Student Address: "<<Person02.PersonContactDetails.SecondAddress<<"\n"
      <<"School Name: "<<Person02.School.Name<<"\n"
      <<"Founded In: "<<Person02.School.FoundingYear<<"\n"
      <<"StudentID: "<<Person02.School.StudentID<<"\n"
      <<"Student Score: "<<Person02.School.StudentScore<<"%\n"
      <<"School Ranking: "<<Person02.School.Ranking<<"\n"
      <<"School Phone: "<<Person02.School.SchoolContactDetails.Phone<<"\n"
      <<"School Address: "<<Person02.School.SchoolContactDetails.FirstAddress<<"\n"
       <<PrintStars<<endl;
      
    
  return 0;
}
