#include <iostream>

using std::cout;
using std::endl;

enum enScreen{SHD = 480, HD = 720, FHD = 1080};

int main()
{
  enScreen ScreenResolution1, ScreenResolution2;

  ScreenResolution1 = enScreen::HD;
  cout<<"Screen Resolution1: "<<ScreenResolution1<<"\n";

  ScreenResolution2 = enScreen::SHD;
  cout<<"Screen Resolution2: "<<ScreenResolution2<<endl;
  return 0;
}
