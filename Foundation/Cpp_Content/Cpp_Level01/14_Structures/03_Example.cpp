#include <iostream>


using std::cout;
using std::endl;
using std::string;

struct stContactDetails{
  string PhoneNum1{"+987541364"}, PhoneNum2{"+19742213"}, Email1{"example@test.com"}, Email2{"Empty"};
};

struct stAddress{
  string Adr1{"st44, NY Tower, Apt7"}, Adr2{"St49, Trump Tower, Penthouse"};
};

struct stOwner{
  string FirstName{"Soufiane"};
  string MiddleName{"Empty"};
  string LastName{"Sadgali"};
  char Gender{'M'};
  stAddress Adr;
  stContactDetails ContactDetails;
};

struct stBikeDetails{
  string Brand{"Ducati"};
  string Model{"Panigale"};
  char Category{'V'};
  unsigned short Serie{4};
  string Color{"#157896"};
  char FullOptions{'F'};
  stOwner Owner;
};

int main(){

  string PrintStars{"***************************************"};

  stBikeDetails Bike1, Bike2;
  
  cout<<PrintStars<<"\n"

      <<"Brand: "<<Bike1.Brand<<"\n"
      <<"Model: "<<Bike1.Model + " " +Bike1.Category<<Bike1.Serie<<"\n"
      <<"Color Ref: "<<Bike1.Color<<"\n"
      <<"Options: "<<Bike1.FullOptions<<"\n"
      <<"Owner: "<<Bike1.Owner.FirstName + Bike1.Owner.LastName<<"\n"
      <<"Gender: "<<Bike1.Owner.Gender<<"ale"<<"\n"
      <<"Adr: "<<Bike1.Owner.Adr.Adr1<<"\n"
      <<"Phone: "<<Bike1.Owner.ContactDetails.PhoneNum1<<"\n"
      <<"Email: "<<Bike1.Owner.ContactDetails.Email1<<"\n"

      <<PrintStars<<"\n";

  Bike2.Brand = "Yamaha";
  Bike2.Model = "Ninja";
  Bike2.Category = 'H';
  Bike2.Serie = 2;
  Bike2.Color = "#987521";
  Bike2.FullOptions = 'M';
  Bike2.Owner.FirstName = "Lara";
  Bike2.Owner.MiddleName = "Jay";
  Bike2.Owner.LastName = "olum";
  Bike2.Owner.Gender = 'F';
  Bike2.Owner.Adr.Adr1 = "New Orleans, st 108, Penthouse";
  Bike2.Owner.Adr.Adr2 = "Dubai, Bentley Mansion";
  Bike2.Owner.ContactDetails.PhoneNum1 = "+897121218";
  Bike2.Owner.ContactDetails.Email1 = "example01@cpp.org";
  Bike2.Owner.ContactDetails.Email2 = "example02@cpp.com";
  
  cout<<PrintStars<<"\n"

      <<"Brand: "<<Bike2.Brand<<"\n"
      <<"Model: "<<Bike2.Model + " " +Bike2.Category<<Bike2.Serie<<"\n"
      <<"Color Ref: "<<Bike2.Color<<"\n"
      <<"Options: "<<Bike2.FullOptions<<"\n"
      <<"Owner: "<<Bike2.Owner.FirstName + Bike2.Owner.MiddleName + Bike2.Owner.LastName<<"\n"
      <<"Gender: "<<Bike2.Owner.Gender<<"emale"<<"\n"
      <<"Adr1: "<<Bike2.Owner.Adr.Adr1<<"\n"
      <<"Adr2: "<<Bike2.Owner.Adr.Adr2<<"\n"
      <<"Phone: "<<Bike2.Owner.ContactDetails.PhoneNum1<<"\n"
      <<"Email1: "<<Bike2.Owner.ContactDetails.Email1<<"\n"
      <<"Email2: "<<Bike2.Owner.ContactDetails.Email2<<"\n"

      <<PrintStars<<endl;
  return 0;
}
