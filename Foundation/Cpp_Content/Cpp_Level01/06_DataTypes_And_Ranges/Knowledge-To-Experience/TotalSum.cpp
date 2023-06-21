#include <iostream>

using std::cout;
using std::endl;

int main()
{
  std::string PlusSignAndNewLine{" +\n"};
  float FirstProductPrice = 1500.50f, SecondProductPrice = 4500.05f, ThirdProductPrice = 6500.75f;
  float TotalSum = FirstProductPrice + SecondProductPrice + ThirdProductPrice;
  
  cout<<FirstProductPrice<<PlusSignAndNewLine
      <<SecondProductPrice<<PlusSignAndNewLine
      <<ThirdProductPrice
      <<"\n--------------------------\n"
      <<"Total: "<<TotalSum<<endl;

  return 0;
}
