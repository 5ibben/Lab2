#include <iostream>
using namespace std;
#include <string>
#include <array>
#include <cstdlib>

bool is_sorted(int *arr);
bool is_palindrome(char* cArray);
int array_rows_cols(int array[21][21]);
void swap_sort(int& a, int& b, int& c, bool ascending);
void shrink_array(int* array);
void print_array(int* array, int len);

int getArrayLength(char intArr[]);
int getArrayLength(int intArr[]);
int copyArray(char* fromArray, int* toArray, int arrayLength);
int copyArray(int* fromArray, char* toArray, int arrayLength);
int main()
{
	const int defaultArrayLenght = 10;
	
	
	//input task.1 palindrome
	cout << "Enter a word to see if it´s a palindrome: ";
	char toPalindrome[defaultArrayLenght];
	cin >> toPalindrome;
	cout << is_palindrome(toPalindrome);

	//input task.2 is_sorted
	cout<<"\n\n"<< "Enter a number to see if it is in ascending order: ";
	char toSorted[defaultArrayLenght];
	int toSortedInt[defaultArrayLenght];
	cin >> toSorted;
	copyArray(toSorted, toSortedInt, defaultArrayLenght);
	cout << is_sorted(toSortedInt);
	

	//input task.3 Print 2D int array with rows/columns
	int rows;
	int columns;
	cout << "\n\nEnter number of rows(max 20): ", cin >> rows;
	cout << "Enter number of columns(max 20): ", cin >> columns;

	int intArray2D[21][21];	//21x21 array
	for (int a =0; a < 21; a++)
	{
		for (int b = 0; b < 21; b++)
		{
			if (a < rows && b < columns)
				intArray2D[a][b] = rand()%10;
			else
				intArray2D[a][b] = 10;
		}
	}

	array_rows_cols(intArray2D);
	

	//input task.4 Swap sort (pass-by-reference)
	int inputs[3];
	int i = 0;
	while (true)
	{
		cout << "\nGive a (0 to quit): "; int a; cin >> a;
		if (a == 0)
			break;
		cout << "Give b: "; int b; cin >> b;
		cout << "Give c: "; int c; cin >> c;
		cout << "Sort ascending / descending(1 / 0) :"; bool d; cin >> d;
		swap_sort(a, b, c, d);
		cout << "\nResult: " << a << b << c<<"\n";
	}
	

	//input task.5 shrink
	int shrinkMe[defaultArrayLenght] = { 4,2,-5,11,3,3 };
	cout << "before shrinkage: ";
	print_array(shrinkMe, defaultArrayLenght);
	shrink_array(shrinkMe);
	cout << "after shrinkage: ";
	print_array(shrinkMe,defaultArrayLenght);

	return 0;
}

void print_array(int* array,int len)
{
	int i = 0;
	while (i < len)
	{
		cout << array[i];
		i++;
	}
	cout << "\n";
}

void shrink_array(int *array)
{
	
	int len = getArrayLength(array);
	int i = 0;
	while (array[i*2] != *"\0")
	{
		array[i] = array[i*2] + array[i*2+1];
		i++;
	}
	int j = i;
	while (j < len)
	{
		array[j] = 0;
		j++;
	}
}


void swap_sort(int &a, int &b, int &c, bool ascending)
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
	while (array[a][0]!=10)
	{
		int rowsum = 0;
		int b = 0;
		while (array[a][b] != 10)
		{
			rowsum += array[a][b];
			columnsum[b] += array[a][b];
			cout << array[a][b]<<"  ";
			b++;
		}
		cout <<" "<<rowsum<< "\n";
		a++;
	}
	cout << "\n";
	for (int b = 0; array[0][b] != 10; b++)
	{
		cout<< columnsum[b]<<" ";
	}
	cout << "\n";
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