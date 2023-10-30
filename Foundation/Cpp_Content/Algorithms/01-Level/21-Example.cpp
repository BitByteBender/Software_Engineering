#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

short ReadNumber(string);

void StoreNumbers(short [100], short &);

short CalcRepetition(short [100], short, short);

void PrintRepetition(short [100], short, short);

int main(void)
{

  short *ptrLength = new short(2);
  short Arr[100];
  *ptrLength = ReadNumber("Enter a number: ");
  
  StoreNumbers(Arr, *ptrLength);
  
  short CheckedNumber = ReadNumber("Enter the number you want to check: ");

  PrintRepetition(Arr, *ptrLength, CheckedNumber);

  delete (ptrLength);
  
  return (0);
}

short ReadNumber(string Message)
{
  short *ptrNum = new short;

  cout<<Message;
  cin>>*ptrNum;

  return (*ptrNum);
}

void StoreNumbers(short Arr[100], short &Length)
{
  cout<<"Enter array elements:\n";
  uint16_t i;

  for (i = 0; i <= (Length - 1); i++) {
    cout<<"Element ["<<(i + 1)<<"]";
    Arr[i] = ReadNumber(" : ");
  }

}

short CalcRepetition(short Arr[100], short Length, short CheckedNumber)
{
  short i, Sum = 0;

  for (i = 0; i <= (Length - 1); i++) {
    if (Arr[i] == CheckedNumber) {
      Sum += 1;
      continue;
    }
  }

  return (Sum);
}

void PrintRepetition(short Arr[100], short Length, short CheckedNumber)
{
  uint16_t i;

  for (i = 0; i <= (Length - 1); i++) {
    if (i <= 0) {
      cout<<"Original array: ";
    }
    if (i < Length) {
      cout<<Arr[i]<<" "; 
    }
    else
    {
      cout<<Arr[i];
    }
  }

  cout<<"\n";
  cout<<CheckedNumber<<" is repeated "
      <<CalcRepetition(Arr, Length, CheckedNumber)
      <<" time(s)"<<endl;
}
