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

  
  char Alpbet = 't';
  if (Students.find(Alpbet) != Students.end())
    cout<<"\nStudent with the initial alphabet("<<Alpbet<<") is : "<<Students[Alpbet]<<endl;
  else
    cout<<"Student not found!\n"<<endl;

  Alpbet = 'z';
  if (Students.find(Alpbet) != Students.end())
    cout<<"Student with the initial alphabet("<<Alpbet<<") is : "<<Students[Alpbet]<<endl;
  else
    cout<<"Student not found!"<<endl;
  
  return (0);
}
