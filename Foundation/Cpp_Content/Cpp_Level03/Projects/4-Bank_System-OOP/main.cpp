#include "headers/clsbankclient.hpp"

int main(void)
{
  clsBankClient C1 = clsBankClient::Find("AAA3"), C2 = clsBankClient::Find("AAA1", "1234");

  C1.Print();
  cout<<C1.IsEmpty();
  cout<<endl;
  C2.Print();
  cout<<C2.IsEmpty()<<endl;


  cout<<clsBankClient::IsClientExist("AAA3")<<endl;
  cout<<clsBankClient::IsClientExist("AAA1")<<endl;
  cout<<clsBankClient::IsClientExist("AAA2")<<endl;
  cout<<clsBankClient::IsClientExist("AAA4")<<endl;
  
  
  return (0);
}
