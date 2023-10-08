#include <iostream>

using std::cout;
using std::endl;
using std::cin;

enum enOperationType{Add = '+', Sub = '-', Div = '/', Multi = '*', Mod = '%'};

void ShowOperationTypes(){
  cout<<"Operation Type:";
  cout<<"\n******************\n"
     <<"(+) Addition\n"
     <<"(-) Substraction\n"
     <<"(/) Division\n"
     <<"(*) Multiplication\n"
     <<"(%) Modulo\n"
     <<"\n******************\n"
     <<endl;
}

unsigned short ReadNumber(std::string Message){
  short Num;
  
  cout<<Message;
  cin>>Num;

  return Num;
}

enOperationType ReadOperationType(){
  enOperationType Operation;

  char OperationPicker{'+'};
  cout<<"Choose your operation: ";
  cin>>OperationPicker;

  return Operation = (enOperationType)OperationPicker;
}

float CheckAndDoOperation(enOperationType Operation, unsigned short Num1, unsigned short Num2){

  switch (Operation) {
  case enOperationType::Add:
    return Num1 + Num2;
  case enOperationType::Sub:
    return Num1 - Num2;
  case enOperationType::Div:
    return float(Num1 / Num2);
  case enOperationType::Multi:
    return Num1 * Num2;
  case enOperationType::Mod:
    return Num1 % Num2;
  default:
    return 0;
  }

}

void PrintChoice(float Result){
  cout<<"Result: "<<Result<<endl;
}

int main()
{
  ShowOperationTypes();
  unsigned short Num1 = ReadNumber("Enter 1st number: ");
  unsigned short Num2 = ReadNumber("Enter 2nd number: ");
  PrintChoice(CheckAndDoOperation(ReadOperationType(), Num1, Num2));
  
  return 0;
}
