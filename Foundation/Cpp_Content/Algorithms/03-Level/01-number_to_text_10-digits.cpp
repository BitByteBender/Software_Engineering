#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;
using std::stoi;

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

uint16_t digitsCheck(unsigned long long &num)
{
  uint16_t i = 0, count = to_string(num).length(), dgtCount = 0;
  string str = to_string(num);

  for (i = 0; i < count; ++i) {
    dgtCount += str[i];
  }

  return (dgtCount);
}

uint16_t checkOriginalNum(unsigned long long originalNum)
{
  uint16_t i = 0, count = 0;

  for (i = 0; i < to_string(originalNum).length(); ++i) {
    count++;
  }

  return (count);
}

string convertNumToText(unsigned long long num)
{
  uint16_t digits = digitCount(num), dgt = 0, nextDgt = 0, prevDgt = 0, tailDgt = 0, headDgt = num;
  unsigned long long Remaining = 0, originalNum = num;
  bool unlock = true, lock = true;
  
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
      */
      if (digits < 10 && digits >= 7) {
	if (digits == 9 && dgt != 0) {
	  Text += patterns[0][dgt - 1] + "-hundred";
	  digits--;
	  dgt = num / pow(10, digits - 1);
	  lock = false;
	}
	
	if (digits == 8 && dgt >= 1) {
	  num = calc(num, Remaining, digits);
	  digits--;
	  nextDgt = num / pow(10, digits - 1);

	  if (lock == false) {
	    Text += " and ";
	  }
	  
	  if (nextDgt != 0 && dgt > 1) {
	    Text += patterns[2][dgt - 1] + '-' + patterns[0][nextDgt-1];
	  } else if (nextDgt != 0 && dgt == 1) {
	    Text += patterns[1][nextDgt - 1];
	  } else {
	    Text += patterns[2][dgt - 1];
	  }
	  lock = false;
	  dgt = nextDgt;
	  continue;
	}

	if (digits == 7) {
	  if (lock == true && dgt != 0) {
	    Text += patterns[0][dgt - 1];
	    lock = false;
	  }
	  Text += " Million";
	  num = calc(num, Remaining, digits);
	  digits--;
	  dgt = num / pow(10, digits - 1);
	}
      }
      
      if (digits < 7 && digits >= 4) {
	if (checkOriginalNum(originalNum) > 6 && digitsCheck(num) != 48 && lock == false) {
	  Text += " and ";
	  lock = true;
	}
	if (digits == 6 && dgt != 0) {
	  uint16_t next_nextDgt;
	  unsigned long long temp;

	  temp = calc(num, Remaining, (digits - 1));
	  next_nextDgt = temp / pow(10, digits - 3);
	  Text += patterns[0][dgt - 1] + "-hundred";
	  
	  if (prevDgt == 0 && next_nextDgt != 0) {
	      Text += " and ";
	      unlock = false;
	  }
	} else {
	  if (digits == 5 && dgt >= 1) {

	    
	    if (prevDgt != 0 && unlock == true) {
	      Text += " and ";
	    }
	    
	    digits--;
	    nextDgt = num / pow(10, digits - 1);
	    if (dgt == 1 && nextDgt != 0) {
	      Text += patterns[1][nextDgt - 1] + " Thousands";
	      num = calc(num, Remaining, digits);
	      nextDgt = 0;
	    } else {
	      Text += patterns[2][dgt - 1];
	      digits++;
	    }
	  } else {
	    
	    if (dgt != 0 && digits == 4) {
	      //problem
	      if (prevDgt != 0) {
		Text += "-" + patterns[0][dgt - 1] + " Thousands";
	      } else
		Text += patterns[0][dgt - 1] + " Thousands";

	    } else {
	      if (digits == 4 && prevDgt != 0) {
		Text += " Thousands";
	      }
	    }
	  }
	}
	//end
	prevDgt = dgt;
      }

      uint16_t hlen = to_string(headDgt).length();
      
      if (digits == 3 && dgt >= 1) {
	if (hlen > 3 || prevDgt != 0) {
	  Text += ' ';
	}
      
	Text += patterns[0][dgt - 1] + " Hundred";
      }
    } else {

      prevDgt = dgt, tailDgt = num % 10;

      if (prevDgt == 0 && tailDgt == 0) {
	digits = 0;
	break;
      }


      uint16_t hlen = to_string(headDgt).length();
      
      if (hlen > 2  && (checkOriginalNum(originalNum) < 7 || checkOriginalNum(originalNum) == 9)) {
	Text +=  " and ";
	headDgt = 0;
      }

      if (digits == 2 && dgt >= 1) {
	if (dgt >= 2) {
	  Text += patterns[2][dgt - 1];
	  digits--;
	  dgt = num / pow(10, digits - 1);
	  if (dgt != 0)
	    Text += '-' + patterns[0][dgt - 1];
	} else {
	  digits--;
	  dgt = num / pow(10, digits - 1);
	  if (dgt == 0) {
	    Text += "Ten";
	  } else {
	    Text += patterns[1][dgt - 1];
	  }
	  
	}
      } else {
	if (digits == 1 && dgt != 0) {
	  Text += patterns[0][dgt - 1]; 
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
