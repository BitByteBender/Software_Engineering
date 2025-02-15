#include <iostream>
#include <cstdint>

using std::cout;
using std::endl;
using std::string;

class clsClient
{
private:
  class clsAdrInfo
  {
  private:
    string _Country, _City;
    string _Address;
    string _Phone;

  public:
    clsAdrInfo()
    {
    }
    
    clsAdrInfo(string Country, string City, string Adr, string Phone)
    {
      this->_Country = Country;
      this->_City = City;
      this->_Address = Adr;
      this->_Phone = Phone;
    }

    void SetCountry(string Country)
    {
      this->_Country = Country;
    }

    string GetCountry()
    {
      return (_Country);
    }

    void SetCity(string City)
    {
      this->_City = City;
    }

    string GetCity()
    {
      return (_City);
    }

    void SetAdr(string Adr)
    {
      this->_Address = Adr;
    }

    string GetAdr()
    {
      return (_Address);
    }

    void SetPhone(string Phone)
    {
      this->_Phone = Phone;
    }

    string GetPhone()
    {
      return (_Phone);
    }
  };
  
private:
  string _AccAdr;
  string _Firstname, _Lastname;
  uint16_t _Age;
  clsAdrInfo _Adr;
  double _Balance;

public:
  clsClient(string AccAdr, string Fn, string Ln, uint16_t Age, double Bl, string Adr, string Country, string City, string Phone)
  { 
    _AccAdr = AccAdr;
    _Firstname = Fn;
    _Lastname = Ln;
    _Age = Age;
    this->_Adr = clsAdrInfo(Country, City, Adr, Phone);
    _Balance = Bl;
  }

  void Print()
  {
    cout<<_Adr.GetCity()<<endl;
  }
};

int main(void)
{
  clsClient Cl("A000", "Ahmed", "Hajji", 18, 985.33, "St404, 10001", "Morocco", "Casablanca", "+98765999");

  Cl.Print();
  return (0);
}

