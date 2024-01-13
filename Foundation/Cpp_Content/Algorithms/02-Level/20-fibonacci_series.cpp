#include <iostream>

using std::cout;
using std::cin;
using std::endl;

uint16_t readNumber(std::string Msg)
{
  uint16_t num{0};

  cout<<Msg;
  cin>>num;

  return (num);
}

inline uint16_t sum(uint16_t num1, uint16_t num2)
{
  return (num1 + num2);
}

void FibonacciSeries(uint16_t arr[10], uint16_t length)
{
  uint16_t i = 0;
  arr[0] = 1, arr[1] = 1;

  for (i = 2; i <= (length - 1); i++) {
    arr[i] = sum(arr[i - 2], arr[i - 1]);
  }
}

void printFibSeries(uint16_t arr[10], uint16_t length)
{
  cout<<"Fibonacci series of "<<length<<" :\n";

  uint16_t i = 0;

  for (i = 0; i <= (length - 1); i++) {
    if (i < (length - 1)) {
      cout<<arr[i]<<' ';
      continue;
    }
    cout<<arr[i];
  }
  cout<<endl;
}

int main(void)
{
  uint16_t number = readNumber("Enter a number: ");
  uint16_t arr[10];
  
  FibonacciSeries(arr, number);
  printFibSeries(arr, number);
  return (0);
}

