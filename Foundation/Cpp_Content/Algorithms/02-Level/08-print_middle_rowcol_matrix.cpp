#include <iostream>
#include <ctime>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

inline uint16_t NumberRandomizer(uint16_t from, uint16_t to)
{
  return (rand() % (to - from + 1) + from);
}

void arrFiller(uint16_t arr[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0;

  for (i = 0; i <= (rows - 1); i++) {
    for (j = 0; j <= (cols - 1); j++) {
      arr[i][j] = NumberRandomizer(1, 10);
    }
  }
}

void printMatrix(uint16_t arr[3][3], uint16_t rows, uint16_t cols, const char *Msg)
{
  uint16_t i = 0, j = 0;

  cout<<Msg;

  for (i = 0; i <= (rows - 1); i++) {
    for (j = 0; j <= (cols - 1); j++) {
      cout<<' ';
      if (arr[i][j] < 10) {
	cout<<0;
      }
      cout<<arr[i][j]<<'\t';
    }
    cout<<'\n';
  }
  cout<<endl;
}

void printRow(uint16_t arr[3][3], uint16_t rows, uint16_t cols, const char *Msg)
{
  uint16_t j = 0, middleRow = rows / 2;

  cout<<Msg;

  for (j = 0; j <= (cols - 1); j++) {
    cout<<' ';
    if (arr[middleRow][j] < 10) {
	cout<<0;
    }
    cout<<arr[middleRow][j]<<'\t';
  }
  cout<<'\n'<<endl;
}

void printCol(uint16_t arr[3][3], uint16_t rows, uint16_t cols, const char *Msg)
{
  uint16_t i = 0, middleCol = cols / 2;

  cout<<Msg;

  for (i = 0; i <= (rows - 1); i++) {
    cout<<' ';
    if (arr[i][middleCol] < 10) {
	cout<<0;
    }
    cout<<arr[i][middleCol]<<'\t';
  }
  cout<<endl;
}


int main(void)
{
  srand(unsigned(time(nullptr)));
  
  uint16_t matrix[3][3];

  arrFiller(matrix, 3, 3);
  printMatrix(matrix, 3, 3, "Matrix:\n");

  printRow(matrix, 3, 3, "Middle Row of matrix is:\n");
  printCol(matrix, 3, 3, "Middle Col of matrix is:\n");
  
  return (0);
}
