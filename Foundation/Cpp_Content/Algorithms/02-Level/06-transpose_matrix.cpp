#include <iostream>


using std::cout;
using std::endl;

void fillArrayInOrder(uint16_t arr[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0, counter = 1;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      arr[i][j] = counter;
      ++counter;
    }
  }
}

void print3by3Matrix(uint16_t arr[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0;

  cout<<"The following is an ordered 3 by 3 matrix:\n";
  
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      cout<<arr[i][j]<<'\t';
    }
    cout<<'\n';
  }

  cout<<endl;
}

void transposeMatrix(uint16_t arr[3][3], uint16_t transposed[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0;
  
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      transposed[i][j] = arr[j][i];
    }
    cout<<"\n";
  }
}

void printTransposedMatrix(uint16_t transposed[3][3], uint16_t rows, uint16_t cols)
{
  uint16_t i = 0, j = 0;

  cout<<"The following is a 3 by 3 transposed matrix:\n";
  
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      cout<<transposed[i][j]<<'\t';
    }
    cout<<"\n";
  }
}

int main(void)
{
  uint16_t arr[3][3], transposed[3][3];

  fillArrayInOrder(arr, 3, 3);
  print3by3Matrix(arr, 3, 3);
  transposeMatrix(arr, transposed, 3, 3);
  printTransposedMatrix(transposed, 3, 3);
  return (0);
}
