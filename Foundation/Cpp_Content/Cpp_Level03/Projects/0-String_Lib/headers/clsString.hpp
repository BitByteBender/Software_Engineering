#ifndef CLSSTRING_H
#define CLSSTRING_H

#include <iostream>
#include <cstdint>

using std::cout;
using std::endl;
using std::string;

class clsString
{
private:
  const char *m_Value = nullptr;

public:
  clsString() : m_Value(nullptr) {}
  clsString(const char *Val) : m_Value(Val) {}

  void setValue(const char *Val);
  const char *getValue() const;

  static uint16_t CountWords(const char *Val);
  uint16_t CountWords() const;
};

#endif /* CLSSTRING_H */
