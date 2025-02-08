#include <iostream>
#include <cstdint>

using std::cout;
using std::endl;
using std::string;

class clsHuman
{
private:
  uint16_t _ID = 15;
  string _Firstname, _Lastname;

public:
  void SetFirstname(string Firstname)
  {
    _Firstname = Firstname;
  }

  void SetLastname(string Lastname)
  {
    _Lastname = Lastname;
  }

  void PrintResult()
  {
    cout<<"Firstname: "<<_Firstname<<'\n'
	<<"Lastname: "<<_Lastname<<'\n'
	<<"ID: "<<_ID<<endl;
  }
};

int main(void)
{
  clsHuman Hmn1;

  Hmn1.SetFirstname("Ichigo");
  Hmn1.SetLastname("kurosaki");
  Hmn1.PrintResult();
  
  return (0);
}
