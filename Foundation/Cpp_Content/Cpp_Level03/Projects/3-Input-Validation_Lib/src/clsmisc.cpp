#include "../headers/clsmisc.hpp"

clsMisc::clsMisc() : m_Value(" ") {}
clsMisc::clsMisc(string Val) : m_Value(Val) {}

void clsMisc::setVal(string Val)
{
  this->m_Value = Val;
}

string clsMisc::getVal() const
{
  return (m_Value);
}

vector<uint16_t> clsMisc::Split(string Val, string Delim)
{
  vector<uint16_t> vFormat;
  short pos = 0;
  
  while ((pos = Val.find(Delim)) != string::npos) {
    vFormat.push_back(stoi(Val.substr(0, pos)));
    Val.erase(0, pos + Delim.length());
  }

  if (!Val.empty()) vFormat.push_back(stoi(Val.substr(0, pos)));
  return (vFormat);
}

vector<uint16_t> clsMisc::Split(string Delim)
{
  return (Split(m_Value, Delim));
}

vector<string> clsMisc::DelimFinder(string Val)
{
  vector<string> vDelims;
  string strContainer = "";
  uint16_t i = 0;
  
  while (Val[i] != '\0') {
    if ((short(char(Val[i])) - 48) >= 0) {
      if (!strContainer.empty())
	vDelims.push_back(strContainer), strContainer.clear();
    } else strContainer += Val[i];
    i++;
  }
 
  return (vDelims);
}

vector<uint16_t> clsMisc::SplitAdv(string Val)
{
  vector<uint16_t> vFormat;
  vector<string> vDelims = clsMisc::DelimFinder(Val);
  
  short i = 0, pos = 0;
  
  while ((pos = Val.find(vDelims[i])) != string::npos) {
    vFormat.push_back(stoi(Val.substr(0, pos)));
    Val.erase(0, pos + vDelims[i].length());
    i++;
    if (Val.empty() || i >= 2) break;
  }

  if (!Val.empty()) vFormat.push_back(stoi(Val));
  return (vFormat);
}

vector<uint16_t> clsMisc::SplitAdv() const
{
  return (SplitAdv(m_Value));
}
