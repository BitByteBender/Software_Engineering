#include <iostream>
#include <string.h>
#include <string>
#include <ctime>

/**
 * Test (1):
 *
 *  valgrind --leak-check=full ./prog
 * ==69775== Memcheck, a memory error detector
 * ==69775== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
 * ==69775== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
 * ==69775== Command: ./prog
 * ==69775== 
 * [Type run to start or close to exit the program]
 *
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
 *
 *
 *
 * Test (2):
 *
 * valgrind --leak-check=full ./prog
 * ==71500== Memcheck, a memory error detector
 * ==71500== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
 * ==71500== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
 * ==71500== Command: ./prog
 * ==71500== 
 * [Type run to start or close to exit the program]
 *
 * Command: c
 * Command: cl
 * Command: clo
 * Command: clos
 * Command: closee
 * Command: closeee
 * Command: r
 * Command: ru
 * Command: runn
 * Command: runnn
 * Command: ruin
 * Command: closi
 * Command: run
 * Program is running ...
 * > cl
 * > c
 * > r
 * > ru
 * > ruin
 * > runn
 * > run
 * Program is running ...
 * > c
 * > cl
 * > clo
 * > cloise
 * > clos
 * > closee
 * > close
 * Program exited successfully!
 * ==71500== 
 * ==71500== HEAP SUMMARY:
 * ==71500==     in use at exit: 0 bytes in 0 blocks
 * ==71500==   total heap usage: 6 allocs, 6 frees, 75,052 bytes allocated
 * ==71500== 
 * ==71500== All heap blocks were freed -- no leaks are possible
 * ==71500== 
 * ==71500== For lists of detected and suppressed errors, rerun with: -s
 * ==71500== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 */

using std::cout;
using std::cin;
using std::endl;
using std::string;

extern const uint16_t Max_Cmd_Length = 100;

char *ReadCommand(const char *);
bool strCmp(char *, const char *);
void onStart();
void onTrigger();
void onExit();

enum enGameChoice{Rock = 1, Paper = 2, Scissors = 3};

struct stBots{
  string arrNames[3] = {"Maestro Bot", "God Mode", "Juan Wicked"};
  uint16_t Score{0};
  uint16_t Health{100};
};

struct stPlayer{
  string inGameName{"Empty"};
  uint16_t Score{0};
  uint16_t Health{100};
};

struct stGameData{
  const string gameName{"Play board"};
  stPlayer Player;
  stBots Bot;
  uint16_t TotalScore = abs(Player.Score - Bot.Score);
  enGameChoice gameChoice;
  uint16_t Round {0};
};

stGameData DataReader(stGameData &Game, uint16_t &pos);

void DisplayGameData(stGameData Game, uint16_t &pos);

void playGame();

int main(void)
{
  onTrigger();
  //playGame();
  return (0);
}

void onStart()
{
  cout<<"Program is running ...\n";
  
  while (true) {
    char *Cmd = ReadCommand("> ");

    /**
     * how many rounds to play
     */
    if (strCmp(Cmd, "run")) {
      cout<<"Program is already running enter [play] or [close]\n";
      free(Cmd);
    } else if (strCmp(Cmd, "play")) {
      free(Cmd);
      playGame();
    }else if (strCmp(Cmd, "close")) {
      free(Cmd);
      onExit();
    }

  }

}

