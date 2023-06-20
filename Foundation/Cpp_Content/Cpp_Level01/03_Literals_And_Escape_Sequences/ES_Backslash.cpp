#include<iostream>

using std::cout;
using std::endl;

int main(){

   cout<<"A1\A2\n"; //Output: A1A2
   cout<<"A1\\A2"<<"\n"; //Output: A1\A2
   cout<<"A1\\A2\\A3\\A4"<<endl; //Output: A1\A2\A3\A4
   return 0;
}
