#include <iostream>

using std::cout;
using std::endl;

enum enDirection{East = 1, West = 2, North = 3, South = 4};

int main()
{
  enDirection Direction1, Direction2, Direction3, Direction4;

  Direction1 = enDirection::East;
  cout<<"Direction1; "<<Direction1<<"\n";

  Direction2 = enDirection::North;
  cout<<"Direction2: "<<Direction2<<"\n";

  Direction3 = enDirection::West;
  cout<<"Direction3: "<<Direction3<<"\n";

  Direction4 = enDirection::South;
  cout<<"Direction4: "<<Direction4<<endl;
  return 0;
}
