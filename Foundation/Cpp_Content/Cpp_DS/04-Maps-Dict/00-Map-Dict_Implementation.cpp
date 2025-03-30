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

  cout<<"Students with the a key is:>> ("<<Students['a']<<')'<<endl;
  cout<<"Students with the s key is:>> ("<<Students['s']<<')'<<endl;
  cout<<"Students with the g key is:>> ("<<Students['g']<<')'<<endl;
  cout<<"Students with the t key is:>> ("<<Students['t']<<')'<<endl;
  cout<<"Students with the o key is:>> ("<<Students['o']<<')'<<endl;
  cout<<"Students with the n key is:>> ("<<Students['n']<<')'<<endl;

  return (0);
}
