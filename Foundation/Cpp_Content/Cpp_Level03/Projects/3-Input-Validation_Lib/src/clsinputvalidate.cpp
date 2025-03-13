#include "../headers/clsinputvalidate.hpp"

bool clsInputValidate::IsNumberBetween(int Num, int From, int To)
{
  return ((Num >= From) && (Num <= To));
}

bool clsInputValidate::IsNumberBetween(double Num, double From, double To)
{
  return ((Num >= From) && (Num <= To));
}

bool clsInputValidate::IsNumberBetween(float Num, float From, float To)
{
  return ((Num >= From) && (Num <= To));
}

bool clsInputValidate::IsDateBetween(clsDate Date, clsDate From, clsDate To)
{
  bool Y, M, D;

  Y = (stoi(Date.getYear()) >= stoi(From.getYear()) && stoi(Date.getYear()) <= stoi(To.getYear()));
  M = (stoi(From.getMonth()) <= stoi(Date.getMonth()) && stoi(Date.getMonth()) <= stoi(To.getMonth()));
  D = (stoi(Date.getDay()) >= stoi(From.getDay()) && stoi(Date.getDay()) <= stoi(To.getDay()));

  return (Y && M && D);
}

int clsInputValidate::ReadIntegerNumber(const char *Msg)
{
  int Num = 0, len = 0, i = 0, Checker = 0;
  string strContainer = "";
  
  cout<<"Enter an integer: ";
  getline(cin>>ws, strContainer);
  
  do {
    len = strContainer.length();
    Checker = int(char(strContainer[i]) - 48);

    if (strContainer[i] == '-' && i == 0) {
      i++;
      continue;
    } else if (!IsNumberBetween(Checker, 0, 9)) {
      cout<<Msg<<endl;
      getline(cin>>ws, strContainer);
      i = 0;
      continue;
    }

    if (i == (len - 1)) {
      Num = stoi(strContainer);
      break;
    }
    i++;
  } while (true);

  return (Num);
}

bool clsInputValidate::NANChecker(string Str)
{
  uint16_t i = 0;
  
  for (; i < Str.length(); ++i) {
    if (Str[i] == '-' && i == 0) continue;
    else if (!IsNumberBetween(int(char(Str[i]) - 48), 0, 9)) return (false);
  }
  
  return (true);
}

int clsInputValidate::ReadIntegerNumberBetween(int From, int To, const char *Msg)
{
  string strContainer = "";
  bool Checker = true;
  
  do {
    if (Checker) {
      cout<<"Enter an integer: ";
      getline(cin>>ws, strContainer);
      Checker = false;
    }
    
    if (!NANChecker(strContainer)) {
      cout<<"["<<strContainer<<"] NAN re-";
      Checker = true;
    } else if (!IsNumberBetween(stoi(strContainer), From, To)) {
      cout<<Msg<<From<<" and "<<To<<", re-";
      Checker = true;
    }

  } while (Checker);

  return (stoi(strContainer));
}
