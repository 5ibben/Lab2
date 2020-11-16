#include <iostream>
#include <lab2lib.h>
using namespace std;

int main()
{
    const int defaultArrayLenght = 10;
    int shrinkMe[defaultArrayLenght] = { 4,2,-5,11,3,3 };
    bool loop = true;
    while (loop)
    {
        cout << "\n\nmenu:\n"
            << "1 : task 1\n"
            << "2 : task 2\n"
            << "3 : task 3\n"
            << "4 : task 4\n"
            << "5 : task 5\n"
            << "6 : task 6\n"
            << "0 : exit\n"
            << "\nWhich task would you like to run ? ";

        int input;
        cin >> input;
        switch (input)
        {
            case 1:
                //input task.1 palindrome
                cout << "\nEnter a word to see if it is a palindrome: ";
                char toPalindrome[defaultArrayLenght];
                cin >> toPalindrome;
                if (is_palindrome(toPalindrome)==1)
                    cout <<"\n"<<toPalindrome<<" is a palindrome!";
                else
                    cout << "\n" << toPalindrome << " is not a palindrome!";
                break;
            case 2:
                //input task.2 is_sorted
                cout << "\n" << "Enter a number to see if it is in ascending order: ";
                char toSorted[defaultArrayLenght];
                int toSortedInt[defaultArrayLenght];
                cin >> toSorted;
                copyArray(toSorted, toSortedInt, defaultArrayLenght);
                if (is_sorted(toSortedInt) == 1)
                    cout << "\n" << toSorted << " is in ascending order!";
                else
                    cout << "\n" << toSorted << " is not in ascending order!";
                break;
            case 3:
                //input task.3 Print 2D int array with rows/columns
                int rows;
                int columns;
                cout << "\nPrint a 2D array\n\nEnter number of rows(max 20): ", cin >> rows;
                cout << "Enter number of columns(max 20): ", cin >> columns;
                if (rows < 21 && columns < 21)
                {
                    int intArray2D[21][21];	//21x21 array
                    for (int a = 0; a < 21; a++)
                    {
                        for (int b = 0; b < 21; b++)
                        {
                            if (a < rows && b < columns)
                                intArray2D[a][b] = rand() % 10;
                            else
                                intArray2D[a][b] = 10;
                        }
                    }
                    array_rows_cols(intArray2D);
                }
                else
                    cout << "\nCome back when you ready to follow the rules!";
                break;
            case 4:
                //input task.4 Swap sort (pass-by-reference)
                cout << "\nSort some numbers, ABC.\n";
                while (true)
                {
                    cout << "\nGive a number A(0 to quit): "; int a; cin >> a;
                    if (a == 0)
                        break;
                    cout << "Give a number B: "; int b; cin >> b;
                    cout << "Give a number C: "; int c; cin >> c;
                    cout << "Sort ascending / descending(1 / 0) :"; bool d; cin >> d;
                    swap_sort(a, b, c, d);
                    cout << "\nResult: " << a << b << c << "\n";
                }
                break;
            case 5:
                //input task.5 shrink
                cout << "before shrinkage: ";
                print_array(shrinkMe, defaultArrayLenght);
                shrink_array(shrinkMe);
                cout << "after shrinkage: ";
                print_array(shrinkMe, defaultArrayLenght);
                break;
            case 6:
                database();
                break;
            case 0:
                cout << "\nGood bye!\n";
                loop = false;
                break;
            default:
                cout << "\nSorry, there is no such task!";
                break;
        }
    }
}