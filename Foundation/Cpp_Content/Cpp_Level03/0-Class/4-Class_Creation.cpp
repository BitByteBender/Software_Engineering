#include <iostream>
#include <cstdint>
#include <string>

using std::cout;
using std::endl;
using std::string;

class clsString
{
private:
  const char *_Str;

public:
  clsString() {}

  clsString(const char *_Str)
  {
    this->_Str = _Str;
  }

  void SetStr(const char *_Str)
  {
    this->_Str = _Str;
  }

  const char *GetStr()
  {
    return (this->_Str);
  }

  uint16_t Len()
  {
    uint16_t Len = 0;

    while (this->_Str[Len] != '\0') {
      Len++;
    }
    
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
    uint16_t i = 0, len = To - From;
    char *Slice = new char[len + 1];
    
    for (i = From; i < To; i++) {
      Slice[i] = this->GetStr()[i];
    }

    Slice[len] = '\0';
    return (Slice);
  }
 
  void Print()
  {
    cout<<"String Content     : "<<GetStr()<<'\n'
	<<"Count<0 Param>     : "<<WordCounter()<<'\n'
	<<"Count<1 Param>     : "<<WordCounter(GetStr())<<'\n'
	<<"Len                : "<<Len()<<'\n'
	<<"Count-Ext<0 Param> : "<<WordCounterExt()<<'\n'
	<<"Pos Finder         : "<<FindPos(" ")<<'\n'
	<<"Slice              : "<<Substr(0, FindPos(" "))<<'\n'<<endl;
  }
};

int main(void)
{
  clsString Str1("This is a test!"), Str2;

  Str1.Print();
  Str2.SetStr("Peekaboo !!!");
  Str2.Print();
  Str1.Print();

  Str2.SetStr("this##is it");
  cout<<Str2.FindPos("##")<<endl;

  Str2.SetStr("this##//is it");
  cout<<Str2.FindPos("##//")<<endl;

  Str2.SetStr("this is it");
  cout<<Str2.FindPos("##//")<<endl;
  cout<<string(Str2.GetStr()).substr(0, string(Str2.GetStr()).find("##//"))<<endl;
  cout<<string(Str2.GetStr()).substr(0, Str2.FindPos("##//"))<<endl;
    
  Str2.SetStr("this ##// is it");
  cout<<Str2.FindPos("##//")<<endl;
  cout<<string(Str2.GetStr()).substr(0, string(Str2.GetStr()).find("##//"))<<endl;
  cout<<string(Str2.GetStr()).substr(0, Str2.FindPos("##//"))<<endl;
  
  return (0);
}
