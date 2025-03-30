#include <iostream>
#include <map>

using std::cout;
using std::endl;
using std::map;
using std::string;

int main(void)
{
  map <char, string> Students;

  Students['s'] = "Souf";
  Students['a'] = "Ali";
  Students['n'] = "Nour";
  Students['t'] = "Taha";
  Students['g'] = "Ghada";
  Students['o'] = "Olayaa";

  for (const auto &Pair : Students)
    cout<<"Students with the "
	<<(char)Pair.first<<" key is:>> ("
	<<(string)Pair.second<<')'
	<<endl;
  
  return (0);
}
