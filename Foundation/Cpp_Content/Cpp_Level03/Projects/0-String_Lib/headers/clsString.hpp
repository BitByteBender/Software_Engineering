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
  static char *m_Buffer;
  static const char *m_Global_Value;
  
public:
  clsString();
  clsString(const char *Val);

  void setValue(const char *Val);
  const char *getValue() const;

  static void setGValue(const char *Val);
  static const char *getGValue();
  static uint16_t CountWords(const char *Val);
  uint16_t CountWords() const;

  static uint16_t FindPos(const char *DELIM);
  static const char *Substr(uint16_t From, uint16_t To);
  static const char *Erase(uint16_t From, uint16_t To);
  
  static vector <const char*> GetWords(const char *Val, const char *DELIM);
  vector <const char*> GetWords(const char *DELIM) const;

  bool isLower(char Alphabet);
  bool isUpper(char Alphabet);
  const char *toLower(const char *Word);
  static const char *toLower();
  const char *toUpper(const char *Word);
  static const char *toUpper();

  static uint16_t Strlen(const char *Word);
  uint16_t Strlen();
  
  ~clsString();
};
#endif /* CLSSTRING_H */
