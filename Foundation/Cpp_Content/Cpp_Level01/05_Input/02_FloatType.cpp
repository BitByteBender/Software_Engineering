#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  cout<<"How much is your monthly income? ";
  float MonthlyIncome{0.0f};
  cin>>MonthlyIncome;

  const int Months{12};
  float YearlyIncome{MonthlyIncome * Months};
  cout<<"Based on your monthly income: "<<MonthlyIncome
      <<" your yearly income should be "<<YearlyIncome<<endl;
  
  return 0;
}
