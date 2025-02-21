#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>

using std::endl;
using std::cout, std::cin;
using std::string;

class clsString
{
private:
  const char* _Str;

public:
  clsString()
  {
  }


  clsString(const char* _Str)
  {
    this->_Str = _Str;
  }

  //clsString(const char* Str) : _Str(Str) {}
  
  void SetStr(const char* Str)
  {
    this->_Str = Str;
  }

  const char* GetStr()
  {
    return (_Str);
  }

  void Print()
  {
    cout<<"Content: "<<GetStr()<<endl;
  }
};

class clsMisc : private clsString
{
public:
  clsMisc(const char* Str = "") : clsString(Str) {}
  
  uint16_t WordCounter()
  {
    uint16_t i = 0, Counter = 0, Len = string(GetStr()).length();
    
    for (i = 0; i < Len; ++i) {
      if (string(GetStr())[i] == ' ') Counter++;
    }
    
    return (Counter + 1);
  }

  uint16_t WordCounter(const char *Word)
  {
    uint16_t i = 0, Counter = 0, Len = string(Word).length();

    for (i = 0; i < Len; ++i) {
      if (string(Word)[i] == ' ' || (i + 1) == Len) Counter++;
    }
    
    return (Counter);
  }

  void Print()
  {
    cout<<"Misc Content: "<<(string(GetStr()).empty() ? "(empty)" : GetStr())<<endl;
  }
};
  
string ReadData(const char* Str)
{
  string Input;

  cout<<Str;
  getline(cin>>std::ws, Input);
  
  return (Input);
}

int main(void)
{
  string PromptStr = ReadData("Enter a content: ");
  clsString Str1(PromptStr.c_str());

  Str1.Print();
  cout<<string(string(Str1.GetStr()))<<endl;
  cout<<PromptStr.length()<<'\n'<<string(Str1.GetStr()).length()<<endl;
  
  clsMisc M1("This is really amazing!"), M2, M3, M4;
  cout<<M1.WordCounter()<<endl;
  cout<<M2.WordCounter(Str1.GetStr())<<endl;
  Str1.Print();
  
  PromptStr = ReadData("Enter a new content: ");
  Str1.SetStr(PromptStr.c_str());
  cout<<M3.WordCounter()<<endl;
  cout<<M4.WordCounter(Str1.GetStr())<<endl;
  M1.Print();
  M2.Print();
  Str1.Print();
  M3.Print();
  M4.Print();
  
  return (0);
}
