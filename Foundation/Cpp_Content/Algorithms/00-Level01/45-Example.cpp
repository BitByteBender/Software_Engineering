#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;

enum enOperations{Add = '+', Sub = '-', Mul = '*', Div = '/'};

struct stNumbers
{
  unsigned short Num1{0};
  unsigned short Num2{0};
  enOperations Type;
};

void DisplayOperations()
{
  cout<<"choose an Operation: ";
  cout<<"(+) Addition\n"
      <<"(-) Subtraction\n"
      <<"(/) Division\n"
      <<"(*) Multiplication\n"
      <<"\n----------------------\n";
}

void ReadNumbers(stNumbers &Nums)
{
  cout<<"Enter a number: ";
  cin>>Nums.Num1;

  cout<<"Enter a number: ";
  cin>>Nums.Num2;

  char OperationPicker{'+'};
  
  DisplayOperations();
  cout<<"Your choice?: ";
  cin>>OperationPicker;

  Nums.Type = (enOperations) OperationPicker;
}

float CalculateNumbers(stNumbers Nums)
{
  switch (Nums.Type)
  {
  case enOperations::Add:
    return (Nums.Num1 + Nums.Num2);
  case enOperations::Sub:
    return (Nums.Num1 - Nums.Num2);
  case enOperations::Mul:
    return (Nums.Num1 * Nums.Num2);
  case enOperations::Div:
    return (Nums.Num1 / Nums.Num2);
  default:
    return (0);
  }
}

void PrintResult(stNumbers Nums)
{
  float Result = CalculateNumbers(Nums);
  cout<<"Result of ("<<Nums.Num1<<" "<<char(Nums.Type)<<" "<<Nums.Num2<<") = "<<Result<<endl;
}

void ReadMultipleNumbers(stNumbers Nums[3], unsigned short &Length)
{
  cout<<"Enter the array length: ";
  cin>>Length;
  
  unsigned short i;
  
  for (i = 0; i <= (Length - 1); i++) {
    ReadNumbers(Nums[i]);
  }
}

void PrintArrayOfResults(stNumbers Nums[3], unsigned short Length)
{
  unsigned short i;
  
  for (i = 0; i <= (Length - 1); i++) {
    cout<<"Result ["<<(i + 1)<<"]: ";
    PrintResult(Nums[i]);
  }
}

void DisplayArray(stNumbers *Arr, unsigned short Length)
{
  cout<<"Array list: ";
  unsigned short j;

  for (j = 0; j <= (Length - 1); j++) {
    //PrintArrayOfResults(&Arr[j], Length);
    cout<<CalculateNumbers(*(Arr + j));
    if (j < (Length - 1)) {
      cout<<", ";
    }
  }
  cout<<endl;
}

int main()
{
  stNumbers Nums[4], *Arr{nullptr};
  unsigned short Length{0};
  Arr = Nums;

  ReadMultipleNumbers(Nums, Length);
  PrintArrayOfResults(Nums, Length);
  DisplayArray(Arr, Length);
  return 0;
}
