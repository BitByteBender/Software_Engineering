#include <iostream>
#include <iomanip>
#include <ctime>

using std::cout;
using std::endl;
using std::setw;

inline uint16_t randomizer(uint16_t from, uint16_t to)
{
  return (rand() % (to - from + 1) + from);
}

void fillArray(uint16_t arr[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      arr[i][j] = randomizer(1, 100);
    }
  }
}

void printMatrix(uint16_t arr[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0;

  cout<<"This is a 3 by 3 randomly generated matrix:\n";
  
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      cout<<setw(3)<<arr[i][j]<<'\t';
    }
    cout<<'\n';
  }
}

uint16_t sumCols(uint16_t arr[3][3], uint16_t cols, uint16_t colNumber)
{
  uint16_t i = 0, sum = 0;

  for (i = 0; i < cols; i++) {
    sum += arr[i][colNumber];
  }

  return (sum);
}

void printCols(uint16_t arr[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0;

  cout<<"The following are the sum of each column in the matrix:\n";
  
  for (i = 0; i < cols; i++) {
    cout<<" Cols "<<(i + 1)<<" sum = "<<sumCols(arr, rows, i)<<"\n";
  }
}

int main(void)
{
  srand(unsigned(time(nullptr)));
  
  uint16_t arr[3][3];

  fillArray(arr, 3, 3);
  printMatrix(arr, 3, 3);
  printCols(arr, 3, 3);
  
  return (0);
}

