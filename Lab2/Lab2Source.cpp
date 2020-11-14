#include <iostream>
using namespace std;
#include <string>
#include <array>

bool is_sorted(int len, int intArr[]);
bool is_palindrome(int len, char cArray[]);
int main()
{
	//Input for task 1
	/*
	string input;
	cin >> input;
	int intArray[20];
	int len = input.length();
	cout << "\n";
	for (int i = 0; i < len; i++)
	{
		intArray[i] = input[i]-48;
	}
	cout << is_sorted(len,intArray);
	*/

	//char cArray[20];
	//cin >> cArray;

	char car[20] = "maeam";
	int arrSize = sizeof(car) / sizeof(car[0]);
	cout<<is_palindrome(arrSize, car);
	

	
	return 0;
}


bool is_sorted(int len,int intArr[])
{
	for (int i = 1; i < len; i++)
	{
		cout << intArr[i]<<"\n";
		if (intArr[i]<=intArr[i-1])
		{
			return false;
		}
	}
	return true;
}

bool is_palindrome(int len, char *cArray)
{
	cout << len;
	int i=0;
	int b=len-1;
	while (i<b)
	{
		if (cArray[i]!=cArray[b])
		{
			return false;
		}
		i++;
		b--;
	}
	return true;
}