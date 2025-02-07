#include <iostream>

using std::cout;
using std::endl;
using std::string;

class clsPerson
{
public:
  string Firstname;
  string Lastname;

  string Fullname()
  {
    return (Firstname + ' ' + Lastname);
  }

  void Print()
  {
    cout<<"This is the Fullname: "<<Fullname()<<endl;
  }
};

int main(void)
{
  clsPerson P1;

  P1.Firstname = "Ahmed";
  P1.Lastname = "Zain";
  P1.Print();
  
  return (0);
}

