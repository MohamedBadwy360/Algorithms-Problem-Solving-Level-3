#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int random_number(int from, int to)
{
    return (rand() % (to - from + 1) + from);
}

void fill_matrix_with_random_number(int arr[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            arr[i][j] = random_number(1, 100);
        }
    }
}

void print_matrix(int arr[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << setw(3) << arr[i][j] << " ";
        }

        cout << endl;
    }
}

bool is_number_exist(int arr[3][3], short rows, short cols, int number)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (arr[i][j] == number)
                return true;
        }
    }

    return false;
}

void print_intersected_numbers(int arr1[3][3], int arr2[3][3], short rows, short cols)
{
    cout << "\nIntersected Numbers is :\n";

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (is_number_exist(arr2, 3, 3, arr1[i][j]))
                cout << arr1[i][j] << "  ";
        }
    }

    cout << endl;
}

int main()
{
    srand(unsigned(time(NULL)));

    int arr1[3][3], arr2[3][3];

    fill_matrix_with_random_number(arr1, 3, 3);
    cout << "Matrix 1:\n";
    print_matrix(arr1, 3, 3);

    fill_matrix_with_random_number(arr2, 3, 3);
    cout << "\nMatrix 2:\n";
    print_matrix(arr2, 3, 3);

    cout << "\n===============";
    print_intersected_numbers(arr1, arr2, 3, 3);


    return 0;
}

