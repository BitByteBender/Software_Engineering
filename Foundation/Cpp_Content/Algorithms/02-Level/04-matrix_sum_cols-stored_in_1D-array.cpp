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

void fillArr(uint16_t arr[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = i;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      arr[i][j] = randomizer(1, 100);
    }
  }
}

void print3by3Matrix(uint16_t arr[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = i;

  cout<<"This is a randomly generated 3 by 3 matrix:\n";
  
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      cout<<setw(3)<<arr[i][j]<<'\t';
    }
    cout<<'\n';
  }
  
  cout<<endl;
}

uint16_t sumCols(uint16_t arr[3][3], uint16_t rows, uint16_t colIdx)
{
  uint16_t i = 0, sum = 0;

  for (i = 0; i < rows; i++) {
    sum += arr[i][colIdx];
  }

  return (sum);
}

void storeSumCols(uint16_t arr[3][3], uint16_t newArr[3], uint16_t rows)
{
  uint16_t i = 0;

  for (i = 0; i < rows; i++) {
    newArr[i] = sumCols(arr, rows, i);
  }
}

void printOneDimArray(uint16_t newArr[3], uint16_t length)
{
  uint16_t j = 0;
  
  cout<<"The following is the sum of each column of a randomly generated 3 by 3 matrix retrieved from a 1D array:\n";

  for (j = 0; j < length; j++) {
    cout<<" Cols "<<(j + 1)<<" sum = "<<newArr[j]<<'\n';
  }

  cout<<endl;
}

int main(void)
{
  srand(unsigned(time(nullptr)));

  uint16_t arr[3][3];
  uint16_t newArr[3];

  fillArr(arr, 3, 3);
  print3by3Matrix(arr, 3, 3);
  storeSumCols(arr, newArr, 3);
  printOneDimArray(newArr, 3);
  
  return (0);
}
