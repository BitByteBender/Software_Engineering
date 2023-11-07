#include <iostream>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;

/**
 * How many arrays: 10
 * Enter the array keys: 5
 * Enter the array length: 4
 * Array Elements:
 * Array[0]: IJNG-ITDT-WBMA-KHPW-UGZY
 * Array[1]: ODJI-GTNA-DONM-XDSH-YYAV
 * Array[2]: ZOXM-VPIR-VHPJ-KZUT-SHTV
 * Array[3]: XGJW-LEDK-CFHD-TEPQ-TXHR
 * Array[4]: HWCR-XWKP-DDNC-MYYX-CDHE
 * Array[5]: KOIF-VXVO-XCFE-BIXY-GIQM
 * Array[6]: NFOB-DNBG-SKKD-BSIW-SEMP
 * Array[7]: ISVJ-CSKI-CAUS-FJVI-YWOS
 * Array[8]: HBVK-VEGN-KSES-MZEO-UOZW
 * Array[9]: OTQV-EMDE-IUXR-XSBS-YJIK
 * ==115827== 
 * ==115827== HEAP SUMMARY:
 * ==115827==     in use at exit: 0 bytes in 0 blocks
 * ==115827==   total heap usage: 7 allocs, 7 frees, 74,798 bytes allocated
 * ==115827== 
 * ==115827== All heap blocks were freed -- no leaks are possible
 * ==115827== 
 * ==115827== For lists of detected and suppressed errors, rerun with: -s
 * ==115827== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 */

short *ReadPositiveNumber(const char *Message)
{
  short *ptrNumber = (short *)malloc(sizeof(short));

  do {
    cout<<Message;
    cin>>*ptrNumber;
  } while (*ptrNumber <= 0);

  return (ptrNumber);
}

short Randomizer(short From, short  To)
{
  short RandNum = (rand() % (To - From + 1) + From);
  return (RandNum);
}

void GenerateKeys(char *&Arr, short &ArrKeys, short &ArrLength)
{
  uint16_t i = 0, j = 0;

  Arr = (char *)malloc(sizeof(char *) * (ArrLength + 1));

  for (i = 0; i < ArrKeys; i++) {
    for (j = 0; j <= (ArrLength - 1); j++) {
      Arr[j] = char(Randomizer(65, 90));
    }
  }

  Arr[ArrLength] = '\0';
}


void PrintArrayElements(char *Arr, const short Length, const short ArrKeys, const short ArrLength)
{
  uint16_t i = 0, j = 0, k = 0;

  cout<<"Array Elements:\n";
  
  for (i = 0; i <= (Length - 1); i++) {
    cout<<"Array["<<i<<"]: ";
    for (j = 0; j < ArrKeys; j++) {
      for (k = 0; k <= (ArrLength - 1); k++) {
        Arr[k] = (char)(Randomizer(65, 90));
	cout<<Arr[k];
      }
      if (j < (ArrKeys -1)) {
	cout<<'-';
      }
    }
    cout<<'\n';
  }
  cout<<endl;
}

void FreeMemoAlloc(short *ptrNumber, char *Arr)
{
  free(Arr);
  free(ptrNumber);
}

int main(void)
{
  srand((unsigned)time(NULL));
  
  short *ArrCount = ReadPositiveNumber("How many arrays: ");
  short *ArrKeys = ReadPositiveNumber("Enter the array keys: ");
  short *ArrLength = ReadPositiveNumber("Enter the array length: ");
  char *Arr = nullptr;


  GenerateKeys(Arr, *ArrKeys, *ArrLength);
  PrintArrayElements(Arr, *ArrCount, *ArrKeys, *ArrLength);
  
  FreeMemoAlloc(ArrCount, Arr);
  free(ArrKeys);
  free(ArrLength);
  return (0);
}
