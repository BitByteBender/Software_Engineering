#include "headers/clsutil.hpp"

int main(void)
{
  clsUtil::Srand();

  cout<<clsUtil::RandomNumber(1, 10)<<endl;

  cout<<clsUtil::GetRandomCharacter(clsUtil::SmallLetter)<<endl;
  cout<<clsUtil::GetRandomCharacter(clsUtil::CapitalLetter)<<endl;
  cout<<clsUtil::GetRandomCharacter(clsUtil::Digit)<<endl;
  cout<<clsUtil::GetRandomCharacter(clsUtil::MixedChars)<<endl;
  cout<<clsUtil::GetRandomCharacter(clsUtil::SpecialChars)<<endl;

  cout<<clsUtil::GenerateWord(clsUtil::MixedChars, 8)<<endl;
  cout<<clsUtil::GenerateKey(clsUtil::MixedChars)<<endl;
  clsUtil::GenerateKeys(10, clsUtil::MixedChars);

  uint16_t X = 5, Y = 10;
  cout<<"[Before Swapping]>X: "<<X<<" | Y: "<<Y<<'\n';
  clsUtil::Swap(X, Y);
  cout<<"[After Swapping]>X: "<<X<<" | Y: "<<Y<<'\n';

  string str1 = "Soufiane", str2 = "Sdgl";
  cout<<"[Before Swapping]>str1: "<<str1<<" | str2: "<<str2<<'\n';
  clsUtil::Swap(str1, str2);
  cout<<"[After Swapping]>str1: "<<str1<<" | str2: "<<str2<<'\n';

  char ch1 = 'A', ch2 = 'Z';
  cout<<"[Before Swapping]>ch1: "<<ch1<<" | ch2: "<<ch2<<'\n';
  clsUtil::Swap(ch1, ch2);
  cout<<"[After Swapping]>ch1: "<<ch1<<" | ch2: "<<ch2<<'\n';

  float A = 9.45f, B = 63.71f;
  cout<<"[Before Swapping]>A: "<<A<<" | B: "<<B<<'\n';
  clsUtil::Swap(A, B);
  cout<<"[After Swapping]>A: "<<A<<" | B: "<<B<<'\n';

  double C = 59.4524, D = 263.7154;
  cout<<"[Before Swapping]>C: "<<C<<" | D: "<<D<<'\n';
  clsUtil::Swap(C, D);
  cout<<"[After Swapping]>C: "<<C<<" | D: "<<D<<'\n';

  str1 = "31/1/2013", X = 250, Y = 2025;
  clsDate Date1(str1), Date2(X, Y);
  cout<<"[Before Swapping]>Date1: "<<Date1.DateToString()<<" | Date2: "<<Date2.DateToString()<<'\n';
  clsUtil::Swap(Date1, Date2);
  cout<<"[After Swapping]>Date1: "<<Date1.DateToString()<<" | Date2: "<<Date2.DateToString()<<'\n';

  uint16_t Arr[5] = {100, 25, 13, 44, 7};
  clsUtil::ShuffleArray(Arr, 5);
  cout<<"Array After shufle:\n";
  for (X = 0; X < 5; ++X) cout<<Arr[X]<<endl;

  string Arr1[5] = { "Soufiane", "Nasr", "Abdo", "Ali", "Ahmed"};
  clsUtil::ShuffleArray(Arr1, 5);
  cout<<"Array After shufle:\n";
  for (X = 0; X < 5; ++X) cout<<Arr1[X]<<endl;

  uint16_t Arr2[6];
  clsUtil::FillArrayWithRandomNums(Arr2, 6);
  cout<<"Array filler with random nums:\n";
  for (X = 0; X < 6; ++X) cout<<Arr2[X]<<endl;

  uint16_t Arr3[5];
  clsUtil::FillArrayWithRandomNums(Arr3, 5, 25, 75);
  cout<<"Array filler with random nums:\n";
  for (X = 0; X < 5; ++X) cout<<Arr3[X]<<endl;

  string Arr4[4];
  clsUtil::FillArrayWithRandomWords(Arr4, 4, clsUtil::MixedChars, 5);
  cout<<"Array filler with random words:\n";
  for (X = 0; X < 4; ++X) cout<<Arr4[X]<<endl;

  string Arr5[5];
  clsUtil::FillArrayWithRandomKeys(Arr5, 5, clsUtil::MixedChars);
  cout<<"Array filler with random keys:\n";
  for (X = 0; X < 5; ++X) cout<<Arr5[X]<<endl;

  cout<<"\nText1 "<<clsUtil::Spaces(10)<<"Text2\n";
  cout<<"\nText1 "<<clsUtil::Tabs(5)<<"Text2\n";

  string TextAfterEncryption, TextAfterDecryption, Text = "Hello this is me!";
  const short EncryptionKey = 2;
  TextAfterEncryption = clsUtil::EncryptText(Text, EncryptionKey);
  TextAfterDecryption = clsUtil::DecryptText(Text, EncryptionKey);
  cout<<"Text: "<<Text
      <<" | After Encryption: "<<TextAfterEncryption
      <<" | After Decryption: "<<TextAfterDecryption<<endl;
  
  return (0);
}
