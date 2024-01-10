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
      arr[i][j] = NumberRandomizer(0, 1);
    }
  }
}

void printMatrix(uint16_t arr[3][3], uint16_t rows, uint16_t cols, const char *Msg)
{
  uint16_t i = 0, j = 0;

  cout<<Msg;

  for (i = 0; i <= (rows - 1); i++) {
    for (j = 0; j <= (cols - 1); j++) {
      cout<<arr[i][j]<<'\t';
    }
    cout<<'\n';
  }
  cout<<endl;
}

bool isIdentity(uint16_t matrix[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0;

   for (i = 0; i <= (rows - 1); i++) {
    for (j = 0; j <= (cols - 1); j++) {
      if (j == i)
	continue;
      
      if (matrix[i][i] != 1 || matrix[i][j] != 0) {
        return (false);
      }
      cout<<"(i:i) = "<<matrix[i][i]<<" | (i:j) "<<matrix[i][j]<<" | (j = "<<j<<")\n  ";
    }
    cout<<'\n';
   }
   
  return (true);
}

void printResult(uint16_t matrix[3][3])
{
  if (isIdentity(matrix, 3, 3)) {
    cout<<"\nYes: matrices is identity."<<endl;
  } else {
    cout<<"\nNo: matrices are Not identity ."<<endl;
  }
}

int main(void)
{
  srand(unsigned(time(nullptr)));
  
  uint16_t matrix[3][3];
  uint16_t matrixTest[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  
  arrFiller(matrix, 3, 3);
  printMatrix(matrix, 3, 3, "Matrix:\n");
  printResult(matrix);

  cout<<"\n"<<endl;
  
  printMatrix(matrixTest, 3, 3, "Matrix for testing:\n");
  printResult(matrixTest);
  
  return (0);
}
