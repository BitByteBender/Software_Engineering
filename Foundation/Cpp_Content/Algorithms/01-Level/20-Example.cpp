#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;
using std::string;

uint16_t* ReadPositiveNumber(string Message)
{
	uint16_t* ptrNum = new uint16_t(2);

	cout << Message;
	cin >> *ptrNum;

	return (ptrNum);
}

short Randomizer(short From, short To)
{
	short RandNum = rand() % (To - From + 1) + From;
	return (RandNum);
}

string GenerateKey(uint16_t KeyTweaker, uint16_t KeyLength)
{
	string Key = "";
	uint16_t i = 0, j = 0;

	for (i = 1; i <= KeyLength; i++)
	{
		for (j = 1; j <= KeyTweaker; j++)
		{
			Key += char(Randomizer(97, 122));
		}

		if (i < KeyLength)
		{
			Key += '-';
			continue;
		}
	}

	return (Key);
}

void PrintGeneratedKeys(uint16_t NumberOfGeneratedKeys, uint16_t KeyTweaker, uint16_t KeyLength)
{
	uint16_t i;

	for (i = 1; i <= NumberOfGeneratedKeys; i++)
	{
		cout << "Key [" << i << "]: " << GenerateKey(KeyTweaker, KeyLength)<< endl;
	}
}

int main(void)
{
	srand((unsigned)time(NULL));

	uint16_t* Num = ReadPositiveNumber("Enter numberof keys to be generated: ");

	PrintGeneratedKeys(*Num, 4, 4);
	delete Num;
	return (0);
}
