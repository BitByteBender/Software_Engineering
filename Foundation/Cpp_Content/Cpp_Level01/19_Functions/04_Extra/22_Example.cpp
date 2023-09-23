#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

std::string ReadText(){
  std::string Text{"Empty"};
  
  cout<<"Enter a text: ";
  getline(cin, Text);

  return Text;
}

void PrintTextOnScreen(std::string TextHolder){
  cout<<TextHolder<<endl;
}

int main()
{
  std::string Text = ReadText();
  PrintTextOnScreen(Text);
  return 0;
}
