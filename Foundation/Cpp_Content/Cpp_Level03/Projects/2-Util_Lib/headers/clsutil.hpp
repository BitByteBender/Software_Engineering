#ifndef CLSUTIL_HPP
#define CLSUTIL_HPP

#include "clsdate.hpp"
#include <iostream>
#include <cstdint>
#include <string.h>
#include <cmath>
#include <ctime>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

class clsUtil
{
public:
  enum enCharType
  {
    SmallLetter = 1,
    CapitalLetter = 2,
    Digit =3,
    MixedChars = 4,
    SpecialChars = 5,
  };
  
  static void Srand();
  static uint16_t RandomNumber(uint16_t Num1, uint16_t Num2);
  static char GetRandomCharacter(enCharType Choice);
  static string GenerateWord(enCharType Choice, uint16_t Length);
  static string GenerateKey(enCharType Choice);
  static void GenerateKeys(uint16_t KeyAmount, enCharType Choice);
  static void Swap(uint16_t &ValX, uint16_t &ValY);
  static void Swap(string &ValX, string &ValY);
  static void Swap(char &ValX, char &ValY);
  static void Swap(float &ValX, float &ValY);
  static void Swap(double &ValX, double &ValY);
  static void Swap(clsDate &Date1, clsDate &Date2);
  static void ShuffleArray(uint16_t Arr[], uint16_t Length);
  static void ShuffleArray(string Arr[], uint16_t Length);
  //static void FillArrayWithRandomNums(uint16_t Arr[], uint16_t Length);
  static void FillArrayWithRandomNums(uint16_t Arr[], uint16_t Length, uint16_t From=0, uint16_t To=100);
  static void FillArrayWithRandomWords(string Arr[], uint16_t Length, enCharType Choice, uint16_t WordLen);
  static void FillArrayWithRandomKeys(string Arr[], uint16_t Length, enCharType Choice);
  static string Spaces(uint16_t Space);
  static string Tabs(uint16_t Tab);
  static string EncryptText(string Text, const short &Key);
  static string DecryptText(string Text, const short &Key);
};

#endif /* CLSUTIL_HPP */
