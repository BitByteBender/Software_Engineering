#include <iostream>

using std::cout;
using std::endl;
using std::string;


int main()
{
  string Stars{"*********************************"};
  string Firstname{"Sofia"}, Lastname{"Reynolds"};
  unsigned short Age{32};
  string Profession{"Data Science"}, Education{"Bachelor's Degree in computer science"}, Country{"United States"}, City{"San Francisco"};
  unsigned char Gender{'F'};
  bool isMarried{false};

  //Card Person data
  cout<<Stars<<"\n";
  cout<<"Name: "<<Firstname +" " + Lastname<<"\n";
  cout<<"Age: "<<Age<<"\n";
  cout<<"Profession: "<<Profession<<"\n";
  cout<<"Education: "<<Education<<"\n";
  cout<<"Country: "<<Country<<"\n";
  cout<<"City: "<<City<<"\n";
  cout<<"Gender: "<<Gender<<"\n";
  cout<<"Married: "<<isMarried<<"\n";
  cout<<Stars<<endl;
  return 0;
}
