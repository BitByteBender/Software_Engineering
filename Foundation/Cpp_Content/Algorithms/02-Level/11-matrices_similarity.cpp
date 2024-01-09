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

bool isSimilar(uint16_t matrix1[3][3], uint16_t matrix2[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0;

   for (i = 0; i <= (rows - 1); i++) {
    for (j = 0; j <= (cols - 1); j++) {
      if (matrix1[i][j] != matrix2[i][j]) {
        return (false);
      }
    }
   }
   
  return (true);
}

void printResult(uint16_t matrix1[3][3], uint16_t matrix2[3][3])
{
  if (isSimilar(matrix1, matrix2, 3, 3)) {
    cout<<"\nYes: matrices are similar."<<endl;
  } else {
    cout<<"\nNo: matrices are Not similar ."<<endl;
  }
}

int main(void)
{
  srand(unsigned(time(nullptr)));
  
  uint16_t matrix1[3][3], matrix2[3][3];
  
  arrFiller(matrix1, 3, 3);
  printMatrix(matrix1, 3, 3, "Matrix 1:\n");

  arrFiller(matrix2, 3, 3);
  printMatrix(matrix2, 3, 3, "Matrix 2:\n");

  printResult(matrix1, matrix2);
  return (0);
}
