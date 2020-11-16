#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include<vector>
using namespace std;


void print_array(int* array, int len)
{
	int i = 0;
	while (i < len)
	{
		cout << array[i];
		i++;
	}
	cout << "\n";
}

void shrink_array(int* array)
{
	int len = getArrayLength(array);
	int i = 0;
	while (array[i * 2] != *"\0")
	{
		array[i] = array[i * 2] + array[i * 2 + 1];
		i++;
	}
	int j = i;
	while (j < len)
	{
		array[j] = 0;
		j++;
	}
}


void swap_sort(int& a, int& b, int& c, bool ascending)
{
	int aTemp = a;
	int bTemp = b;
	int cTemp = c;
	if (ascending)
	{
		for (int i = 0; i < 2; i++)		//ascending
		{
			if (a > b)
			{
				a = b; b = aTemp;
				aTemp = a; bTemp = b;
			}
			if (b > c)
			{
				b = c; c = bTemp;
				bTemp = b;
			}
		}
	}
	else
	{
		for (int i = 0; i < 2; i++)		//descending
		{
			if (a < b)
			{
				a = b; b = aTemp;
				aTemp = a; bTemp = b;
			}
			if (b < c)
			{
				b = c; c = bTemp;
				bTemp = b;
			}
		}

	}
}

int array_rows_cols(int array[21][21])
{
	cout << "\n";
	int columnsum[21] = { 0 };
	int a = 0;
	while (array[a][0] != 10)
	{
		int rowsum = 0;
		int b = 0;
		while (array[a][b] != 10)
		{
			rowsum += array[a][b];
			columnsum[b] += array[a][b];
			cout << array[a][b] << "  ";
			b++;
		}
		cout << " " << rowsum << "\n";
		a++;
	}
	cout << "\n";
	for (int b = 0; array[0][b] != 10; b++)
	{cout << columnsum[b] << " ";}
	cout << "\n";
	return 0;
}

int copyArray(char* fromArray, int* toArray, int arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{toArray[i] = fromArray[i];}
	return 0;
}
int copyArray(int* fromArray, char* toArray, int arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{toArray[i] = fromArray[i];}
	return 0;
}

int getArrayLength(char intArr[])
{
	int i = 0;
	while (intArr[i] != *"\0")
	{i++;}
	return i;
}
int getArrayLength(int intArr[])
{
	int i = 0;
	while (intArr[i] != *"\0")
	{i++;}
	return i;
}

bool is_sorted(int* arr)
{
	for (int i = 1; i < getArrayLength(arr); i++)
	{
		if (arr[i] <= arr[i - 1])
		{return false;}
	}
	return true;
}

bool is_palindrome(char* cArray)
{
	int i = 0;
	int b = getArrayLength(cArray) - 1;
	while (i < b)
	{
		if (cArray[i] != cArray[b])
		{return false;}
		i++;
		b--;
	}
	return true;
}

void database()
{
	vector<string> v;
	string name;
	while (true)
	{
		cout << "\n1.initialize database\n"
			<< "2.insert\n"
			<< "3.search\n"
			<< "4.delete\n"
			<< "5.print\n"
			<< "6.quit\n\n"
			<< "Make your choice: ";
		int x;
		cin >> x;
		cout << "\n";
		//name input for option 2, 3, 4.
		if (x == 2 || x == 3 || x == 4)
		{
			cout << "Please enter name: ";
			cin >> name;
		}

		//1.initialize database
		if (x == 1)
		{
			cout << "This will erase all names from database. Proceed?(y/n) : ";
			char c;
			cin >> c;
			if (c == *"y")
				v.clear();
		}

		//2.insert
		if (x == 2)
		{
			v.push_back(name);
		}

		//3.search
		if (x == 3)
		{
			for (auto e : v)
			{
				if (!e.find(name))
				{
					cout << "\n" << e;
				}
			}
			cout << "\n";
		}

		//4.delete
		if (x == 4)
		{
			vector<string> vTemp;
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i] != name)
				{
					vTemp.push_back(v[i]);
				}
			}
			v = vTemp;
		}

		//5.print
		if (x == 5)
		{
			for (auto e : v)
			{
				cout << e << endl;
			}
		}

		//6.quit
		if (x == 6)
		{
			cout << "Good Bye!\n";
			break;
		}
	}
}