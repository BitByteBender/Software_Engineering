#include <iostream>
#include <ctime>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void storeNumberIntoVector(vector <uint16_t> &vNums, uint16_t num)
{
  vNums.push_back(num);
}

char readDecision(const char *Msg)
{
  char Cond{'x'};
  
  cout<<Msg;
  cin>>Cond;

  return (Cond);
}

bool keepStoring()
{
  char cond = readDecision("Do you wanna continue?");
  return (cond == 'y' || cond == 'Y');
}

void readNum(vector <uint16_t> &vNums)
{
  char cond;
  uint16_t num;
  
  cout<<"enter a number: ";
  
  do {
    cin>>num;
    storeNumberIntoVector(vNums, num);
    cond = keepStoring();
    
    if (cond) {
      cout<<"re-enter a number: ";
    }
  } while (cond);
}

void printNumsInVec(vector <uint16_t> vNums)
{
  cout<<"Vector elements are: ";
  
  for (uint16_t &nums : vNums) {
    cout<<nums<<' ';
  }
  cout<<endl;
}

int main(void)
{
  vector <uint16_t> vNums;
  
  readNum(vNums);
  printNumsInVec(vNums);

  return (0);
}
