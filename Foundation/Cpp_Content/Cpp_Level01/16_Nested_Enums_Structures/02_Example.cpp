#include <iostream>

using std::cout;
using std::endl;
using std::string;


enum enGender{ Male = 0, Female = 1};
enum enMaritalStatus{ Single, Married, Divorced, Widowed};

struct stContactDetails
{
  string Address{"Empty"}, POBox{"Empty"}, Phone{"Empty"};
};

struct stHumanData{
  string Firstname{"Empty"}, Middlename{"Empty"}, Lastname{"Empty"};
  unsigned short Age{0};
  string Country{"Empty"}, City{"Empty"};
  stContactDetails ContactDetails;
  enGender Gender;
  enMaritalStatus MaritalStatus;
};

int main()
{
  stHumanData HumanData1, HumanData2;

  cout<<"*****************************"<<"\n";
  cout<<"Firstname: "<<HumanData1.Firstname<<"\n";
  cout<<"Middlename: "<<HumanData1.Middlename<<"\n";
  cout<<"Lastname: "<<HumanData1.Lastname<<"\n";
  cout<<"Age: "<<HumanData1.Age<<"\n";
  cout<<"Country: "<<HumanData1.Country<<"\n";
  cout<<"City: "<<HumanData1.City<<"\n";
  cout<<"Address: "<<HumanData1.ContactDetails.Address<<"\n";
  cout<<"POBox: "<<HumanData1.ContactDetails.POBox<<"\n";
  cout<<"Phone: "<<HumanData1.ContactDetails.Phone<<"\n";
  cout<<"Gender: "<<(HumanData1.Gender = enGender::Male)<<"\n";
  cout<<"MaritalStatus: "<<(HumanData1.MaritalStatus = enMaritalStatus::Widowed)<<"\n";
  cout<<"*****************************"<<"\n";

  HumanData2.Firstname = "Jack";
  HumanData2.Middlename = "Pirate";
  HumanData2.Lastname = "Sparrow";
  HumanData2.Age = 57;
  HumanData2.Country = "Sea";
  HumanData2.City = "Atlantis";
  HumanData2.ContactDetails.Address = "DeepSea, Shell N1001";
  HumanData2.ContactDetails.POBox = "8752222973";
  HumanData2.ContactDetails.Phone = "+987522234";
  HumanData2.Gender = enGender::Male;
  HumanData2.MaritalStatus = enMaritalStatus::Single;
  
  cout<<"*****************************"<<"\n";
  cout<<"Firstname: "<<HumanData2.Firstname<<"\n";
  cout<<"Middlename: "<<HumanData2.Middlename<<"\n";
  cout<<"Lastname: "<<HumanData2.Lastname<<"\n";
  cout<<"Age: "<<HumanData2.Age<<"\n";
  cout<<"Country: "<<HumanData2.Country<<"\n";
  cout<<"City: "<<HumanData2.City<<"\n";
  cout<<"Address: "<<HumanData2.ContactDetails.Address<<"\n";
  cout<<"POBox: "<<HumanData2.ContactDetails.POBox<<"\n";
  cout<<"Phone: "<<HumanData2.ContactDetails.Phone<<"\n";
  cout<<"Gender: "<<HumanData2.Gender<<"\n";
  cout<<"MaritalStatus: "<<HumanData2.MaritalStatus<<"\n";
  cout<<"*****************************"<<endl;
  
  return 0;
}
