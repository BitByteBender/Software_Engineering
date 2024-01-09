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
      cout<<setw(3)<<arr[i][j]<<'\t';
    }
    cout<<'\n';
  }
  cout<<endl;
}

uint16_t mulMatrices(uint16_t arr1[3][3], uint16_t arr2[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t mul = 0;

  mul =  (arr1[rows][cols] * arr2[rows][cols]);
  
  return (mul);
}

void printResult(uint16_t arr1[3][3], uint16_t arr2[3][3], uint16_t arr[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0;

  cout<<"Result:\n";
  
  for (i = 0; i <= (rows - 1); i++) {
    for (j = 0; j <= (cols - 1); j++) {
      arr[i][j] = mulMatrices(arr1, arr2, i, j);
      cout<<arr[i][j]<<'\t';
    }
    cout<<'\n';
  }
  cout<<endl;
}

int main(void)
{
  srand(unsigned(time(nullptr)));
  
  uint16_t matrix1[3][3], matrix2[3][3], matrixMul[3][3];
  
  arrFiller(matrix1, 3, 3);
  arrFiller(matrix2, 3, 3);

  printMatrix(matrix1, 3, 3, "Matrix 1:\n");
  printMatrix(matrix2, 3, 3, "Matrix 2:\n");

  printResult(matrix1, matrix2, matrixMul, 3, 3);
  
  return (0);
}
