#include <iostream>
#include <string.h>

/**
 * Test (1):
 *  valgrind --leak-check=full ./prog
 * ==69775== Memcheck, a memory error detector
 * ==69775== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
 * ==69775== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
 * ==69775== Command: ./prog
 * ==69775== 
 * [Type run to start or close to exit the program]

 * Command: c
 * Command: cl
 * Command: clo
 * Command: clos
 * Command: closee
 * Command: close
 * Program exited successfully!
 * ==69775== 
 * ==69775== HEAP SUMMARY:
 * ==69775==     in use at exit: 0 bytes in 0 blocks
 * ==69775==   total heap usage: 4 allocs, 4 frees, 74,760 bytes allocated
 * ==69775== 
 * ==69775== All heap blocks were freed -- no leaks are possible
 * ==69775== 
 * ==69775== For lists of detected and suppressed errors, rerun with: -s
 * ==69775== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
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
    free(Cmd);
  } else if (!strCmp(Cmd, "close")) {
    free(Cmd);
    onTrigger();
  } else {
    free(Cmd);
    onExit();
  }

}

void onExit()
{
  cout<<"Program exited successfully!\n";
  exit(EXIT_SUCCESS);
}

char *ReadCommand(const char *Msg)
{
  char *Cmd = (char *)malloc(sizeof(char *));

  do {
    cout<<Msg;
    cin.getline(Cmd, Max_Cmd_Length);
  } while (!strCmp(Cmd, "close"));

  return (Cmd);
}

bool strCmp(const char *Str1, const char *Str2)
{
  unsigned short i = 0;

  for (i = 0; i <= strlen(Str2); i++) {
    if (Str1[i] != Str2[i]) {
      return (false);
    }
  }

  return (true);
}
