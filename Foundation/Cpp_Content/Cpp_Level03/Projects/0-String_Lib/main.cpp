#include "headers/clsString.hpp"

int main(void)
{
  clsString str1, str2("This is good!");

  str1.setValue("Hello it's me");

  cout<<str1.getValue()<<'\n';
  cout<<str2.getValue()<<'\n';

  cout<<"Str1 WordsCounter: "<<str1.CountWords()<<'\n';
  cout<<"Str2 WordsCounter: "<<str2.CountWords(str2.getValue())<<'\n';
  cout<<"Str2 WordsCounter: "<<str2.CountWords("Hello World")<<'\n';
  
  return (0);
}
