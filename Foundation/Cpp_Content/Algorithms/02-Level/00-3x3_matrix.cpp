#include <iostream>
#include <ctime>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

uint16_t randomNums(uint16_t From, uint16_t To)
{
  return (rand() % (To - From + 1) + From);
}

void fillArr(uint16_t arr[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = i;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      arr[i][j] = randomNums(1, 100);
    }
  }
}

void print3by3Matrix(uint16_t arr[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = i;

  cout<<"This is a 3x3 randomly generated matrix:\n";
  
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      cout<<setw(3)<<arr[i][j];
      if (j < 3) {
	cout<<'\t';
      }
    }
    cout<<'\n';
  }
}

int main(void)
{
  srand(unsigned(time(nullptr)));

  uint16_t arr[3][3];

  fillArr(arr, 3, 3);
  print3by3Matrix(arr, 3, 3);
  return (0);
}
