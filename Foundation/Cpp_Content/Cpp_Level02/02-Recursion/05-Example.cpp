#include <iostream>

using std::cout, std::endl;

short Add_Performer(short, short);
short Add_Double(int);

int main()
{
  short n{15};
  
  cout<<Add_Double(n)<<"\n";
  
  return 0;
}

short Add_Performer(short n, short result)
{
  if (n == 0)
  {
    return (result);
  }
  else
  {
    return (Add_Performer((n - 1), (result + 2)));
  }
}

short Add_Double(int n)
{
    return (Add_Performer(n, 0));
}
