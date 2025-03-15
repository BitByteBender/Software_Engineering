#include "../headers/clsperson.hpp"

clsPerson::clsPerson(string Firstname, string Lastname, string Email, string Phonenum)
  : m_Firstname(Firstname), m_Lastname(Lastname), m_Email(Email), m_PhoneNumber(Phonenum) {}

void clsPerson::SetFirstname(string Firstname)
{
  m_Firstname = Firstname;
}

string clsPerson::GetFirstname() const
{
  return (m_Firstname);
}

void clsPerson::SetLastname(string Lastname)
{
  m_Lastname = Lastname;
}

string clsPerson::GetLastname() const
{
  return (m_Lastname);
}

void clsPerson::SetEmail(string Email)
{
  m_Email = Email;
}

string clsPerson::GetEmail() const
{
  return (m_Email);
}

void clsPerson::SetPhonenum(string Phonenum)
{
  m_PhoneNumber = Phonenum;
}

string clsPerson::GetPhonenum() const
{
  return (m_PhoneNumber);
}

string clsPerson::GetFullname() const
{
  return (m_Firstname + ' ' + m_Lastname);
}
