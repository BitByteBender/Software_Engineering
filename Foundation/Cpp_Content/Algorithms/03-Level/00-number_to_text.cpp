#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;

unsigned long long readNumber(const char *Msg)
{
  unsigned long long num{0};

  cout<<Msg;
  cin>>num;

  return (num);
}

uint16_t digitCount(unsigned long long num)
{
  return (to_string(num).length()); 
}

unsigned long long calc(unsigned long long num, unsigned long long Remaining, uint16_t digits)
{
  Remaining = (num % unsigned(pow(10, digits - 1)));
  return (num = Remaining);
}

string convertNumToText(unsigned long long num)
{
  uint16_t digits = digitCount(num), dgt = 0, nextDgt = 0, prevDgt = 0;
  unsigned long long Remaining = 0;
  string patterns[3][10] = {
    {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eigth", "Nine"},
    {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"},
    {"Ten", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}
  };
  string Text;

  while (digits != 0) {
    dgt = num / pow(10, digits - 1);
    num = calc(num, Remaining, digits);
    
    if (!(digits < 3)) {
      /*
      if (digits >= 10) {
	Text += + " Billion ";
      }

      if (digits < 10 && digits >= 7) {
	Text += + " Million ";
      }
      */
      if (digits < 7 && digits >= 4) {
	if (digits == 6) {
	  Text += patterns[0][dgt - 1] + "-hundred ";
	} else {
	  if (digits == 5 && dgt >= 1) {
	    cout<<num<<'\n';
	    digits--;
	    nextDgt = num / pow(10, digits - 1);
	    cout<<nextDgt<<'\n'<<dgt<<'\n'<<num<<'\n';
	    if (dgt == 1 && nextDgt != 0) {
	      Text += patterns[1][nextDgt - 1] + " Thousands ";
	      num = calc(num, Remaining, digits);
	      cout<<dgt<<'\n'<<num<<'\n'<<digits<<'\n';
	      nextDgt = 0;
	    } else {
	      Text += patterns[2][dgt - 1];
	      digits++;
	    }
	  } else {
	    if (dgt != 0 && digits == 4) {
	      if (nextDgt != 0) {
		Text += '-' + patterns[0][dgt - 1] + " Thousands ";
	      } else
		Text += patterns[0][dgt - 1] + " Thousands ";

	    } else {
	      if (digits == 4)
		Text += " Thousands ";
	    }
	  }
	}
      }

      if (digits == 3 && dgt >= 1) {
	Text += patterns[0][dgt - 1] + " Hundred ";
      }
    } else {
      if (digits == 2 && dgt >= 1) {
	if (dgt >= 2) {
	  Text += "and ";
	  Text += patterns[2][dgt - 1];
	  digits--;
	  dgt = num / pow(10, digits - 1);
	  if (dgt != 0)
	    Text += '-' + patterns[0][dgt - 1]; 
	} else {
	  digits--;
	  dgt = num / pow(10, digits - 1);
	  if (dgt == 0) {
	    Text += "and Ten";
	  } else {
	    Text += patterns[1][dgt - 1];
	  }
	  
	}
      } else {
	if (digits == 1 && dgt != 0) {
	  Text += " and " + patterns[0][dgt - 1]; 
	}
      }
    }

    digits--;
  }
  
  return (Text);
}

int main(void)
{
  unsigned long long num = readNumber("Enter a number: ");
  cout<<convertNumToText(num)<<'\n';
  return (0);
}
