#include <iostream>
#include <string>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;

unsigned long long readNum(const char *Msg)
{
  unsigned long long number{0};

  cout<<Msg;
  cin>>number;

  return (number);
}

unsigned long long calculate(unsigned long long number, uint16_t digits)
{
  unsigned long long Remaining;

  Remaining = number % unsigned(pow(10, digits - 1));

  return (Remaining);
}

uint16_t restDigits(unsigned long long number)
{
  uint16_t i = 0, count = 0;
  string strNum = to_string(number);
  
  for (i = 0; i < to_string(number).length(); ++i) {
    count += strNum[i];
  }

  return (count);
}

string triggerOrdersOfMagnitude(uint16_t digits)
{
  string Text;
  
  switch (digits) {
  case (4):
  case (5):
  case (6):
    Text = "Thousands";
  break;
  case (7):
  case (8):
  case (9):
    Text = "Millions";
  break;
  case (10):
  case (11):
  case (12):
    Text = "Billion";
  break;
  case (13):
  case (14):
  case (15):
    Text = "Trillion";
  break;
  }

  return (Text);
}

string convertNumToText(unsigned long long number)
{
  uint16_t digits = to_string(number).length();
  string Text;
  string patterns[3][10] = {
    {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eigth", "Nine"},
    {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"},
    {"Ten", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}
  };
  
  while (digits != 0) {
    uint16_t tailDgt;
    uint16_t dgt;
    
    dgt = number / pow(10, digits - 1);

    uint16_t temp = digits;
    unsigned long long tempNum = number;
    bool lock = false;

    if (restDigits(number) == 48)
      lock = true;

    //cout<<"(Start)\n>>>>>> tempNum: "<<tempNum<<'\n';

    tempNum = calculate(tempNum, digits);
    temp = digits;
    temp--;
    tailDgt = tempNum / pow(10, temp - 1);

    if (Text.length() != 0 && Text[Text.length() - 1] != ' ') {
      Text += ' ';
    }

    /*
    cout<<">>>>>> temp: "<<temp<<'\n';
    cout<<">>>>>> tempNum: "<<tempNum<<'\n';
    cout<<">>>>>> Lock: "<<lock<<'\n';
    */
    number = calculate(number, digits);
    /*
    cout<<">>>>>> Comparison dgt: "<<dgt<<" | tailDgt: "<<tailDgt<<'\n';
    cout<<">>>>>> Digits: "<<digits<<'\n';
    cout<<">>>>>> (Digits + 2 % 3): "<<(digits + 2) % 3<<'\n';
    cout<<">>>>>> Num: "<<number<<"\n\n";
    */
    
    if (dgt > 1 && lock == false && (digits + 2) % 3 != 0 && digits % 3 != 0) {
      if (tailDgt == 0) {
	Text += patterns[2][dgt - 1];
      } else {
	Text += patterns[2][dgt - 1] + '-' + patterns[0][tailDgt - 1];
      }
      lock = true;
    } else if (dgt == 1 && lock == false && (digits + 2) % 3 != 0 && digits % 3 != 0) {
      if (tailDgt != 0) {
	Text += patterns[1][tailDgt - 1];
      } else {
	Text += "Ten";
      }
      lock = true;
    }
    /*
    cout<<">>>>>> Text: "<<Text<<'\n';
    cout<<">>>>>> Comparison dgt: "<<dgt<<" | tailDgt: "<<tailDgt<<'\n';
    */
    
    if (lock == true) {
      Text += ' ' + triggerOrdersOfMagnitude(digits);
      digits--;
      dgt = tailDgt;
      number = calculate(number, digits);
      digits--;
      // cout<<"-----> check\n";
      if (restDigits(number) == 48) {
	return (Text);
      } else
	continue;
    }
    /*
    cout<<">>>>>> Text: "<<Text<<'\n';
    cout<<">>>>>> num: "<<number<<" | tempNum: "<<tempNum<<'\n';
    cout<<">>>>>> Comparison dgt: "<<dgt<<" | tailDgt: "<<tailDgt<<'\n';
    cout<<">>>>>> Digits: "<<digits<<'\n';
    cout<<">>>>>> Lock: "<<lock<<'\n';
    */
    if (dgt != 0 && digits != 0) {
      Text += patterns[0][dgt - 1];
      
      if (digits % 3 == 0) {
	Text += "-hundred";
      }

      if ((digits == 4 || digits == 7 || digits == 10 || digits == 13) && number != 0) {
	Text += ' ' + triggerOrdersOfMagnitude(digits);
      }

    }
    

    if (restDigits(number) <= 59) {
      /*string Str, Delim = " Thousands ";
      short pos = Text.find(Delim);

      Str += Text.substr(0, pos);
      Text.clear();
      
      cout<<Str<<'\n';
      Text += Str + ' ' + "Thousands ";*/

      Text += " Thousands ";
      if (number != 0) {
	Text += patterns[0][number - 1];
      }
      return (Text);
    }

    /*
    cout<<"Text: "<<Text<<'\n';
    cout<<"2-dgt: "<<dgt<<" | tailDgt: "<<tailDgt<<"\n3-num: "<<number<<"\nlock: "<<lock<<'\n';
    cout<<"Digits: "<<digits<<" | Temp: "<<temp<<'\n';
    */
    
    if (Text[Text.length() - 1] != ' ' && restDigits(number) != 48) {
      //cout<<">>>"<<Text[Text.length() - 1]<<'\n';
      Text += ' ';
    }
    
    digits--;
  }
  
  return (Text);
}

void printConvertedText(unsigned long long number)
{
  cout<<convertNumToText(number)<<endl;
}

int main(void)
{
  unsigned long long num = readNum("Enter a number: ");
  printConvertedText(num);
  return (0);
}
