#include <iostream>

using std::cout;
using std::endl;

void OutputSideStars(){
  cout<<"*\t*\n";
}

void OutputMidStars(){
  cout<<"*********\n";
}

void OutputH(){
  OutputSideStars();
  OutputSideStars();
  OutputSideStars();
  OutputMidStars();
  OutputSideStars();
  OutputSideStars();
  OutputSideStars();
}

int main()
{
  OutputH();
  return 0;
}
