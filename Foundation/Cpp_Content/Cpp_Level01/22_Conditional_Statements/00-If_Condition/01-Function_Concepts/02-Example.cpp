#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

unsigned short ReadMark(string Message){
  unsigned short Mark{0};
  cout<<Message;
  cin>>Mark;
  return Mark;
}

bool CheckMark(unsigned short Mark){
  return Mark>=85;
}

void PrintResult(unsigned short Mark){
  if (CheckMark(Mark)) {
    cout<<"Pass"<<endl;
  }else{
    cout<<"Fail"<<endl;
  }
}

int main()
{
  unsigned short Mark = ReadMark("Enter your mark: ");
  PrintResult(Mark);
  return 0;
}
