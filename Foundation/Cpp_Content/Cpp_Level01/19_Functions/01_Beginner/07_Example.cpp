#include <iostream>

using std::cout;
using std::endl;
using std::string;

void MyCardInfo(){
  string Stars{"*********************************"};
  string Fullname{"Soufiane Sad"};
  unsigned short Age{58};
  string City{"Marbella"};
  string Country{"Spain"};

  cout<<Stars<<"\n"
      <<"Name: "<<Fullname<<"\n"
      <<"Age: "<<Age<<"\n"
      <<"City: "<<City<<"\n"
      <<"Country: "<<Country<<"\n"
      <<Stars<<endl;
}

int main()
{
  MyCardInfo();
  return 0;
}
