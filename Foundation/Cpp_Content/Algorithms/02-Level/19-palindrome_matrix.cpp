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

bool isPalindrome(uint16_t matrix[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0, start = 0, end = 0;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      start = matrix[i][j];
      end = matrix[i][cols - j - 1];
      if (start != end) {
	return (false);
      } else if (i == j)
	break;
    }
  }
  return (true);
}

void printResult(uint16_t matrix[3][3], uint16_t rows, uint16_t cols)
{
  if (isPalindrome(matrix, rows, cols)) {
    cout<<"Yes, matrix is a palindrome.\n";
  } else {
    cout<<"No, matrix is NOT a palindrome.\n";
  }
  cout<<endl;
}

int main(void)
{
  srand(unsigned(time(nullptr)));

  uint16_t matrix[3][3], matrixTest[3][3] = {{14, 5, 14}, {23, 75, 23}, {9, 2, 9}};

  fillMatrix(matrix, 3, 3);
  printMatrix(matrix, 3, 3);
  printResult(matrix, 3, 3);

  printMatrix(matrixTest, 3, 3);
  printResult(matrixTest, 3, 3);

  return (0);
}
