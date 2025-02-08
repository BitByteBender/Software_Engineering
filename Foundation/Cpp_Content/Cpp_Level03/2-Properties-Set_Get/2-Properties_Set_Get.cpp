#include <iostream>
#include <cstdint>

using std::cout;
using std::endl;
using std::string;

class clsHuman
{
private:
  uint16_t _ID = 999;
  string _Firstname, _Lastname;

public:
  void SetFirstname(string Firstname)
  {
    _Firstname = Firstname;
  }

  string GetFirstname()
  {
    return (_Firstname);
  }

  void SetLastname(string Lastname)
  {
    _Lastname = Lastname;
  }

  string GetLastname()
  {
    return (_Lastname);
  }
  
  uint16_t GetID()
  {
    return (_ID);
  }
  
  void PrintResult()
  {
    cout<<"Firstname: "<<GetFirstname()<<'\n'
	<<"Lastname: "<<GetLastname()<<'\n'
	<<"ID: "<<GetID()<<endl;
  }
};

int main(void)
{
  clsHuman Hmn1;

  Hmn1.SetFirstname("Souf");
  Hmn1.SetLastname("Sdg");
  Hmn1.PrintResult();
  
  return (0);
}
