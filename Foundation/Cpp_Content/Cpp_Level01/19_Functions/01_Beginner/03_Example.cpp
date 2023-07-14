#include <iostream>

using std::cout;
using std::endl;
using std::string;

void DisplayCard(){
  string PrintStars{"*********************"}, Name{"Jack D-Pirate"};
  short Age{44};
  string City{"Florida"}, Country{"USA"};

  cout<<PrintStars<<"\n";
  cout<<"Name: "<<Name<<"\n";
  cout<<"Age: "<<Age<<"\n";
  cout<<"City: "<<City<<"\n";
  cout<<"Country: "<<Country<<"\n";
  cout<<PrintStars<<endl;
}

int main()
{
  DisplayCard();
  return 0;
}
