#include <iostream>

using std::cout;
using std::endl;

int main(){
  //We assign const to vars that are constant and cannot be changed like 1h = 60 minutes / 1minutes = 60seconds / Pi =  3.14
  const short MinutesPerHour = 60;

  //This variable is being declared as a constant
  const std::string Gender = "Male";
  cout<<Gender<<"\n";

  //Remember: Vars that have been declared as const can never get re-assigned a new value
  Gender = "Female";//This is will issue an error cause the var Gender is declared as constant
  cout<<Gender<<endl;
  return 0;
}
