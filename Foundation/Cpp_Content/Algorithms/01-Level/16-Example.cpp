#include <iostream>

using std::cout, std::endl;
using std::cin;
using std::string;

string *ReadWord(string Message)
{
  string *ptrString = new string;

  do {
    cout<<Message;
    cin>>*ptrString;
  } while (*ptrString <= "AAA");

  return (ptrString);
}

bool GuessPassword(string Word)
{
  uint16_t i = 0, j = 0, Trials = 0, Buffer = 67;
  char k = 'A';
  string WordHolder = "";
  
  if (Word.length() > 3)
  {
    puts("Error");
    return (0);
  }
  else
  {

  for (i = 65; i <= 90; i++) {
    for (j = 65; j <= 90; j++) {
      k = char(k);
      for (k = 'A'; k <= 'Z'; k++) {
	WordHolder += char(i);
	WordHolder += char(j);
	WordHolder += k;
	
	cout<<"Trial ["<<(++Trials)<<"] : "<<WordHolder<<"\n";

	if (Word == WordHolder) {
	  cout<<"\n";
	  cout<<"Password is "<<Word<<"\n";
	  cout<<"Found After "<<(Trials)<<" Trial(s)"<<endl;
	  return (1);
	}

	WordHolder = "";
      }
      if (j == Buffer) {
	Buffer += 3;
	cout<<endl;
      }
    }
  }
  
  }
  
  return (0);
}

int main()
{
  string *Word = ReadWord("Enter a word: ");
  GuessPassword(*Word);
  
  delete (Word);

  return (0);
}
