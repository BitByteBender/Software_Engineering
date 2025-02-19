#include <iostream>
#include <cstdint>
#include <cmath>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

class clsToken
{
private:
  string _TKName, _TKSym, _TKAdr;
  long long _TKSupply;

  string _InitAdrHexa()
  {
    return ("0x" + GetTKAdr());
  }
  
public:
  clsToken()
  {
  }
  
  clsToken(string Name, string Sym, string Adr, long long Supply)
  {
    this->_TKName = Name;
    this->_TKSym = Sym;
    this->_TKAdr = Adr;
    this->_TKSupply = Supply;
  }

  void SetTKName(const char *TKName)
  {
    this->_TKName = TKName;
  }

  string GetTKName()
  {
    return (this->_TKName);
  }

  void SetTKSym(const char *TKSym)
  {
    this->_TKSym = TKSym;
  }

  string GetTKSym()
  {
    return (this->_TKSym);
  }

  void SetTKAdr(const char *TKAdr)
  {
    this->_TKAdr = TKAdr;
  }

  string GetTKAdr()
  {
    return (this->_TKAdr);
  }

  void SetTKSupply(long long TKSupply)
  {
    this->_TKSupply = TKSupply;
  }

  long long GetTKSupply()
  {
    return (this->_TKSupply);
  }
  
  void PrintTokenData(const char *Style)
  {
    cout<<Style<<'\n';
    cout<<" | Token Name         :> "<<this->GetTKName()<<'\n'
	<<" | Token Symbol       :> "<<this->GetTKSym()<<'\n'
	<<" | Token Address      :> "<<this->_InitAdrHexa()<<'\n'
	<<" | Token Total Supply :> "<<this->GetTKSupply()<<'\n'
	<<"-----------------------------------------"<<endl;
  }
};

int main(void)
{
  clsToken Tk1("Amamiya", "AMY", "777A589RYTGG", (3 * pow(10, 7))), Tk2;
  Tk1.PrintTokenData("---[Token (1) Data]--------------------------");

  cout<<endl;

  Tk1.SetTKName("York");
  Tk1.SetTKSym("YRK");
  Tk1.SetTKAdr("777B589RYTGT");
  Tk2 = Tk1;
  Tk2.PrintTokenData("---[Token (2) Data]--------------------------");
  return (0);
}
