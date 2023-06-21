#include <iostream>

using std::cout;
using std::endl;
using std::endl;

int main()
{

  cout<<"The size of int is "<<sizeof(int)<<" bytes.\n";
  cout<<"The size of short int is "<<sizeof(short int)<<" bytes.\n";
  cout<<"The size of long int is "<<sizeof(long int)<<" bytes.\n";
  cout<<"The size of long long int is "<<sizeof(long long int)<<" bytes.\n";
  
  cout<<"The size of char is "<<sizeof(char)<<" bytes.\n";
  
  cout<<"The size of float is "<<sizeof(float)<<" bytes.\n";

  cout<<"The size of double is "<<sizeof(double)<<" bytes.\n";
  cout<<"The size of long double is "<<sizeof(long double)<<" bytes.\n";

  cout<<"The size of string is "<<sizeof(std::string)<<" bytes.\n";
  
  cout<<"The size of bool is "<<sizeof(bool)<<" bytes.\n";

  return 0;
}
