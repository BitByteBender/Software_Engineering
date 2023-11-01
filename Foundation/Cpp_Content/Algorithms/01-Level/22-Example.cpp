#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;

short *ReadNumber(string Message)
{
  short *ptrNum = (short*)malloc(sizeof(short));

  cout<<Message;
  cin>>*ptrNum;

  return (ptrNum);
}

uint16_t Randomizer(uint16_t From, uint16_t To)
{
  uint16_t RandNum = (rand() % (To - From + 1) + From);
  return (RandNum);
}

void StoredRandNumbers(short *Arr, short Length)
{
  unsigned short i = 0;

  for (i = 0; i <= (Length - 1); i++) {
    Arr[i] = Randomizer(1, 100);
  }
  
  Arr[Length] = '\0';
}

void PrintArrayElements(const short *Arr, short Length)
{
  cout<<"Array Elements: ";
  unsigned short i;
  
  for (i = 0; i <= (Length - 1); i++) {
    if (i < (Length - 1)) {
      cout<<Arr[i]<<" ";
    }
    else {
      cout<<Arr[i]<<endl;
    }
  }

}

int main()
{
  srand((unsigned)time(NULL));
  
  short *Length = ReadNumber("Enter the length of the array: ");
  short *Arr = (short*)malloc(sizeof(short) * (*Length + 1));
  
  StoredRandNumbers(Arr, *Length);
  PrintArrayElements(Arr, *Length);
  
  free(Arr);
  free(Length);
  return 0;
}
