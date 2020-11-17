#include <iostream>
#include <lab2lib.h>
using namespace std;

    /*
        If you´re reading this, let me excuse myself in advance, I know it´s kind of messy, I´m sorry! :).
        There may be some stupid stuff going on down below. This is mainly to comply with lab instructions.
        However, the functionality is there, and in accordance to instructions!
       
       //Sebastian Näslund.
    */

int main()
{
    cout << "\nWelcome to lab 2.\nPlease be careful with input!\n";

    //Some variable declaration/assignment. To be used in function inputs.
    const int defaultArrayLenght = 11;
    int shrinkMe[defaultArrayLenght] = { 5, 5, 7, 6, 2, 2, 11, 11, 5, 4 };
    int shrinkMe2[defaultArrayLenght] = { 5, 5, 7, 6, 2, 2, 11, 11, 5 };
    bool loop = true;
    int input;
    
    //Menu loop
    while (loop)
    {   
        //Prints menu
        cout << "\nmenu:\n"
            << "1 : task 1  Palindrome check.\n"
            << "2 : task 2  Ascending number check\n"
            << "3 : task 3  Print 2D Array\n"
            << "4 : task 4  Swap Sort\n"
            << "5 : task 5  Shrink an array\n"
            << "6 : task 6  Name database\n"
            << "0 : exit\n"
            << "\nWhich task would you like to run ? ";

        //User menu input
        cin >> input;
        switch (input)
        {
            case 1: //Task.1 palindrome
                cout << "\nEnter a word to see if it is a palindrome: ";
                //input
                char toPalindrome[defaultArrayLenght];
                cin >> toPalindrome;
                //output
                if (is_palindrome(toPalindrome)==1)
                    cout <<"\n"<<toPalindrome<<" is a palindrome!\n";
                else
                    cout << "\n" << toPalindrome << " is not a palindrome!\n";
                break;

            case 2: //Task.2 is_sorted
                cout << "\n" << "Enter a number to see if it is in ascending order: ";
                //input
                char toSorted[defaultArrayLenght];
                int toSortedInt[defaultArrayLenght];
                cin >> toSorted;
                //input convertion
                copyArray(toSorted, toSortedInt, defaultArrayLenght);
                //output
                if (is_sorted(toSortedInt) == 1)
                    cout << "\n" << toSorted << " is in ascending order!\n";
                else
                    cout << "\n" << toSorted << " is not in ascending order!\n";
                break;

            case 3: //Task.3 Print 2D int array with rows/columns
                int rows;
                int columns;
                //input
                cout << "\nPrint a 2D array\n\nEnter number of rows(max 20): ", cin >> rows;
                cout << "Enter number of columns(max 20): ", cin >> columns;

                if (rows < 21 && columns < 21)//input handling
                {
                    int intArray2D[21][21];	//21x21 array, max input=20, function is dependent of unassigned elements.
                    for (int a = 0; a < 21; a++)
                    {
                        for (int b = 0; b < 21; b++)//Assigns psuedo-random numbers to specified row/column lengths.
                        {
                            if (a < rows && b < columns)
                                intArray2D[a][b] = rand() % 10;
                            else
                                intArray2D[a][b] = 10;
                        }
                    }
                    array_rows_cols(intArray2D);//function call
                }
                else
                    cout << "\nCome back when you are ready to follow the rules!\n";
                break;

            case 4://Task.4 Swap sort (pass-by-reference)
                cout << "\nSort some numbers, ABC.\n";
                //input loop
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

            case 5://Task.5 shrink (arrays are assigned at top of script.)
                cout << "\nArray1 before shrinkage: ";
                print_array(shrinkMe, defaultArrayLenght);//before
                shrink_array(shrinkMe);//Shrinks array
                cout << "Array1 after shrinkage: ";
                print_array(shrinkMe, defaultArrayLenght);//after

                cout << "\nArray2 before shrinkage: ";
                print_array(shrinkMe2, defaultArrayLenght);//before
                shrink_array(shrinkMe2);//Shrinks array
                cout << "Array2 after shrinkage: ";
                print_array(shrinkMe2, defaultArrayLenght);//after
                
                shrink_array(shrinkMe2);//Shrinks array
                cout << "\nArray2 after another shrinkage: ";
                print_array(shrinkMe2, defaultArrayLenght);//after
                break;

            case 6://Task.6 Database 
                database();
                break;

            case 0:// Exit
                cout << "\nGood bye!\n";
                loop = false;//exits menu loop
                break;

            default://invalid task number
                cout << "\nSorry, there is no such task!";
                break;
        }
    }
}