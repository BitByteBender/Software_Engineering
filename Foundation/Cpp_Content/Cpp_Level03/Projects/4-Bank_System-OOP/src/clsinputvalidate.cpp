
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
  return (clsDate::IsDateBetween(Date, From, To));
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
  uint16_t i = 0, count = 0;
  
  for (; i < Str.length(); ++i) {
    if (Str[i] == '-' && i == 0) continue;
    
    if (Str[i] == '.' && count == 0) {
      count++;
    } else if (!IsNumberBetween(int(char(Str[i]) - 48), 0, 9)) return (false);
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

double clsInputValidate::ReadDblNumber(const char *Msg)
{
  string strContainer = "";
  bool Checker = true;
  
  do {
    if (Checker) {
      cout<<Msg;
      getline(cin>>ws, strContainer);
      Checker = false;
    }
    
    if (!NANChecker(strContainer)) {
      cout<<"["<<strContainer<<"] Not a number, re-";
      Msg = clsString::toLower(Msg);
      Checker = true;
    }

  } while (Checker);

  return (stod(strContainer));
}

double clsInputValidate::ReadDblNumberBetween(double From, double To, const char *Msg)
{
  string strContainer = "";
  bool Checker = true;
  
  do {
    if (Checker) {
      cout<<"Enter a double: ";
      getline(cin>>ws, strContainer);
      Checker = false;
    }
    
    if (!NANChecker(strContainer)) {
      cout<<"["<<strContainer<<"] NAN re-";
      Checker = true;
    } else if (!IsNumberBetween(stod(strContainer), From, To)) {
      cout<<Msg<<From<<" and "<<To<<", re-";
      Checker = true;
    }

  } while (Checker);

  return (stod(strContainer));
}

int clsInputValidate::ReadIntegerNumber(string Msg)
{
  int Num = 0;
  cout<<"Enter an integer number: ";
  
  while (!(cin>>Num)) {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<Msg;
  }
  
  return (Num);
}

bool clsInputValidate::IsValidDate(clsDate Date)
{
  return (clsDate::IsValid(&Date));
}

double clsInputValidate::ReadDoubleNumber(const char *Msg)
{
  double Num = 0;
  string msg = "Number should be in this format [155.521 or 155], ";
  string Lower = string(clsString::toLower(Msg));
  
  cout<<Msg;
  cin>>Num;
  
  while (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<msg + "re-" + Lower;
    cin>>Num;
  }
  
  return (Num);
}

string clsInputValidate::ReadString(const char *Msg)
{
  string StrInput = "";
  
  cout<<Msg;
  getline(cin>>ws, StrInput);
  
  return (StrInput);
}
/*
#include "../headers/clsinputvalidate.hpp"

template <class T>
T clsInputValidate<T>::IsNumberBetween(T Num, T From, T To)
{
  return ((Num >= From) && (Num <= To));
}

template <class T>
T clsInputValidate<T>::IsDateBetween(T Date, T From, T To)
{
  return (T::IsDateBetween(Date, From, To));
}

template <class T>
T clsInputValidate<T>::ReadIntegerNumber(T *Msg)
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

template <class T>
T clsInputValidate<T>::NANChecker(T Str)
{
  uint16_t i = 0, count = 0;
  
  for (; i < Str.length(); ++i) {
    if (Str[i] == '-' && i == 0) continue;
    
    if (Str[i] == '.' && count == 0) {
      count++;
    } else if (!IsNumberBetween(int(char(Str[i]) - 48), 0, 9)) return (false);
  }
  
  return (true);
}

template <class T>
T clsInputValidate<T>::ReadIntegerNumberBetween(T From, T To, T *Msg)
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

template <class T>
T clsInputValidate<T>::ReadDblNumber(const char *Msg)
{
  string strContainer = "";
  bool Checker = true;
  
  do {
    if (Checker) {
      cout<<Msg;
      getline(cin>>ws, strContainer);
      Checker = false;
    }
    
    if (!NANChecker(strContainer)) {
      cout<<"["<<strContainer<<"] Not a number, re-";
      Msg = clsString::toLower(Msg);
      Checker = true;
    }

  } while (Checker);

  return (stod(strContainer));
}

template <class T>
T clsInputValidate<T>::ReadDblNumberBetween(T From, T To, T *Msg)
{
  string strContainer = "";
  bool Checker = true;
  
  do {
    if (Checker) {
      cout<<"Enter a double: ";
      getline(cin>>ws, strContainer);
      Checker = false;
    }
    
    if (!NANChecker(strContainer)) {
      cout<<"["<<strContainer<<"] NAN re-";
      Checker = true;
    } else if (!IsNumberBetween(stod(strContainer), From, To)) {
      cout<<Msg<<From<<" and "<<To<<", re-";
      Checker = true;
    }

  } while (Checker);

  return (stod(strContainer));
}

template <class T>
T clsInputValidate<T>::ReadIntegerNumber(T Msg)
{
  int Num = 0;
  cout<<"Enter an integer number: ";
  
  while (!(cin>>Num)) {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<Msg;
  }
  
  return (Num);
}

template <class T>
T clsInputValidate<T>::IsValidDate(T Date)
{
  return (clsDate::IsValid(&Date));
}

template <class T>
T clsInputValidate<T>::ReadDoubleNumber(T *Msg)
{
  double Num = 0;
  string msg = "Number should be in this format [155.521 or 155], ";
  string Lower = string(clsString::toLower(Msg));
  
  cout<<Msg;
  cin>>Num;
  
  while (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<msg + "re-" + Lower;
    cin>>Num;
  }
  
  return (Num);
}

template <class T>
T clsInputValidate<T>::ReadString(T *Msg)
{
  string StrInput = "";

  cout<<Msg;
  getline(cin>>ws, StrInput);
  
  return (StrInput);
}

*/


/*
bool clsInputValidate::IsValid()
{
  char Checker = ReadString("Are you sure you want to update this record (Y/N)?: ")[0];
  return (Checker == 'Y' || Checker == 'y');
}

clsBankClient clsInputValidate::ReadObj(string AccNum, bool Trigger)
{
  clsBankClient Client;

  if (Trigger) {
    // Read Accnum
    while (Client.GetAccountNumber() == AccNum) {
      // Implementation {Randomization or Incrementor}
    }
  }
  Client.m_AccountNumber = AccNum;
  
  Client.SetPincode(ReadString("Enter a Pincode: "));
  Client.SetBalance(ReadDblNumber("Enter a Balance: "));
  Client.SetFirstname(ReadString("Enter a Firstname: "));
  Client.SetLastname(ReadString("Enter a Lastname: "));
  Client.SetEmail(ReadString("Enter an Email: "));
  Client.SetPhonenum(ReadString("Enter a Phone number: "));
  
  return (Client);
}
*/
