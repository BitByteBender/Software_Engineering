#include "../headers/clsString.hpp"

void clsString::setValue(const char *Val)
{
  this->m_Value = Val;
}

const char *clsString::getValue() const
{
  return (this->m_Value);
}

uint16_t clsString::CountWords(const char *Val)
{
  uint16_t Counter = 0, i = 0;

  while (Val[i] != '\0') {
    if (Val[i] == ' ') Counter++;
    i++;
  }

  return (Counter + 1);
}

uint16_t clsString::CountWords() const
{
  return (CountWords(m_Value));
}
