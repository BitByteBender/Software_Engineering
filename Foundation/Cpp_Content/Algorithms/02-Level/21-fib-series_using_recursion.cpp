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

void printFibSeries(uint16_t length, uint16_t head, uint16_t tail)
{
  uint16_t i = 1, temp = sum(head, tail);
  
  if (length == 10) {
    cout<<"Fibonacci series of "<<length<<" :\n";
    cout<<temp<<' ';
  }
  
  if (i >= (length - 1)) {
    cout<<temp<<endl;
    return;
  } else {
    head = tail;
    tail = temp;
    cout<<temp<<' ';
    printFibSeries(length - 1, head, tail);
  }
}

int main(void)
{
  uint16_t number = readNumber("Enter a number: ");
  
  printFibSeries(number, 0, 1);
  return (0);
}
