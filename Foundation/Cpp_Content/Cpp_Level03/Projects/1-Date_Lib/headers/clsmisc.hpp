#ifndef CLSSTR_H
#define CLSSTR_H

#include <iostream>
#include <string.h>
#include <vector>
#include <cstdint>
#include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::to_string;
using std::stoi;

class clsMisc
{
private:
  string m_Value;
  
public:
  clsMisc();
  clsMisc(string Val);

  void setVal(string Val);
  string getVal() const;
  
  static vector<uint16_t> Split(string Val, string Delim);
  vector<uint16_t> Split(string Delim);

  static vector<string> DelimFinder(string Val);
  static vector<uint16_t> SplitAdv(string Val);
  vector<uint16_t> SplitAdv() const;
};

#endif /* CLSSTR_H */
