#include <iostream>
#include "headers/clsmisc.hpp"
#include "headers/clsdate.hpp"


int main(void)
{
  clsMisc s1("15,30,2022");

  for (const uint16_t &v:s1.Split(",")) {
    cout<<v<<'\n';
  }

  string Val = "31/1/2025";
  uint16_t D = 15, M = 1, Y = 2023;
  clsDate D1, D2(Val), D3(D, M, Y), D4;
  
  cout<<D1.getDay()<<'/'<<D1.getMonth()<<'/'<<D1.getYear()<<'\n';
  D1.Print();
  D2.Print();
  cout<<D2.getDay()<<'\n';
  D3.Print();

  Val = "31* /25/#2022";
  for (const string &d:clsMisc::DelimFinder(Val)) {
    cout<<d<<'\n';
  }
  
  for (const uint16_t &v:clsMisc::SplitAdv("31+# 200* /20233")) {
    cout<<v<<'\n';
  }

  D4.setVal("550+# 52  /2044");
  
  for (const uint16_t &v:D4.SplitAdv()) {
    cout<<v<<'\n';
  }

  cout<<"Leap Year Checker:\n";
  uint16_t i = 0;
  string ValY = "";
  
  for (i = 0; i < 20; ++i) {
    ValY = to_string(stoi(D4.getYear()) + i);
    D4.setYear(ValY);
    cout<<stoi(D4.getYear())<<": "<<clsDate::isLeap(stoi(D4.getYear()))<<'\n';
  }

  i = 0;
  cout<<D4.getYear()<<'\n';

  for (i = 0; i < 20; ++i) {
    ValY = to_string(stoi(D4.getYear()) + i);
    D4.setYear(ValY);
    cout<<stoi(D4.getYear())<<": "<<clsDate::isLeap(stoi(D4.getYear()))<<" | Feb: "<<clsDate::getFebDays(stoi(D4.getYear()))<<'\n';
  }

  i = 1;
  ValY = "2368";
  D4.setYear(ValY);
  
  for (; i <= 12; ++i) {
    cout<<D4.getYear()<<" | Month("<<i<<"): "<<clsDate::getDaysInMonth(i, stoi(D4.getYear()))<<'\n';
  }

  cout<<"Leap\n";
  cout<<"Month: "<<D4.DaysIntoMonths(60, stoi(D4.getYear()))<<'\n';
  cout<<"Days left: "<<D4.RemainingDays(60, stoi(D4.getYear()))<<'\n';
  cout<<"Month: "<<D4.DaysIntoMonths(126, stoi(D4.getYear()))<<'\n';
  cout<<"Days left: "<<D4.RemainingDays(126, stoi(D4.getYear()))<<'\n';
  cout<<"Month: "<<D4.DaysIntoMonths(61, stoi(D4.getYear()))<<'\n';
  cout<<"Days left: "<<D4.RemainingDays(61, stoi(D4.getYear()))<<'\n';
  cout<<"Month: "<<D4.DaysIntoMonths(58, stoi(D4.getYear()))<<'\n';
  cout<<"Days left: "<<D4.RemainingDays(58, stoi(D4.getYear()))<<'\n';
  cout<<"Month: "<<D4.DaysIntoMonths(59, stoi(D4.getYear()))<<'\n';
  cout<<"Days left: "<<D4.RemainingDays(59, stoi(D4.getYear()))<<'\n';
  cout<<"Month: "<<D4.DaysIntoMonths(62, stoi(D4.getYear()))<<'\n';
  cout<<"Days left: "<<D4.RemainingDays(62, stoi(D4.getYear()))<<'\n';
  cout<<"not leap\n";
  cout<<"Month: "<<D4.DaysIntoMonths(60, 2025)<<'\n';
  cout<<"Days left: "<<D4.RemainingDays(60, 2025)<<'\n';
  cout<<"Month: "<<D4.DaysIntoMonths(126, 2025)<<'\n';
  cout<<"Days left: "<<D4.RemainingDays(126, 2025)<<'\n';
  cout<<"Month: "<<D4.DaysIntoMonths(61, 2025)<<'\n';
  cout<<"Days left: "<<D4.RemainingDays(61, 2025)<<'\n';
  cout<<"Month: "<<D4.DaysIntoMonths(58, 2025)<<'\n';
  cout<<"Days left: "<<D4.RemainingDays(58, 2025)<<'\n';
  cout<<"Month: "<<D4.DaysIntoMonths(59, 2025)<<'\n';
  cout<<"Days left: "<<D4.RemainingDays(59, 2025)<<'\n';
  cout<<"Month: "<<D4.DaysIntoMonths(62, 2025)<<'\n';
  cout<<"Days left: "<<D4.RemainingDays(62, 2025)<<'\n';

  uint16_t Days = 250, Year = 2022;
  clsDate D5(Days, Year);
  D5.Print();
  
  cout<<D5.GregorianCalc()<<'\n';

  string Dd = "10", Mm = "3", Yy = "2025";
  D5.setDay(Dd), D5.setMonth(Mm), D5.setYear(Yy);
  cout<<clsDate::GregorianCalc(&D5)<<'\n';
  cout<<D5.IsValid()<<'\n';
  
  Dd = "17", Mm = "3", Yy = "2025";
  D5.setDay(Dd), D5.setMonth(Mm), D5.setYear(Yy);
  cout<<clsDate::GregorianCalc(&D5)<<'\n';
  cout<<D5.IsValid()<<'\n';
  
  Dd = "16", Mm = "3", Yy = "2025";
  D5.setDay(Dd), D5.setMonth(Mm), D5.setYear(Yy);
  cout<<clsDate::GregorianCalc(&D5)<<'\n';
  cout<<D5.IsValid()<<'\n';
    
  Dd = "32", Mm = "12", Yy = "2025";
  D5.setDay(Dd), D5.setMonth(Mm), D5.setYear(Yy);
  cout<<clsDate::GregorianCalc(&D5)<<'\n';
  cout<<D5.IsValid()<<'\n';

  Dd = "29", Mm = "2", Yy = "2025";
  D5.setDay(Dd), D5.setMonth(Mm), D5.setYear(Yy);
  cout<<clsDate::GregorianCalc(&D5)<<'\n';
  cout<<D5.IsValid()<<'\n';

  Dd = "28", Mm = "2", Yy = "2025";
  D5.setDay(Dd), D5.setMonth(Mm), D5.setYear(Yy);
  cout<<clsDate::GregorianCalc(&D5)<<'\n';
  cout<<D5.IsValid()<<'\n';

  Dd = "29", Mm = "2", Yy = "2368";
  D5.setDay(Dd), D5.setMonth(Mm), D5.setYear(Yy);
  cout<<clsDate::GregorianCalc(&D5)<<'\n';
  cout<<D5.IsValid()<<'\n';
  
  Dd = "31", Mm = "1", Yy = "2025";
  D5.setDay(Dd), D5.setMonth(Mm), D5.setYear(Yy);
  cout<<clsDate::GregorianCalc(&D5)<<'\n';
  cout<<D5.IsValid()<<'\n';

  Dd = "29", Mm = "0", Yy  = "2025";
  D5.setDay(Dd), D5.setMonth(Mm), D5.setYear(Yy);
  cout<<clsDate::GregorianCalc(&D5)<<'\n';
  cout<<D5.IsValid()<<'\n';

  Dd = "29", Mm = "13", Yy = "2025";
  D5.setDay(Dd), D5.setMonth(Mm), D5.setYear(Yy);
  cout<<clsDate::GregorianCalc(&D5)<<'\n';
  cout<<D5.IsValid()<<'\n';

  D = 28, M = 12, Y = 2025;
  clsDate *ptr = new clsDate(D, M, Y);
  cout<<clsDate::GregorianCalc(ptr)<<'\n';
  delete ptr;
  
  return (0);
}