void onTrigger()
{
  cout<<"[Type run to start or close to exit the program]\n\n";
  
  char *Cmd = ReadCommand("Command: ");
  
  if (strCmp(Cmd, "run")) {
    free(Cmd);
    onStart();
  } else {
    if (!strCmp(Cmd, "close")) {
      free(Cmd);
      onTrigger();
    } else {
      free(Cmd);
      onExit();
    }
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

 do {
    cout<<Msg;
    cin.getline(Cmd, Max_Cmd_Length);
 } while (!(strCmp(Cmd, "close") || strCmp(Cmd, "run") || strCmp(Cmd, "play")));

  return (Cmd);
}

bool strCmp(char *Str1, const char *Str2)
{
  unsigned short i = 0;

  for (i = 0; i <= strlen(Str2); i++) {
    if (Str1[i] != Str2[i]) {
      return (false);
    }
  }

  return (true);
}

void BotNamesDisplayer()
{
  cout<<"Choose Bot you want to play against (0->2): ";
  cout<<"\n0:> Maestro Bot";
  cout<<"\n1:> God Mode";
  cout<<"\n2:> Juan Wicked";
  cout<<"\n> ";
}

stGameData DataReader(stGameData &Game, uint16_t &pos)
{
  cout<<"Enter a name (or type +- to get a default name): ";
  getline(cin, Game.Player.inGameName);

  
  BotNamesDisplayer();
  cin >> pos;
    
  cin.ignore();
  
  return (Game);
}

inline uint16_t gameRandomizer(uint16_t From, uint16_t To)
{
  return (rand() % (To - From + 1) + From);
}

string checkGame(stGameData Game, uint16_t choice)
{
  Game.gameChoice = (enGameChoice)choice;
  
  switch (Game.gameChoice) {
  case (enGameChoice::Rock):
    return "Rock";
  case (enGameChoice::Paper):
    return "Paper";
  case (enGameChoice::Scissors):
    return "Scissors";
  default:
    return "Invalid";
  }
}

void onBeginPlay(stGameData Game, uint16_t pos)
{
  uint16_t choicePicker{0}, rounds{0};

  cout<<"How many rounds?: ";
  cin>>rounds;

  
  if (Game.Player.inGameName == "+-")
    Game.Player.inGameName = "Player1";

  Game.Round = rounds;
  
  while (rounds != 0) {

    uint16_t botChoice{0};
    
    cout<<Game.Player.inGameName<<": ";
    cin>>choicePicker;
    Game.gameChoice = (enGameChoice) choicePicker;

    cin.ignore();

    botChoice = gameRandomizer(1, 3);
    cout<<Game.Bot.arrNames[pos]<<": "<<botChoice<<"\n";
    
    cout<<"\nResult:\n>> "
	<<"["<<Game.Player.inGameName<<"] chosen >> ["<<checkGame(Game, choicePicker)<<"]"
	<<" | "
	<<"["<<Game.Bot.arrNames[pos]<<"] chosen >> ["<<checkGame(Game, botChoice)<<"]";

    if (!(choicePicker == botChoice)) {
      cout<<"\n>> ";
      if (choicePicker == 1 && botChoice == 3) {
	cout<<"["<<Game.Player.inGameName<<"] won this round!";
      } else if (choicePicker == 2 && botChoice == 1) {
	cout<<"["<<Game.Player.inGameName<<"] won this round!";
      } else if (choicePicker == 3 && botChoice == 2) {
	cout<<"["<<Game.Player.inGameName<<"] won this round!";
      } else {
	cout<<"["<<Game.Bot.arrNames[pos]<<"] won this round!";
      }
      cout<<"\n";
    } else {
      cout<<"\nIt's a tie game!"<<"\n";
    }
    
    rounds--;
    
    cout<<endl;
  }
  
  DisplayGameData(Game, pos);
  
}

void DisplayGameData(stGameData Game, uint16_t &pos)
{
  cout<<"****************  Game Data  *****************\n";
  
  if (Game.Player.inGameName == "+-") {
    Game.Player.inGameName = "Player1";
  }
  
  cout<<Game.Player.inGameName<<" Vs "<<Game.Bot.arrNames[pos]<<"\n";
  cout<<Game.Player.inGameName<<" Score: "<<Game.Player.Score<<"\n";
  cout<<Game.Bot.arrNames[pos]<<" Score: "<<Game.Player.Score<<"\n";
  cout<<Game.Round<<" Rounds played"<<"\n";
  cout<<"****************  Game Ended  ****************"<<endl;
}

void playGame()
{
  stGameData Game;
  uint16_t pos = 0;
  srand((unsigned)time(nullptr));
  
  DataReader(Game, pos);
  onBeginPlay(Game, pos);
}
