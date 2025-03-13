#include "headers/clsinputvalidate.hpp"

int main(void)
{
  cout<<clsInputValidate::IsNumberBetween(5, 1, 10)<<'\n';
  cout<<clsInputValidate::IsNumberBetween(5.544, 1.341, 5.546)<<'\n';
  cout<<clsInputValidate::IsNumberBetween(5.54f, 1.34f, 4.56f)<<'\n';

  uint16_t D = 11, Dd = 31, M = 3, Mm = 12, Y = 2025;
  cout<<clsInputValidate::IsDateBetween(clsDate(), clsDate(D, M, Y), clsDate(Dd, Mm, Y))<<endl;
  cout<<clsInputValidate::IsDateBetween(clsDate(), clsDate(Dd, Mm, Y), clsDate(D, M, Y))<<endl;

  int a = clsInputValidate::ReadIntegerNumber("Invalid integer number, Enter again: ");
  cout<<"a = "<<a<<'\n';

  int b = clsInputValidate::ReadIntegerNumberBetween(1, 15, "Number entered is not between ");
  cout<<"b = "<<b<<endl;
  
  /*
  cout<<clsInputValidate::NANChecker("-81r-")<<endl;
  cout<<clsInputValidate::NANChecker("99-Z-")<<endl;
  cout<<clsInputValidate::NANChecker("-8Z1r-")<<endl;
  cout<<clsInputValidate::NANChecker("9-Z")<<endl;
  cout<<clsInputValidate::NANChecker("9")<<endl;
  cout<<clsInputValidate::NANChecker("809")<<endl;
  cout<<clsInputValidate::NANChecker("-829")<<endl;
  cout<<clsInputValidate::NANChecker("99-")<<endl;
  cout<<clsInputValidate::NANChecker("-9-8")<<endl;
  */
  return (0);
}
