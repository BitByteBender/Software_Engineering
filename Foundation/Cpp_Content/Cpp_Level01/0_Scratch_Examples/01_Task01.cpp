#include <iostream>

using std::cout;
using std::endl;

int main()
{
  short num1{5}, num2{6}, num3{2};

  int arr[3];

  if (num1 >= num2 && num1 >= num3) {
    arr[0] = num1;
    if(num2 >= num3){
      arr[1] = num2;
      arr[2] = num3;
    }else{
      arr[1] = num3;
      arr[2] = num2;
    }
  }else if(num2 >= num1 && num2 >= num3){
    arr[0] = num2;
    if(num1 >= num3){
      arr[1] = num1;
      arr[2] = num3;
    }else{
      arr[1] = num3;
      arr[2] = num1;
    }
  }else{
    arr[0] = num3;
    arr[2] = num2;
    arr[3] = num1;
  }

  cout<<"Sorted array: "<<arr[0]<<"\n"<<arr[1]<<"\n"<<arr[2]<<endl;
  return 0;
}
