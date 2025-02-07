#include <iostream>
#include <cstdint>

using std::cout;
using std::endl;
using std::string;

class clsPerson
{
protected:
  uint16_t Age;
  string Firstname;
  string Lastname;

  void SetAttrs(string Fn, string Ln, uint16_t A)
  {
    Age = A;
    Firstname = Fn;
    Lastname = Ln;
  }

  
public:
  void Print()
  {
    SetAttrs("Zorro", "Roronoa", 155);
    cout<<"This is the Fullname: "<<Firstname + ' ' + Lastname<<'\n';
    cout<<"This is the Age: "<<Age<<endl;
  }
};

int main(void)
{
  clsPerson P1;

  P1.Print();
  
  return (0);
}
