#include <iostream>
#include <iomanip>
#include <ctime>

using std::cout;
using std::endl;
using std::setw;

inline uint16_t numberRandomizer(uint16_t from, uint16_t to)
{
  return (rand() % (to - from + 1) + from);
}

void fillMatrix(uint16_t matrix[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      matrix[i][j] = numberRandomizer(0, 100);
    }
  }
}

void printMatrix(uint16_t matrix[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0;

  cout<<"Matrix:\n";

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      cout<<setw(3)<<matrix[i][j]<<'\t';
    }
    cout<<'\n';
  }
  cout<<endl;
}

uint16_t getMin(uint16_t matrix[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0, number = 0, minNumber = matrix[0][0];

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      number = matrix[i][j];
      if (number < minNumber) {
	minNumber = number;
      }
    }
  }
  return (minNumber);
}

uint16_t getMax(uint16_t matrix[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0, number = 0, maxNumber = matrix[0][0];

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      number = matrix[i][j];
      if (number > maxNumber) {
	maxNumber = number;
      }
    }
  }
  return (maxNumber);
}

void printResult(uint16_t matrix[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0, number = 0, maxNumber = 0, minNumber = 0;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      number = matrix[i][j];
      if (number == getMin(matrix, rows, cols) && minNumber == 0) {
	minNumber = number;
      } else if (number == getMax(matrix, rows, cols) && maxNumber == 0) {
	maxNumber = number;
      }
    }
  }
  cout<<"Min number is: "<<minNumber<<'\n';
  cout<<"Max number is: "<<maxNumber<<endl;
}

int main(void)
{
  srand(unsigned(time(nullptr)));

  uint16_t matrix[3][3];

  fillMatrix(matrix, 3, 3);
  printMatrix(matrix, 3, 3);
  printResult(matrix, 3, 3);

  return (0);
}
