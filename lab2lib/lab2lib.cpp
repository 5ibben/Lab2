#include <iostream>
#include<vector>
using namespace std;


int copyArray(char* fromArray, int* toArray, int arrayLength)
{	//Converts a char array into an int array, by copying.
	for (int i = 0; i < arrayLength; i++)
	{toArray[i] = fromArray[i];}
	return 0;
}
int copyArray(int* fromArray, char* toArray, int arrayLength)
{	//Converts an int array into a char array, by copying.
	for (int i = 0; i < arrayLength; i++)
	{toArray[i] = fromArray[i];}
	return 0;
}


int getArrayLength(char intArr[])
{	//Get´s the number of assigned elements in an int array
	int i = 0;
	while (intArr[i] != *"\0")
	{i++;}
	return i;
}
int getArrayLength(int intArr[])
{	//Get´s the number of assigned elements in a char array
	int i = 0;
	while (intArr[i] != *"\0")
	{i++;}
	return i;
}


void print_array(int* array, int len)
{	//prints the elements of an integer array, up to the given lenght.

	int i = 0;
	while (i < len)
	{
		cout<< array[i] << " ";
		i++;
	}
	cout << "\n";
}

//Task.1
bool is_sorted(int* arr)
{	//Checks if an int array is in ascending order
	for (int i = 1; i < getArrayLength(arr); i++)
	{
		if (arr[i] <= arr[i - 1])
		{return false;}
	}
	return true;
}

//Task.2
bool is_palindrome(char* cArray)
{	//Checks if a char array is a palindrome
	int i = 0;
	int b = getArrayLength(cArray) - 1;
	while (i < b)//compares first letter of the word(i) to the last letter of the word(b), then increments (i) and decremets (b)
	{
		if (cArray[i] != cArray[b])
		{return false;}
		i++;
		b--;
	}
	return true;
}

//Task.3
int array_rows_cols(int array[21][21])
{	//Prints out an integer array of given rows and columns.

	cout << "\n";
	int columnsum[21] = { 0 };
	int a = 0;
	while (array[a][0] != 10)//Prints Row
	{
		int rowsum = 0;
		int b = 0;
		while (array[a][b] != 10)//Prints Column
		{
			rowsum += array[a][b];
			columnsum[b] += array[a][b];
			cout << array[a][b] << "  ";
			b++;
		}
		cout << " " << rowsum << "\n";//Adds the sum of a row at the end of that row.
		a++;
	}
	cout << "\n";
	for (int b = 0; array[0][b] != 10; b++)
	{cout << columnsum[b] << " ";}//Adds the sum of each column as a new row.
	cout << "\n";
	return 0;
}

//Task.4
void swap_sort(int& a, int& b, int& c, bool ascending)
{	//Swaps between the given integers a,b,c to order them in either ascending or descending order.

	int aTemp = a;
	int bTemp = b;
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

//Task.5
void shrink_array(int* array)
{	//shrinks an integer array, by adding adjecent values into one.

	int len = getArrayLength(array);
	int i = 0;
	while (array[i * 2] != *"\0")//Element addition
	{
		array[i] = array[i * 2] + array[i * 2 + 1];
		i++;
	}
	int j = i;//adds zeros at the end of new values.
	while (j < len)
	{
		array[j] = 0;
		j++;
	}
}

//Task.6
void database()
{
	vector<string> v;// this is the actual database
	string name;
	int x;

	//Database menu loop.
	while (true)
	{
		cout << "\n1.initialize database\n"
			<< "2.insert\n"
			<< "3.search\n"
			<< "4.delete\n"
			<< "5.print\n"
			<< "6.quit\n\n"
			<< "Make your choice: ";
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
		{	//Makes a copy of the database(v) into vTemp, excluding all eventual positions where the given name is found.
			vector<string> vTemp;
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i] != name)
				{
					vTemp.push_back(v[i]);
				}
			}
			v = vTemp;//assigns v to the new vector vTemp, which excludes the given name.
		}

		//5.print
		if (x == 5)
		{	//prints all elements of the database(vector v)
			for (auto e : v)
			{
				cout << e << endl;
			}
		}

		//6.quit
		if (x == 6)
		{
			break;
		}
	}
}