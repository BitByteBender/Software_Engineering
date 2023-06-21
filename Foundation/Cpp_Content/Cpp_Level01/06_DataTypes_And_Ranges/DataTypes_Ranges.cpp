#include <iostream>
#include <climits>
#include <cfloat>

using std::cout;
using std::endl;
using std::string;


int main()
{
  cout<<"int/signed int Range: ("<<INT_MIN<<", "<<INT_MAX<<")\n";
  cout<<"short int/signed short int Range: ("<<SHRT_MIN<<", "<<SHRT_MAX<<")\n";
  cout<<"long int/signed long int Range: ("<<LONG_MIN<<", "<<LONG_MAX<<")\n";
  cout<<"long long int/signed long long int Range: ("<<LLONG_MIN<<", "<<LLONG_MAX<<")\n";

  cout<<"unsigned int Range: ("<<0<<", "<<UINT_MAX<<")\n";
  cout<<"unsigned short int Range: ("<<0<<", "<<USHRT_MAX<<")\n";
  cout<<"unsigned long int Range: ("<<0<<", "<<ULONG_MAX<<")\n";
  cout<<"unsigned long long int Range: ("<<0<<", "<<ULLONG_MAX<<")\n";

  cout<<"char/signed char Range: ("<<CHAR_MIN<<", "<<CHAR_MAX<<")\n";
  cout<<"unsigned char Range: ("<<0<<", "<<UCHAR_MAX<<")\n";

  cout<<"float Range: ("<<FLT_MIN<<", "<<FLT_MAX<<")\n";
  cout<<"float(negative) Range: ("<<-FLT_MIN<<", "<<-FLT_MAX<<")\n";
  
  cout<<"double Range: ("<<DBL_MIN<<", "<<DBL_MAX<<")\n";
  cout<<"long double Range: ("<<LDBL_MIN_10_EXP<<", "<<LDBL_MAX_10_EXP<<")\n";
  cout<<"double(negative) Range: ("<<-DBL_MIN<<", "<<-DBL_MAX<<")\n";

  cout<<"bool Range: ("<<0<<", "<<1<<")\n";
  
  return 0;
}
