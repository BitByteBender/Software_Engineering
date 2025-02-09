#include <iostream>
#include <cstdint>

using std::cout, std::endl;
using std::string;

class clsPerson
{
private:
  string _Firstname, _Lastname;
  uint16_t _Age;

public:
  clsPerson(string Firstname, string Lastname, uint16_t Age)
  {
    _Firstname = Firstname;
    _Lastname = Lastname;
    _Age = Age;
  }

  string GetFullname()
  {
    return (_Firstname + ' ' + _Lastname);
  }

  void Print()
  {
    cout<<"Card Info:\n"
	<<"_________________________\n";
    cout<<"Firstname : "<<_Firstname<<'\n'
	<<"Lastname  : "<<_Lastname<<'\n'
	<<"Fullname  : "<<GetFullname()<<'\n'
	<<"Age       : "<<_Age<<'\n'
	<<"__________________________\n"<<endl;
  }
};

int main(void)
{
  clsPerson Prs1("Ahmed", "Ranko", 35);

  Prs1.GetFullname();
  Prs1.Print();
  return (0);
}
