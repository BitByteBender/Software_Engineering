#include <iostream>
#include <cstdint>

using std::string;
using std::cout;
using std::endl;

class clsPlayer
{
private:
  const _Float32 ExtraHealth = 45.f;
  
public:
  string Name;
  uint16_t Level;
  _Float32 Health, Speed;
  string ArrRaces[2] = {"Human", "Elf"}, Type[3] = {"Magic", "Melee", "Hybrid"};

  _Float32 Booster(string Type)
  {
    if (Type == "Hybrid") return (Speed * 2.0f);
  }

  inline string GuildName()
  {
    return ("[Synergy] " + Name);
  }

  _Float32 BoostHealth()
  {
    if (Health < 15.0f) {
      return (Health + ExtraHealth); 
    } else return (Health);
  }
};

int main(void) {
  clsPlayer Player1, Player2;
  string Race, Type;
  _Float32 NewSpeedBooster;
  
  Player1.Name = "Maestro";
  Player1.Level = 55;
  Player1.Health = 100.0f;
  Player1.Speed = 45.5f;
  Race = Player1.ArrRaces[1];
  Type = Player1.Type[2];
  
  cout<<"Player1 Data: \n";
  cout<<"Player Name: "<<Player1.Name<<'\n'
      <<"Player Health: "<<Player1.Health<<'\n'
      <<"Player Speed: "<<Player1.Speed<<'\n'
      <<"Player Race: "<<Race<<'\n'
      <<"Player Type: "<<Type<<'\n'
      <<"Player Choice: "<<Player1.GuildName()<<'\n'
      <<"Player ExtraHealth: "<<Player1.BoostHealth()<<'\n';
  
  NewSpeedBooster = Player1.Booster(Type);
  cout<<"SpeedBoost: "<<NewSpeedBooster<<'\n';

  Player2.Health = 14.0f;
  cout<<"Player Name: "<<(Player2.Name = "Roronoa")<<'\n'
      <<"Player GuildName: "<<Player2.GuildName()<<'\n'
      <<"Player Speed: "<<(Player2.Speed = 80.0f)<<'\n'
      <<"Player Health: "<<Player2.Health<<'\n'
      <<"Player ExtraHealth: "<<Player2.BoostHealth()<<'\n';
  
  NewSpeedBooster = Player2.Booster(Type);
  cout<<"SpeedBoost: "<<NewSpeedBooster<<'\n';
  return (0);
}
