#include "../headers/clsString.hpp"

const char *clsString::m_Global_Value = nullptr;
char *clsString::m_Buffer = nullptr;

clsString::clsString() : m_Value(nullptr) {}

clsString::clsString(const char *Val) : m_Value(Val) {}

void clsString::setValue(const char *Val)
{
  m_Value = Val;
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
  
  while (j < strlen(DELIM) && i <= strlen(Val)) {
    /*cout<<"i: "<<i<<" | pos: "<<pos
	<<" | j: "<<j<<" | Delim length: "<<strlen(DELIM)
	<<" | Val length: "<<strlen(Val)<<" | Val: "<<Val[i]<<" | Delim: "<<DELIM[j]<<'\n';
    */

    
    if (Val[i] == DELIM[j]) {
      j++;
    } else {
      pos += 1 + j;
      j = 0;
      if (Val[i] == DELIM[j] && Val[strlen(Val)] == DELIM[strlen(DELIM)] && Val[i + 1] != '\0') j++, pos -= 1;
    }

    i++;
  }

  return (pos);
}


const char *clsString::Substr(uint16_t From, uint16_t To)
{
  uint16_t i = 0, len = abs(To - From);
  m_Buffer = (char *)malloc(len + 1);
  
  for (; i < len; ++i) {
    m_Buffer[i] = clsString::getGValue()[From + i];
  }

  m_Buffer[len] = '\0';
  return (m_Buffer);
}

const char *clsString::Erase(uint16_t From, uint16_t To)
{
  uint16_t len = strlen(clsString::getGValue()) - abs(To - From), i = 0, j = 0;
  m_Buffer = (char*)malloc(len + 1);

  /*
  cout<<"strVal: "<<clsString::getGValue()<<'\n';
  cout<<"strLen: "<<strlen(clsString::getGValue())<<'\n';
  cout<<"size len: "<<len<<'\n';
  cout<<"size buffer: "<<sizeof(m_Buffer)<<'\n';
  */
  
  for (i = 0; i < strlen(clsString::getGValue()); ++i) {
    if (i >= From && i < To) continue;
    
    m_Buffer[j] = clsString::getGValue()[i];
    j++;

  }

  m_Buffer[len] = '\0';
  return (m_Buffer);
}

vector <const char*> clsString::GetWords(const char *Val, const char *DELIM)
{
  vector <const char*> vWords;

  clsString::setGValue(Val);
  m_Global_Value = clsString::getGValue();
  short pos = FindPos(DELIM);

  while (pos >= 0) {
    vWords.push_back(clsString::Substr(0, pos));
    m_Global_Value = clsString::Erase(0, pos + strlen(DELIM));
    clsString::setGValue(m_Global_Value);
    //cout<<"SC: "<<m_Global_Value<<" | GVal: "<<clsString::getGValue()<<'\n';
    pos = FindPos(DELIM);

    if (string(m_Global_Value).empty())
      break;
  }

  free((void*)m_Global_Value);
  return (vWords);
}

vector <const char*> clsString::GetWords(const char *DELIM) const
{
  return (GetWords(m_Value, DELIM));
}

bool clsString::isLower(char Alphabet)
{
  return (Alphabet >= 97 && Alphabet <= 122);
}

bool clsString::isUpper(char Alphabet)
{
  return (Alphabet >= 65 && Alphabet <= 90);
}

const char *clsString::toLower(const char *Word)
{
  uint16_t i = 0, len = strlen(Word);
  m_Buffer = (char*)malloc(len + 1);

  for (; i < len; i++) {
    if (isUpper(Word[i])) m_Buffer[i] = char(uint16_t(Word[i]) + 32);
    else m_Buffer[i] = Word[i];
  }
  
  return (m_Buffer);
}

const char *clsString::toUpper(const char *Word)
{
  uint16_t i = 0, len = strlen(Word);
  m_Buffer = (char*)malloc(len + 1);

  for (; i < len; i++) {
    if (isLower(Word[i])) m_Buffer[i] = char(uint16_t(Word[i]) - 32);
    else m_Buffer[i] = Word[i];
  }

  m_Buffer[len] = '\0';
  return (m_Buffer);
}

uint16_t clsString::Strlen(const char *Word)
{
  uint16_t Counter = 0;

  while (Word[Counter] != '\0') Counter++;
  
  return (Counter);
}

uint16_t clsString::Strlen()
{
  return (Strlen(m_Global_Value));
}

clsString::~clsString()
{
  
}
