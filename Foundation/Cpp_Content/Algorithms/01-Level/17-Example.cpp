#include <iostream>
#include <string>

using std::cout, std::endl;
using std::cin;
using std::string;

string *ReadText(string Message)
{
  string *ptrString = new string;

  cout<<Message;
  cin>>*ptrString;

  return (ptrString);
}

string EncryptText(string Text)
{
  string Container = "";
  uint16_t i;
  
  for (i = 0; i <= (Text.length() - 1); i++) {
    Container += (char)((uint16_t)Text[i] + 2);
  }

  return (Container);
}

string DecryptText(string Text)
{
  string DecryptContainer = EncryptText(Text);
  uint16_t i;
  
  for (i = 0; i <= (EncryptText(Text).length() - 1); i++) {
    DecryptContainer[i] = char((uint16_t)(DecryptContainer[i] - 2));
  }

  return (DecryptContainer);
}

void Print(string &Text)
{
  cout<<"Text Before encryption: "<<Text<<"\n";
  cout<<"Text After encryption: "<<EncryptText(Text)<<"\n";
  cout<<"Text After decryption: "<<DecryptText(Text)<<endl;
}

int main()
{
  string *Text = ReadText("Enter a word: ");

  Print(*Text);
  
  delete (Text);

  return (0);
}
