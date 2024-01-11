#include <iostream>
#include<ctime>

using std::cout;
using std::cin;
using std::endl;

uint16_t ReadNumber(const char *Msg)
{
  uint16_t Number{0};

  cout<<Msg;
  cin>>Number;

  return (Number);
}

inline uint16_t randomizer(uint16_t from, uint16_t to)
{
  return (rand() % (to - from + 1) + from);
}

void fillMatrix(uint16_t matrix[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0;

  for (i = 0; i <= (rows - 1); i++) {
    for (j = 0; j <= (cols - 1); j++) {
      matrix[i][j] = randomizer(0, 9);
    }
  }
}

void printMatrix(uint16_t matrix[3][3], uint16_t rows, uint16_t cols, const char *Msg)
{
  uint16_t i = 0, j = i;

  cout<<Msg;

  for (i = 0; i <= (rows - 1); i++) {
    for (j = 0; j <= (cols - 1); j++) {
      printf(" %d ", matrix[i][j]);
    }
    cout<<'\n';
  }
}

uint16_t countNum(uint16_t matrix[3][3], uint16_t rows, uint16_t cols, uint16_t &number)
{
  uint16_t i = 0, j = i, counter = 0 ;

  for (i = 0; i <= (rows - 1); i++) {
    for (j = 0; j <= (cols - 1); j++) {
      if (matrix[i][j] == number)
	++counter;
    }
  }

  return (counter);
}

void printResult(uint16_t matrix[3][3], uint16_t rows, uint16_t cols, uint16_t number)
{
  if (countNum(matrix, rows, cols, number)) {
    cout<<"Number "<<number<<" count is "<<countNum(matrix, rows, cols, number)<<'\n';
  } else {
    cout<<"No "<<number<<" does not exist in the matrix"<<'\n';
  }
  cout<<endl;
}

int main(void)
{
  srand(unsigned(time(nullptr)));

  uint16_t matrix[3][3], number = 0;
  
  fillMatrix(matrix, 3, 3);
  printMatrix(matrix, 3, 3, "Matrix:\n");
  
  number = ReadNumber("\nEnter a number to check: ");
  
  printResult(matrix, 3, 3, number);

  return (0);
}
