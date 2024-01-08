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

int main(void)
{
  uint16_t arr[3][3];

  fillArrayInOrder(arr, 3, 3);
  print3by3Matrix(arr, 3, 3);
  
  return (0);
}

