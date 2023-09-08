#include <iostream>

using std::cout;
using std::endl;

int main()
{
  short Alpha{15}, Lambda{5}, Epsilon{20};

  cout<<"Alpha: "<<Alpha<<"\nLambda: "<<Lambda<<"\nEpsilon: "<<Epsilon<<"\n\n";

  Epsilon = ++Alpha + Lambda-- - Epsilon++; // 1 = 16 + 5(-1) - 20(+1)
  /*
   Alpha = 16
   Lambda = 4
   Epsilon = 1
  */
  cout<<"Alpha: "<<Alpha<<"\nLambda: "<<Lambda<<"\nEpsilon: "<<Epsilon<<"\n\n";
  
  Alpha = ++Lambda - --Lambda + ++Alpha + Epsilon--;// 19 = 5 - 4 + 17 + 1(-1)
  /*
   Alpha = 19
   Lambda = 4
   Epsilon = 0
  */
  cout<<"Alpha: "<<Alpha<<"\nLambda: "<<Lambda<<"\nEpsilon: "<<Epsilon<<"\n\n";
  
  Lambda = Alpha + Epsilon + (++Epsilon) - (Lambda--); // 16 = 19 + 0 + 1 - 4(-1)
  /*
   Alpha = 19
   Lambda = 16
   Epsilon = 1
  */
  cout<<"Alpha: "<<Alpha<<"\nLambda: "<<Lambda<<"\nEpsilon: "<<Epsilon<<"\n\n";

  short Sigma = Lambda++ - (Epsilon) + (++Alpha); // 35 = 16(+1) - 1 + 20
  /*
   Alpha = 20
   Lambda = 17
   Epsilon = 1
   Sigma = 35
  */
  cout<<"Alpha: "<<Alpha<<"\nLambda: "<<Lambda<<"\nEpsilon: "<<Epsilon<<"\nSigma: "<<Sigma<<"\n\n";

  Alpha = 3;
  Sigma = Alpha-- + Alpha++ + (++Alpha); // 9 = 3(-1) + 2(+1) + 4 
  cout<<"Alpha: "<<Alpha<<"\nSigma: "<<Sigma<<endl;
  return 0;
}
