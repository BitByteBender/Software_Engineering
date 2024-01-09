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

uint16_t sumOfmatrix(uint16_t arr[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0, sum = 0;

  for (i = 0; i <= (rows - 1); i++) {
    for (j = 0; j <= (cols - 1); j++) {
      sum += arr[i][j];
    }
  }

  return (sum);
}

void printSum(uint16_t sum)
{
  cout<<"Sum of matrix is: "<<sum<<endl;
}

int main(void)
{
  srand(unsigned(time(nullptr)));
  
  uint16_t matrix[3][3];

  arrFiller(matrix, 3, 3);
  printMatrix(matrix, 3, 3, "Matrix:\n");

  printSum(sumOfmatrix(matrix, 3, 3));
  return (0);
}
