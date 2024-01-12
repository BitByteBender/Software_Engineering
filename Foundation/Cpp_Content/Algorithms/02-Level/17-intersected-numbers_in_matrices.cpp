#include <iostream>
#include<iomanip>
#include<ctime>

using std::cout;
using std::endl;
using std::setw;

inline uint16_t randomizer(uint16_t from, uint16_t to)
{
  return (rand() % (to - from + 1) + from);
}

void matrixFiller(uint16_t matrix[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      matrix[i][j] = randomizer(0, 25);
    }
  }
}

void printMatrix(uint16_t matrix[3][3], uint16_t rows, uint16_t cols, const char *Msg)
{
  uint16_t i = 0, j = 0;

  cout<<Msg;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      cout<<setw(3)<<matrix[i][j]<<'\t';
    }
    cout<<'\n';
  }
  cout<<endl;
}

bool intersectedNumber(uint16_t matrix1[3][3], uint16_t number, uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      if (matrix1[i][j] == number) {
	return (true);
      }
    }
  }

  return (false);
}

void printResult(uint16_t matrix1[3][3], uint16_t matrix2[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0, number = 0;

  cout<<"intersected numbers are:\n";
  
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      number = matrix1[i][j];

      if (intersectedNumber(matrix2, number, rows, cols)) {
	cout<<number<<'\t';
      }
    }
  }
  cout<<endl;
}

int main(void)
{
  srand(unsigned(time(NULL)));

  uint16_t matrix1[3][3], matrix2[3][3];
  
  matrixFiller(matrix1, 3, 3);
  printMatrix(matrix1, 3, 3, "Matrix1:\n");

  matrixFiller(matrix2, 3, 3);
  printMatrix(matrix2, 3, 3, "Matrix2:\n");

  printResult(matrix1, matrix2, 3, 3);
  return (0);
}
