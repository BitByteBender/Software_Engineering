#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned short Grade{0};
  std::string Message{"Enter your grade: "};
  
  cout<<Message;
  cin>>Grade;

  if (Grade>=90) {
    cout<<"A"<<endl;
  }else if(Grade>=80){
    cout<<"B"<<endl;
  }else if(Grade>=70){
    cout<<"C"<<endl;
  }else if(Grade>=60){
    cout<<"D"<<endl;
  }else if(Grade>=50){
    cout<<"E"<<endl;
  }else{
    cout<<"F"<<endl;
  }
  
  return 0;
}
