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

void printSum(uint16_t sum, const char *Msg)
{
  cout<<Msg<<sum<<endl;
}

inline bool checkMatricesEquality(uint16_t matrix1Sum, uint16_t matrix2Sum)
{
  return (matrix1Sum == matrix2Sum);
}

void printResult(uint16_t sumOfmatrix1, uint16_t sumOfmatrix2)
{
  if (checkMatricesEquality(sumOfmatrix1, sumOfmatrix2)) {
    cout<<"\nYes: matrices are equal."<<endl;
  } else {
    cout<<"\nNo: matrices are Not equal."<<endl;
  }
}

int main(void)
{
  srand(unsigned(time(nullptr)));
  
  uint16_t matrix1[3][3], matrix2[3][3];
  uint16_t sumOfmatrix1{0}, sumOfmatrix2{0};
  
  arrFiller(matrix1, 3, 3);
  printMatrix(matrix1, 3, 3, "Matrix 1:\n");

  arrFiller(matrix2, 3, 3);
  printMatrix(matrix2, 3, 3, "Matrix 2:\n");

  sumOfmatrix1 = sumOfmatrix(matrix1, 3, 3);
  sumOfmatrix2 = sumOfmatrix(matrix2, 3, 3);
  
  printSum(sumOfmatrix1, "sum of matrix 1 is: ");
  printSum(sumOfmatrix2, "sum of matrix 2 is: ");
  
  printResult(sumOfmatrix1, sumOfmatrix2);
  return (0);
}
