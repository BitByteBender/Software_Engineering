#include <iostream>

using std::cout;
using std::endl;
using std::string;

class clsPerson
{
private:
  string _Firstname;
  string _Lastname;

  void SetNames(string Firstname, string Lastname)
  {
    _Firstname = Firstname;
    _Lastname = Lastname;
  }

  string Fullname()
  {
    SetNames("Zorro", "Roronoa");
    return (_Firstname + ' ' + _Lastname);
  }
  
public:

  void Print()
  {
    cout<<"This is the Fullname: "<<Fullname()<<endl;
  }
};

int main(void)
{
  clsPerson P1;

  P1.Print();
  
  return (0);
}
