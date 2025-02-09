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
  clsPerson()
  {
    _Firstname = "Killua";
    _Lastname = "Zoldyk";
    _Age = 14;
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
  clsPerson Prs1;

  Prs1.GetFullname();
  Prs1.Print();
  return (0);
}
