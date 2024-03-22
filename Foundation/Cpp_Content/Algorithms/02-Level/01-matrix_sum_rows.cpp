#include <iostream>
#include <ctime>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

inline uint16_t randomizeNumbers(uint16_t from, uint16_t to)
{
  return (rand() % (to - from + 1) + from);
}

void fillArr(uint16_t arr[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      arr[i][j] = randomizeNumbers(1, 100);
    }
  }
}

void printMatrix(uint16_t arr[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0;

  cout <<"This a 3 by 3 randomly generated matrix:\n";
  
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      cout<<setw(3)<<arr[i][j]<<'\t';
      if (j == (cols - 1)) {
	cout<<'\n';
	break;
      }
    }
  }
  cout<<endl;
}


uint16_t sumRows(uint16_t arr[3][3], uint16_t rowNumber, uint16_t cols)
{
  uint16_t j = 0, sum = 0;


  for (j = 0; j < cols; j++) {
    sum += arr[rowNumber][j];
  }

  return (sum);
}

void printRows(uint16_t arr[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0;

  cout<<"The following are the sum of each row in the matrix:\n";
  
  for (i = 0; i < rows; i++) {
    cout<<" Row"<<(i + 1)<<" sum = ";
    cout<<sumRows(arr, i, cols)<<"\n";

  }
}

int main(void)
{
  srand(unsigned(time(nullptr)));

  uint16_t arr[3][3];

  fillArr(arr, 3, 3);
  printMatrix(arr, 3, 3);
  printRows(arr, 3, 3);
  
  return (0);
}

