#ifndef CLSSTRING_H
#define CLSSTRING_H

#include <iostream>
#include <cstdint>
#include <vector>
#include <cstdlib>
#include <string.h>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class clsString
{
private:
  const char *m_Value = nullptr;
  static const char *m_Global_Value;
  
public:
  clsString() : m_Value(nullptr) {}
  clsString(const char *Val) : m_Value(Val) {}

  void setValue(const char *Val);
  const char *getValue() const;

  static void setGValue(const char *Val);
  static const char *getGValue();
  static uint16_t CountWords(const char *Val);
  uint16_t CountWords() const;

  static uint16_t FindPos(const char *DELIM);
  static const char *Substr(uint16_t From, uint16_t To);
  static const char *Erase(uint16_t From, uint16_t To);
  
  static vector <string> GetWords(const char *Val, const char *DELIM);
  vector <string> GetWords(const char *DELIM) const;
};
#endif /* CLSSTRING_H */
