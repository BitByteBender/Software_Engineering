#include <iostream>
#include "math.h"

using std::cout;
using std::endl;

int main()
{
  float A{3.15f}, B{75.45f}, C{24.15f}, D{9.99f}, E{87.499f};
  float Calculation = pow(sqrt(A + D * 15.0f), 3.0f);
  float FirstArray[2] = {52.25f, 43.34f};
  float SecondArray[5] = {D, FirstArray[0], C, D*2.0f, 56.47f}, ThirdArray[6] = {65.5f, 12.01f, 365.78f, 972.68f, FirstArray[1], Calculation};
  float FourthArray[9] = {E, A, pow(78.45f,2), B, SecondArray[3], ThirdArray[5], SecondArray[0], ThirdArray[3], SecondArray[1]};
  
  cout<<"FirstArray at index 0: "<<FirstArray[0]<<"\n";
  cout<<"FirstArray at index 1: "<<FirstArray[1]<<"\n\n";

  cout<<"SecondArray at Index 0: "<<SecondArray[0]<<"\n";
  cout<<"SecondArray at Index 1: "<<SecondArray[1]<<"\n";
  cout<<"SecondArray at Index 2: "<<SecondArray[2]<<"\n";
  cout<<"SecondArray at Index 3: "<<SecondArray[3]<<"\n";
  cout<<"SecondArray at Index 4: "<<SecondArray[4]<<"\n\n";

  cout<<"ThirdArray at Index 0: "<<ThirdArray[0]<<"\n";
  cout<<"ThirdArray at Index 1: "<<ThirdArray[1]<<"\n";
  cout<<"ThirdArray at Index 2: "<<ThirdArray[2]<<"\n";
  cout<<"ThirdArray at Index 3: "<<ThirdArray[3]<<"\n";
  cout<<"ThirdArray at Index 4: "<<ThirdArray[4]<<"\n";
  cout<<"ThirdArray at Index 5: "<<ThirdArray[5]<<"\n\n";

  cout<<"FourthArray at Index 0: "<<FourthArray[0]<<"\n";
  cout<<"FourthArray at Index 1: "<<FourthArray[1]<<"\n";
  cout<<"FourthArray at Index 2: "<<FourthArray[2]<<"\n";
  cout<<"FourthArray at Index 3: "<<FourthArray[3]<<"\n";
  cout<<"FourthArray at Index 4: "<<FourthArray[4]<<"\n";
  cout<<"FourthArray at Index 5: "<<FourthArray[5]<<"\n";
  cout<<"FourthArray at Index 6: "<<FourthArray[6]<<"\n";
  cout<<"FourthArray at Index 7: "<<FourthArray[7]<<"\n";
  cout<<"FourthArray at Index 8: "<<FourthArray[8]<<endl;
  

  
  return 0;
}
