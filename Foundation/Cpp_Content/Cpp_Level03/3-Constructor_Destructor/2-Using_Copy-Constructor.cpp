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

  void SetFirstname(string Fn)
  {
    _Firstname = Fn;
  }

  string GetFirstname()
  {
    return (_Firstname);
  }

  void SetLastname(string Ln)
  {
    _Lastname = Ln;
  }

  string GetLastname()
  {
    return (_Lastname);
  }

  void SetAge(uint16_t Age)
  {
    _Age = Age;
  }

  uint16_t GetAge()
  {
    return (_Age);
  }
  
  clsPerson(clsPerson &Prs)
  {
    _Firstname = Prs._Firstname;
    _Lastname = Prs._Lastname;
    _Age = Prs._Age;
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

  cout<<'\n';
  
  Prs1.SetFirstname("Souf");
  Prs1.SetLastname("Sdg");
  Prs1.SetAge(30);
  Prs1.GetFullname();
  Prs1.Print();
  
  clsPerson Prs2(Prs1);
  Prs2.GetFullname();
  Prs2.Print();
  
  return (0);
}
