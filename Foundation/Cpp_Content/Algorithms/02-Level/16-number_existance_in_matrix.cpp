#include <iostream>
#include<iomanip>
#include<ctime>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

uint16_t ReadNumber(const char *Msg)
{
  uint16_t num{0};

  cout<<Msg;
  cin>>num;

  return (num);
}

inline uint16_t randomizer(uint16_t from, uint16_t to)
{
  return (rand() % (to - from + 1) + from);
}

void matrixFiller(uint16_t matrix[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      matrix[i][j] = randomizer(0, 100);
    }
  }
}

void printMatrix(uint16_t matrix[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      cout<<setw(3)<<matrix[i][j]<<'\t';
    }
    cout<<'\n';
  }
  cout<<endl;
}

bool checkNum(uint16_t matrix[3][3], uint16_t rows, uint16_t cols, uint16_t num)
{
  uint16_t i = 0, j = 0;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      if (matrix[i][j] == num) {
	return (true);
      }
    }
  }

  return (false);
}

void printResult(uint16_t matrix[3][3], uint16_t rows, uint16_t cols, uint16_t num)
{
  if (checkNum(matrix, rows, cols, num)) {
    cout<<"Yes, number "<<num<<" exists in the matrix\n";
  } else {
    cout<<"No, number "<<num<<" does not exist\n";
  }
}

int main(void)
{
  srand(unsigned(time(NULL)));

  uint16_t matrix[3][3], num = 0;

  matrixFiller(matrix, 3, 3);
  printMatrix(matrix, 3, 3);

  num = ReadNumber("enter a number to check: ");
  printResult(matrix, 3, 3, num);
  return (0);
}
