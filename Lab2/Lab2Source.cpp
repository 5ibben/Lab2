#include <iostream>
using namespace std;
#include <string>
#include <array>

bool is_sorted(int *arr);
bool is_palindrome(char* cArray);

int getArrayLength(char intArr[]);
int getArrayLength(int intArr[]);
int copyArray(char* fromArray, int* toArray, int arrayLength);
int copyArray(int* fromArray, char* toArray, int arrayLength);
int main()
{
	const int defaultArrayLenght = 20;
	
	//input task.1 palindrome
	cout << "Enter a word to see if it´s a palindrome: ";
	char toPalindrome[defaultArrayLenght];
	cin >> toPalindrome;
	cout << is_palindrome(toPalindrome);

	//input task.2 is_sorted
	cout<<"\n"<< "Enter a number to see if it is in ascending order: ";
	char toSorted[defaultArrayLenght];
	int toSortedInt[defaultArrayLenght];
	cin >> toSorted;
	copyArray(toSorted, toSortedInt, defaultArrayLenght);
	cout << is_sorted(toSortedInt);

	//input task.3

	
	return 0;
}

int copyArray(char* fromArray, int* toArray,int arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		toArray[i] = fromArray[i];
	}
	return 0;
}
int copyArray(int* fromArray, char* toArray, int arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		toArray[i] = fromArray[i];
	}
	return 0;
}

int getArrayLength(char intArr[])
{
	int i = 0;
	while (intArr[i] != *"\0")
	{
		i++;
	}
	return i;
}
int getArrayLength(int intArr[])
{
	int i = 0;
	while (intArr[i] != *"\0")
	{
		i++;
	}
	return i;
}

bool is_sorted(int *arr)
{
	for (int i = 1; i < getArrayLength(arr); i++)
	{
		if (arr[i] <= arr[i - 1])
		{
			return false;
		}
	}
	return true;
}


bool is_palindrome(char *cArray)
{
	int i=0;
	int b=getArrayLength(cArray)-1;
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