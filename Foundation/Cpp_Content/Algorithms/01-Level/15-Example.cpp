#include <iostream>

using std::cout, std::endl;
using std::cin;
using std::string;

void PrintWords()
{
  uint16_t i = 0, j = 0, k = 0;

  for (i = 65; i <= 90; i++) {
    for (j = 65; j <= 90; j++) {
      for (k = 65; k <= 90; k++) {
	cout<<char(i)<<char(j)<<char(k)<<"\n";
      }
    }
  }

}


int main()
{

  PrintWords();

  return (0);
}
