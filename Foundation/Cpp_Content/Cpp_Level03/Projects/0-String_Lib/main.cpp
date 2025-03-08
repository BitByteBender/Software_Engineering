#include "headers/clsString.hpp"

int main(void)
{
  clsString str1, str2("This is good!"), str3;

  str1.setValue("Hello it's me");

  cout<<str1.getValue()<<'\n';
  cout<<str2.getValue()<<'\n';

  cout<<"Str1 WordsCounter: "<<str1.CountWords()<<'\n';
  cout<<"Str2 WordsCounter: "<<str2.CountWords(str2.getValue())<<'\n';
  cout<<"Str2 WordsCounter: "<<str2.CountWords("Hello World")<<'\n';

  for (const char *v:str1.GetWords("i, Guardium Laviosa!!, RtrX!,!!, #!,# !,", "!, ")) {
    cout<<v<<'\n';
  }
  
  
  /*clsString::setGValue("Hello world!");
  cout<<"GVal: "<<clsString::getGValue()<<'\n';
  cout<<"GVal Pos: "<<clsString::FindPos(" ")<<'\n';
  */
  //cout<<"Substr: "<<clsString::Substr(2, 5)<<'\n';
  for (const char *v:str1.GetWords("i#!# * t## * re y## * Gm La##! * Rt## *!", "## * ")) {
    cout<<v<<'\n';
    }/*

  str3.setGValue("This is ju test!");
  cout<<"Str3 length: "<<strlen(str3.getGValue())<<'\n';
  cout<<"Str3 Before: "<<str3.getGValue()<<'\n';
  str3.setGValue(clsString::Erase(0, 5));
  cout<<"Str3 After[0, 5]: "<<str3.getGValue()<<'\n';

  str3.setGValue("This is ju test!");
  cout<<"Str3 length: "<<strlen(str3.getGValue())<<'\n';
  cout<<"Str3 Before: "<<str3.getGValue()<<'\n';
  str3.setGValue(clsString::Erase(3, 4));
  cout<<"Str3 After[3, 4]: "<<str3.getGValue()<<'\n';

  str3.setGValue("This is ju test!");
  cout<<"Str3 length: "<<strlen(str3.getGValue())<<'\n';
  cout<<"Str3 Before: "<<str3.getGValue()<<'\n';
  str3.setGValue(clsString::Erase(2, 4));
  cout<<"Str3 After[2, 4]: "<<str3.getGValue()<<'\n';*/

  cout<<str3.toUpper("rambo, tHE bLuE #gReEk")<<'\n';
  cout<<str3.toLower("rambo tHE @bLuE 'gReEk")<<'\n';
  cout<<clsString::Strlen("Hello !")<<" | "<<strlen("Hello !")<<'\n';
  str3.setGValue("Hello !");
  cout<<str3.Strlen()<<'\n';
  return (0);
}
