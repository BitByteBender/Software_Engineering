#include <iostream>
using std::cout, std::endl;

class clsMath
{
private:
  short _A, _B;
  static short _C, _D;
  
public:
  clsMath(short A, short B, short C, short D)
  {
    _A = A;
    _B = B;
    _C = C;
    _D = D;
  }

  short Calc()
  {
    return (_A + _B);
  }
  
  static short CalcSt(short A)
  {
    return (A);
  }

  static short CalcStc(short A, short B)
  {
    return ((A + B) * _C);
  }

  static short CalcStd(short A, short B)
  {
    return ((A + B) * (++_D));
  }
};

short clsMath::_C = 0;
short clsMath::_D = 0;

int main(void)
{
  cout<<clsMath::CalcSt((5 * 5))<<endl;//25
  cout<<clsMath::CalcStc(9, 1)<<endl;//0
  cout<<clsMath::CalcStd(9, 1)<<endl;//10
  
  clsMath M1(15, 6, 1, 2), M2(55, 15, 1, 2), M3(15, 5, 2, 3), M5(5, 3, 15, 6);
  short A, B;

  A = M1.Calc(), B = clsMath::CalcSt(A);
  cout<<A<<'\n';//21
  cout<<B<<'\n';//21
  cout<<M1.CalcSt(8)<<'\n';//8
  cout<<M1.CalcStc(2, 2)<<'\n';//4
  cout<<M1.CalcStd(2, 5)<<'\n';//49
  cout<<"-------------------\n"<<endl;
  
  A = M2.Calc(), B = clsMath::CalcSt(A);
  cout<<A<<endl;//70
  cout<<B<<endl;//70
  cout<<M2.CalcSt(8 + 2)<<'\n';//10
  cout<<M2.CalcStc(5, 6)<<'\n';//11
  cout<<M2.CalcStd(5, 6)<<'\n';//88
  cout<<"-------------------\n"<<endl;

  clsMath M4(5, 3, 2, 7);
  A = M4.Calc(), B = clsMath::CalcSt(A);
  cout<<A<<endl;//8
  cout<<B<<endl;//8
  cout<<M4.CalcSt(10 + 2)<<'\n';//12
  cout<<M4.CalcStc(8, 6)<<'\n';//28
  cout<<M3.CalcStd(2, 2)<<'\n';//32
  cout<<M5.CalcStd(7, 3)<<'\n';//90
  cout<<M4.CalcStd(3, 1)<<'\n';//40
  cout<<"-------------------\n"<<endl;
  return (0);
}
