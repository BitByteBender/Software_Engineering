#ifndef CLSPERSON_HPP
#define CLSPERSON_HPP

#include "clsutil.hpp"
#include "clsinputvalidate.hpp"

class clsPerson
{
private:
  string m_Firstname = "", m_Lastname = "";
  string m_Email = "", m_PhoneNumber = "";

public:
  clsPerson(string Firstname, string Lastname, string Email, string Phonenum);

  void SetFirstname(string Firstname);
  string GetFirstname() const;

  void SetLastname(string Lastname);
  string GetLastname() const;

  void SetEmail(string Email);
  string GetEmail() const;

  void SetPhonenum(string Phonenum);
  string GetPhonenum() const;

  string GetFullname() const;
};
#endif /* CLSPERSON_HPP */
