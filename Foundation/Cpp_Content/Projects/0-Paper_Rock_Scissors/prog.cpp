#include <iostream>
#include <string.h>
/**
 */

using std::cout;
using std::cin;
using std::endl;
using std::string;

const uint16_t Max_Cmd_Length = 100;

char *ReadCommand(const char *);
bool strCmp(const char *, const char *);
void onStart();
void onTrigger();
void onExit();

int main(void)
{
  onTrigger();
  return (0);
}

void onStart()
{
  cout<<"Program is running ...\n";
  
  while (true) {
    char *Cmd = ReadCommand("> ");

    if (strCmp(Cmd, "close")) {
      break;
    }
  }
  
}

void onTrigger()
{
  cout<<"[Type run to start or close to exit the program]\n\n";
  
  char *Cmd = ReadCommand("Command: ");
  
  if (strCmp(Cmd, "run")) {
    onStart();
  } else if (!strCmp(Cmd, "close")) {
    onTrigger();
  }

}

void onExit()
{
  cout<<"Program exited successfully!\n";
  exit(EXIT_SUCCESS);
}

char *ReadCommand(const char *Msg)
{
  char *Cmd = (char *)malloc(sizeof(char) * Max_Cmd_Length);

  cout<<Msg;
  cin.getline(Cmd, Max_Cmd_Length);

  return (Cmd);
}

bool strCmp(const char *Str1, const char *Str2)
{
  unsigned short i = 0;

  for (i = 0; Str2[i] != '\0'; i++) {
    if (Str2[i] != Str1[i]) {
      return (false);
    }
  }

  return (true);
}
