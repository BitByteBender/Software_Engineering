#include "../headers/clsutil.hpp"

void clsUtil::Srand()
{
  srand(unsigned(time(nullptr)));
}

uint16_t clsUtil::RandomNumber(uint16_t From, uint16_t To)
{
  return (rand() % (To - From + 1) + From);
}

char clsUtil::GetRandomCharacter(enCharType Choice)
{
  char RandomChoice;
  
  switch (Choice) {
  case (SmallLetter):
    RandomChoice = char(RandomNumber(97, 122));
    break;
  case (CapitalLetter):
    RandomChoice = char(RandomNumber(65, 91));
    break;
  case (Digit):
    RandomChoice = char(RandomNumber(48, 57));
    break;
  case (MixedChars):
    RandomChoice = char(RandomNumber(33, 122));
    break;
  case (SpecialChars):
    RandomChoice = char(RandomNumber(33, 47));
    break;
  };

  return (RandomChoice);
}

string clsUtil::GenerateWord(enCharType Choice, uint16_t Length)
{
  string strContainer = "";
  uint16_t i = 0;
  
  for (; i < Length; ++i) strContainer += clsUtil::GetRandomCharacter(Choice);

  return (strContainer);
}

string clsUtil::GenerateKey(enCharType Choice)
{
  string strContainer = "";
  uint16_t i = 0;
  
  for (; i <= 3; ++i) {
    strContainer += GenerateWord(Choice, 4);
    if (i < 3) strContainer += '-';
  }
  
  return (strContainer);
}

void clsUtil::GenerateKeys(uint16_t KeyAmount, enCharType Choice)
{
  uint16_t i = 1;

  for (; i <= KeyAmount; ++i) {
    cout<<GenerateKey(Choice);
    (i == KeyAmount) ? cout<<endl : cout<<'\n';
  }
}

void clsUtil::Swap(uint16_t &ValX, uint16_t &ValY)
{
  uint16_t Temp = ValX;
  ValX = ValY;
  ValY = Temp;
}

void clsUtil::Swap(string &ValX, string &ValY)
{
  string Temp = ValX;
  ValX = ValY;
  ValY = Temp;
}

void clsUtil::Swap(char &ValX, char &ValY)
{
  char Temp = ValX;
  ValX = ValY;
  ValY = Temp;
}

void clsUtil::Swap(float &ValX, float &ValY)
{
  float Temp = ValX;
  ValX = ValY;
  ValY = Temp;
}

void clsUtil::Swap(double &ValX, double &ValY)
{
  double Temp = ValX;
  ValX = ValY;
  ValY = Temp;
}

void clsUtil::Swap(clsDate &Date1, clsDate &Date2)
{
  clsDate Temp = Date1;
  Date1 = Date2;
  Date2 = Temp;
}

void clsUtil::ShuffleArray(uint16_t Arr[], uint16_t Length)
{
  uint16_t i = 0, j = 0, temp = RandomNumber(0, (Length - 1));;
  //string ValueTracker = to_string(temp));
  uint16_t tempArr[Length] = {};
  tempArr[0] = Arr[temp];
  
  while (i < (Length - 1)) {
    if (tempArr[j] != Arr[temp]) {
      if (i == j) {
	i++, j = 0;
	tempArr[i] = Arr[temp];
	//ValueTracker += to_string(temp);
	temp = RandomNumber(0, (Length - 1));
      } else j++;
    } else {
      temp = RandomNumber(0, (Length - 1));
      j = 0;
    }
  }

  i = 0;
  while (Length >= 1) {
    Arr[i] = tempArr[i];
    ++i, --Length;
  }
}

void clsUtil::ShuffleArray(string Arr[], uint16_t Length)
{
  uint16_t i = 0, j = 0, temp = RandomNumber(0, (Length - 1));;
  //string ValueTracker = to_string(temp));
  string tempArr[Length] = {};
  tempArr[0] = Arr[temp];
  
  while (i < (Length - 1)) {
    if (tempArr[j] != Arr[temp]) {
      if (i == j) {
	i++, j = 0;
	tempArr[i] = Arr[temp];
	//ValueTracker += to_string(temp);
	temp = RandomNumber(0, (Length - 1));
      } else j++;
    } else {
      temp = RandomNumber(0, (Length - 1));
      j = 0;
    }
  }

  i = 0;
  while (Length >= 1) {
    Arr[i] = tempArr[i];
    ++i, --Length;
  }
}
/*
void clsUtil::FillArrayWithRandomNums(uint16_t Arr[], uint16_t Length)
{
  uint16_t i = 0;
  for (; i < Length; ++i) Arr[i] = RandomNumber(0, 100);
}
*/
void clsUtil::FillArrayWithRandomNums(uint16_t Arr[], uint16_t Length, uint16_t From, uint16_t To)
{
  uint16_t i = 0;
  for (; i < Length; ++i) Arr[i] = RandomNumber(From, To);
}

void clsUtil::FillArrayWithRandomWords(string Arr[], uint16_t Length, enCharType Choice, uint16_t WordLen)
{
  uint16_t i = 0;
  for (; i < Length; ++i) Arr[i] = GenerateWord(Choice, WordLen);
}

void clsUtil::FillArrayWithRandomKeys(string Arr[], uint16_t Length, enCharType Choice)
{
  uint16_t i = 0;
  for (; i < Length; ++i) Arr[i] = GenerateKey(Choice);
}

string clsUtil::Spaces(uint16_t Space)
{
  uint16_t i = 0;
  string Spacer = "";
  
  for (; i < Space; ++i) {
    Spacer += ' ';
  }

  return (Spacer);
}

string clsUtil::Tabs(uint16_t Tab)
{
  return (Spaces(Tab * 7));
}

string clsUtil::EncryptText(string Text, const short &Key)
{
  uint16_t i = 0;
  
  for (; i <= (Text.length() - 1); ++i) Text[i] = char(uint16_t(Text[i]) + Key);

  return (Text);
}

string clsUtil::DecryptText(string Text, const short &Key)
{
  return (EncryptText(EncryptText(Text, Key), (Key * -1)));
}

string clsUtil::SmartSpacer(string Line, short Spacing)
{
  short i = 0, len = Spacing - Line.length();
  string Cnt = Line;
  
  while (i < len) {
    Cnt += ' ';
    ++i;
  }

  return (Cnt);
}

string clsUtil::SmartSplit(string Line, string Separator)
{
  short Pos = Line.find(Separator);
  string NewLine = "";
  
  while (Pos != string::npos) {
    NewLine += "| " + SmartSpacer(Line.substr(0, Pos), 30);
    Line.erase(0, Pos + Separator.length());
    Pos = Line.find(Separator);
  }
  
  if (Line != "") NewLine += "|" + Line;
  
  return (NewLine);
}
