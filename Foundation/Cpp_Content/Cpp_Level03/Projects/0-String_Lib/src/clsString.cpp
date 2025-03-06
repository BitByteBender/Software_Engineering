#include "../headers/clsString.hpp"

const char *clsString::m_Global_Value = nullptr;

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

void clsString::setGValue(const char *Val)
{
  m_Global_Value = Val;
}

const char *clsString::getGValue()
{
  return (m_Global_Value);
}

uint16_t clsString::FindPos(const char *DELIM)
{
  uint16_t pos = 0, i = 0, j = 0;
  const char *Val = clsString::getGValue();
  
  while (j < strlen(DELIM) && i < strlen(Val)) {
    cout<<"i: "<<i<<" | pos: "<<pos
	<<" | j: "<<j<<" | Delim length: "<<strlen(DELIM)
	<<" | Val length: "<<strlen(Val)<<" | Val: "<<Val[i]<<" | Delim: "<<DELIM[j]<<'\n';


    
    if (Val[i] == DELIM[j]) {
      j++;
    } else {
      pos += 1 + j;
      j = 0;
      if (Val[i] == DELIM[j]) j++, pos -= 1;
    }

    i++;
  }
  
  return (pos);
}


const char *clsString::Substr(uint16_t From, uint16_t To)
{
  uint16_t i = 0, len = (To - From);
  char *_Buffer = (char *)malloc(sizeof(len + 1) * sizeof(char));
  
  for (; i < len; ++i) {
    _Buffer[i] = clsString::getGValue()[From + i];
  }

  _Buffer[len] = '\0';
  return (_Buffer);
}

vector <string> clsString::GetWords(const char *Val, const char *DELIM)
{
  vector <string> vWords;
  /*
    string strContainter = Val;
  short pos = string(strContainter).find(DELIM);
  
  while (pos > 0) {
    vWords.push_back(strContainter.substr(0, pos));
    strContainter.erase(0, pos + string(DELIM).length());
    pos = strContainter.find(DELIM);
  }

  if (!strContainter.empty()) vWords.push_back(strContainter);
  */
  clsString::setGValue(Val);
  string strContainer = clsString::getGValue();
  short pos = FindPos(DELIM);

  while (pos >= 0) {
    vWords.push_back(clsString::Substr(0, pos));
    clsString::setGValue(strContainer.erase(0, pos + string(DELIM).length()).c_str());
    strContainer = clsString::getGValue();
    pos = FindPos(DELIM);

    if (strContainer.empty())
      break;
  }

  return (vWords);
}

vector <string> clsString::GetWords(const char *DELIM) const
{
  return (GetWords(m_Value, DELIM));
}
