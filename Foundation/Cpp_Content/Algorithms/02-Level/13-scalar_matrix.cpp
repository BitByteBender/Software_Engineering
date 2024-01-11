#include <iostream>
#include<ctime>


using std::cout;
using std::endl;

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

bool isScalar(uint16_t matrix[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = i, temp = 0;

  for (i = 0; i <= (rows - 1); i++) {
    for (j = 0; j <= (cols - 1); j++) {
      temp = matrix[0][0];

      if (i == j)
	continue;
      
      if (matrix[i][i] != temp || matrix[i][j] != 0) {
	return (false);
      }

    }
  }

  return (true);
}

void printResult(uint16_t matrix[3][3], uint16_t rows, uint16_t cols)
{
  if (isScalar(matrix, rows, cols)) {
    cout<<"Yes: matrix is scalar\n";
  } else {
    cout<<"No: matrix is Not a scalar\n";
  }
  cout<<endl;
}

int main(void)
{
  srand(unsigned(time(nullptr)));

  uint16_t matrix[3][3];
  uint16_t matrixTest1[3][3] = {{9, 0, 0}, {0, 9, 0}, {0, 0, 9}};
  uint16_t matrixTest2[3][3] = {{9, 0, 9}, {0, 9, 0}, {0, 0, 9}};
  uint16_t matrixTest3[3][3] = {{9, 1, 9}, {0, 9, 0}, {0, 0, 9}};
  
  fillMatrix(matrix, 3, 3);
  printMatrix(matrix, 3, 3, "Matrix 1:\n");

  printResult(matrix, 3, 3);

  printMatrix(matrixTest1, 3, 3, "Matrix Test1:\n");
  printResult(matrixTest1, 3, 3);

  printMatrix(matrixTest2, 3, 3, "Matrix Test2:\n");
  printResult(matrixTest2, 3, 3);

  printMatrix(matrixTest3, 3, 3, "Matrix Test3:\n");
  printResult(matrixTest3, 3, 3);
  return (0);
}
