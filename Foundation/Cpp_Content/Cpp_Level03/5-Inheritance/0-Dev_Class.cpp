#include <iostream>
#include <cstdint>
#include <string>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::setw;

class clsPerson
{
private:
  uint16_t _ID = 0;
  string _Firstname, _Lastname;
  string _Phone, _Email;

public:
  clsPerson(uint16_t ID, string Firstname, string Lastname, string Phone, string Email)
  {
    _ID = ID;
    _Firstname = Firstname;
    _Lastname = Lastname;
    _Phone = Phone;
    _Email = Email;
  }

  uint16_t GetID()
  {
    return (_ID);
  }

  void SetFirstname(string Firstname)
  {
    _Firstname = Firstname;
  }

  string GetFirstName()
  {
    return (_Firstname);
  }

  void SetLastname(string Lastname)
  {
    _Lastname = Lastname;
  }

  string GetLastName()
  {
    return (_Lastname);
  }

  void SetPhone(string Phone)
  {
    _Phone = Phone;
  }

  string GetPhone()
  {
    return (_Phone);
  }

  void SetEmail(string Email)
  {
    _Email = Email;
  }

  string GetEmail()
  {
    return (_Email);
  }
  
  string GetFullname()
  {
    return (_Firstname + ' ' + _Lastname);
  }

  void Print(bool Trigger=true)
  {
    cout<<"Info:\n"
	<<"______________________________"
	<<"\nID"<<setw(10)<<": "<<_ID
	<<"\nFirstname"<<setw(3)<<": "<<_Firstname
	<<"\nLastname"<<setw(4)<<": "<<_Lastname
	<<"\nFullname"<<setw(4)<<": "<<GetFullname()
	<<"\nEmail"<<setw(7)<<": "<<_Email
	<<"\nPhone"<<setw(7)<<": "<<_Phone;

    if (Trigger) cout<<"\n______________________________\n"<<endl;
  }

  void SendEmail(string Subject, string Body)
  {
    cout<<"\nThe following Email message has been sent successfully to: "<<_Email<<'\n';
    cout<<"Subject: "<<Subject<<'\n'<<"Body: "<<Body<<endl;
  }

  void SendSMS(string Content)
  {
    cout<<"\nThe following SMS message has been sent successfully to: "<<_Phone<<'\n';
    cout<<Content<<endl;
  }
};

class clsEmployee : public clsPerson
{
private:
  string _Title, _Department;
  double _Salary;

public:
  clsEmployee(uint16_t ID, string Firstname, string Lastname, string Email, string Phone, string Title, string Department, double Salary)
    : clsPerson(ID, Firstname, Lastname, Email, Phone)
  {
    _Title = Title;
    _Department = Department;
    _Salary = Salary;
  }

  void SetTitle(string Title)
  {
    _Title = Title;
  }

  string GetTitle()
  {
    return (_Title);
  }

  void SetDepartment(string Department)
  {
    _Department = Department;
  }

  string GetDepartment()
  {
    return (_Department);
  }

  void SetSalary(double Salary)
  {
    _Salary = Salary;
  }

  double GetSalary()
  {
    return (_Salary);
  }

  void Print(bool Trigger=true)
  {
    clsPerson::Print(false);
    cout<<"\nTitle"<<setw(7)<<": "<<_Title
	<<"\nDepartment"<<setw(2)<<": "<<_Department
	<<"\nSalary"<<setw(6)<<": "<<_Salary;
    if (Trigger) cout<<"\n______________________________\n"<<endl;
  }
};

class clsDeveloper : public clsEmployee
{
private:
  string _MainProgrammingLanguage = "C++";

public:
  clsDeveloper(uint16_t ID, string Firstname, string Lastname, string Email, string Phone, string Title, string Department, double Salary, string MPL)
    : clsEmployee(ID, Firstname, Lastname, Email, Phone, Title, Department, Salary)
  {
    _MainProgrammingLanguage = MPL;
  }

  void SetMPL(string MPL)
  {
    _MainProgrammingLanguage = MPL;
  }

  string GetMPL()
  {
    return (_MainProgrammingLanguage);
  }

  void Print()
  {
    clsEmployee::Print(false);
    cout<<"\nMpl"<<setw(9)<<": "<<_MainProgrammingLanguage
	<<"\n______________________________\n"<<endl;
  }
};
  
int main(void)
{
  clsPerson Prs1(999, "Malak", "Sdg", "malak@gmail.com", "+74532166699");
  Prs1.Print();
  Prs1.SendEmail("Hey", "This is person!");
  Prs1.SendSMS("Person class content");

  cout<<'\n';
  
  clsEmployee Emp1((Prs1.GetID() + 1), "Namrood", "Mario", "nam@google.com", "+159682347", "SWE", "IT", 2354.54);
  Emp1.Print();
  Emp1.SendEmail("Hello", "This is employee!");
  Emp1.SendSMS("Employee class content");

  cout<<'\n';
  
  clsDeveloper Dev1((Emp1.GetID() + 3), "Bruno", "Snicker", "brn@gml.com", "+8745885", "BE", "IT", 4785.45, "Python");
  Dev1.Print();
  Dev1.SendEmail("Hey-yo!", "This is developer!");
  Dev1.SendSMS("Developer class content");

  cout<<endl;
  return (0);
}
