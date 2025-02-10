#include <iostream>
#include <cstdint>

using std::cout;
using std::endl;

class clsMath
{
private:
  uint16_t _X, _Y;
  static uint16_t _Z;

public:
  clsMath(uint16_t X, uint16_t Y, uint16_t Z)
  {
    _X = X;
    _Y = Y;
    _Z = Z;
  }

  uint16_t Calc()
  {
    _Z++;
    return (_X + _Y + _Z);
  }

  void print()
  {
    cout<<"Counter: "<<_Z<<endl;
  }
};

uint16_t clsMath::_Z = 0;

int main(void)
{
  clsMath M1(15, 15, 5), M2(15, 15, 5), M3(15, 15, 5);

  cout<<M1.Calc()<<'\n';
  M1.print();

  cout<<'\n'<<M2.Calc()<<'\n';
  M2.print();

  cout<<'\n'<<M3.Calc()<<'\n';
  M3.print();
  cout<<"----------------------"<<endl;

  clsMath M4(15, 15, 5);
  cout<<M4.Calc()<<'\n';
  M4.print();

  clsMath M5(15, 15, 5), M6(15, 15, 5);
  cout<<'\n'<<M5.Calc()<<'\n';
  M5.print();

  cout<<'\n'<<M6.Calc()<<'\n';
  M6.print();
  cout<<"----------------------"<<endl;

  clsMath M7(15, 15, 5);
  cout<<M7.Calc()<<'\n';
  M7.print();

  clsMath M8(15, 15, 5);
  cout<<'\n'<<M8.Calc()<<'\n';
  M8.print();

  clsMath M9(15, 15, 5);
  cout<<'\n'<<M9.Calc()<<'\n';
  M9.print();
  cout<<"----------------------"<<endl;
  clsMath M10(15, 15, 5), M11(15, 15, 5), M12(15, 15, 5);

  cout<<M10.Calc()<<'\n';
  cout<<M11.Calc()<<'\n';
  cout<<M12.Calc()<<'\n';
  M10.print();
  M11.print();
  M12.print();
  cout<<"----------------------"<<endl;
  clsMath M13(15, 15, 5), M14(15, 15, 5), M15(15, 15, 5);

  cout<<M13.Calc()<<'\n'; //36
  M13.print();//6
  M14.print();//6
  cout<<M14.Calc()<<'\n';//37
  cout<<M15.Calc()<<'\n';//38
  M15.print();//8
  cout<<"----------------------"<<endl;
  clsMath M16(15, 15, 5), M17(15, 15, 5), M18(15, 15, 5);

  M16.print();//5
  cout<<M16.Calc()<<'\n';//36
  cout<<M17.Calc()<<'\n';//37
  M17.print();//7
  M18.print();//7
  cout<<M18.Calc()<<'\n';//38
  cout<<"----------------------"<<endl;
  
  // Very Important to understand the life of static member variable
  clsMath M19(15, 15, 5), M20(15, 15, 5);

  M19.print();//5
  cout<<M19.Calc()<<'\n';//36
  
  clsMath M21(15, 15, 5);
  M20.print();//5
  cout<<M20.Calc()<<'\n';//36
  cout<<M21.Calc()<<'\n';//37
  M21.print();//7
  cout<<"----------------------"<<endl;
  clsMath M22(15, 15, 5), M23(15, 15, 5);

  M22.print();//5
  cout<<M22.Calc()<<'\n';//36
  cout<<M23.Calc()<<'\n';//37
  
  clsMath M24(15, 15, 5);
  M23.print();//5
  cout<<M24.Calc()<<'\n';//36
  M24.print();//6
  cout<<"----------------------"<<endl;
  return (0);
}
