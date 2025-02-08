#include <iostream>
#include <cstdint>

using std::cout;
using std::endl;
using std::string;

class clsHuman
{
private:
  uint16_t _ID = 21;
  string _Firstname = "Sung", _Lastname = "Jinwoo";

public:
  uint16_t GetID()
  {
    return (_ID);
  }

  string GetFirstname()
  {
    return (_Firstname);
  }

  string GetLastname()
  {
    return (_Lastname);
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

  Hmn1.PrintResult();
  
  return (0);
}
