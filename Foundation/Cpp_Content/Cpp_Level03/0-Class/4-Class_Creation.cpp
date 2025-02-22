#include <iostream>
#include <cstdint>
#include <string>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

class clsString
{
private:
  const char *_Str;
  static const char *_StrHolder;
  char *_Buffer;
public:
  clsString() : _Buffer(nullptr) {}

  clsString(const char *_Str)
  {
    this->_Str = _Str;
    this->_Buffer = nullptr;
  }

  void SetStr(const char *_Str)
  {
    this->_Str = _Str;
  }

  const char *GetStr()
  {
    return (this->_Str);
  }

  static void SetStrHolder(const char *Str)
  {
    _StrHolder = Str;
  }
  
  static const char *GetStrHolder()
  {
    return (_StrHolder);
  }
  
  uint16_t Len()
  {
    uint16_t Len = 0;
    
    while (this->_Str[Len] != '\0') Len++;
    
    return (Len);
  }
  
  uint16_t WordCounter(const char *_Str)
  {
    uint16_t i = 0, Counter = 0, len = string(_Str).length();

    for (; i < len; i++) {
      if (_Str[i] == ' ') Counter++;
    }

    return (Counter + 1);
  }

  uint16_t WordCounter()
  {
    const char *Str = GetStr();
    uint16_t i = 0, Counter = 0, len = string(Str).length();

    for (; i < len; i++) {
      if (Str[i] == ' ' || (i + 1) == len) Counter++;
    }

    return (Counter);
  }

  uint16_t WordCounterExt()
  {
    const char *Str = GetStr();
    uint16_t i = 0, Counter = 0;

    for (; i < Len(); i++) {
      if (Str[i] == ' ' || (i + 1) == Len()) Counter++;
    }

    return (Counter);
  }

  short FindPos(const char *Delim)
  {
    uint16_t i = 0, j = 0, Counter = 0;

    while (this->_Str[i] != '\0') {
      if (Delim[j] == _Str[i]) {
	Counter = (i - j);
	if (string(Delim).length() - 1 == j) break;
	j++;
      } else j = 0;
      i++;
    }

    return (Counter > 0 ? Counter : -1);
  }
  
  const char *Substr(short From, short To)
  {
    uint16_t len = To - From;
    if (_Buffer != nullptr) {
      delete[] _Buffer;
      _Buffer = nullptr;
    }

    _Buffer = new char[len + 1];
    
    for (uint16_t i = 0; i < To; i++) {
      _Buffer[i] = this->GetStr()[From + i];
    }

    _Buffer[len] = '\0';
    return (_Buffer);
  }

  const char *Pushback(const char *NewStr)
  {
    if (_Buffer != nullptr) {
      delete[] _Buffer;
      _Buffer = nullptr;
    }

    uint16_t i = 0, j = 0, k = 0, len = 0;

    while (true) {
      if (NewStr[len] != '\0') ++len;
      else break;
    }

    len += Len();
    _Buffer = new char[len + 1];
    
    for (;i < len; i++) {
      if (this->_Str[k] != '\0') {
        k = i + 1;
	_Buffer[i] = this->_Str[i];
      } else _Buffer[i] = NewStr[j], j++;
    }

    _Buffer[len] = '\0';
    return (_Buffer);
  }
  
  void Print()
  {
    cout<<"String Content     : "<<GetStr()<<'\n'
	<<"Count<0 Param>     : "<<WordCounter()<<'\n'
	<<"Count<1 Param>     : "<<WordCounter(GetStr())<<'\n'
	<<"Len                : "<<Len()<<'\n'
	<<"Count-Ext<0 Param> : "<<WordCounterExt()<<'\n'
	<<"Pos Finder         : "<<FindPos(" ")<<'\n'
	<<"Slice              : "<<Substr(0, FindPos(" "))<<'\n'
	<<"Pushed Back        : "<<Pushback(" True")<<endl;
  }

  ~clsString()
  {
    if (_Buffer) {
      delete[] _Buffer;
      _Buffer = nullptr;
    }
  }
};

const char *clsString::_StrHolder = nullptr;

int main(void)
{
  clsString Str1("This is a test!"), Str2;

  Str1.SetStrHolder(Str1.GetStr());
  Str1.Print();
  Str2.SetStr("Peekaboo !!!");
  Str2.SetStrHolder(Str2.GetStr());
  Str2.Print();
  Str1.Print();

  Str2.SetStr("this##is it");
  Str2.SetStrHolder(Str2.GetStr());
  cout<<Str2.FindPos("##")<<endl;

  Str2.SetStr("this##//is it");
  Str2.SetStrHolder(Str2.GetStr());
  cout<<Str2.FindPos("##//")<<endl;

  Str2.SetStr("this is it");
  Str2.SetStrHolder(Str2.GetStr());
  cout<<Str2.FindPos("##//")<<endl;
  cout<<string(Str2.GetStr()).substr(0, string(Str2.GetStr()).find("##//"))<<endl;
  cout<<string(Str2.GetStr()).substr(0, Str2.FindPos("##//"))<<endl;
    
  Str2.SetStr("this ##// is it");
  Str2.SetStrHolder(Str2.GetStr());
  cout<<Str2.FindPos("##//")<<endl;
  cout<<string(Str2.GetStr()).substr(0, string(Str2.GetStr()).find("##//"))<<endl;
  cout<<string(Str2.GetStr()).substr(0, Str2.FindPos("##//"))<<endl;

  Str2.SetStr("Lets go ##/  !! ##/  Tester");
  Str2.SetStrHolder(Str2.GetStr());
  cout<<Str2.FindPos(" ##/  ")<<endl;
  cout<<string(Str2.GetStr()).substr(1, string(Str2.GetStr()).find(" ##/  ") - 1)<<endl;
  cout<<string(Str2.GetStr()).substr(1, Str2.FindPos(" ##/  ") - 1)<<endl;
  
  return (0);
}
