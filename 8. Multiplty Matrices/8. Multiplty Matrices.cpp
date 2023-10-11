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
            arr[i][j] = random_number(1, 10);
        }
    }
}

void print_matrix(int arr[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            printf("%0*d ", 2, arr[i][j]);
        }

        cout << endl;
    }
}

void multiply_matrices(int arr1[3][3], int arr2[3][3], int result[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            result[i][j] = arr1[i][j] * arr2[i][j];
        }
    }
}

int main()
{
    srand(unsigned(time(NULL)));

    int arr1[3][3], arr2[3][3], result[3][3];

    cout << "Matrix 1:\n";
    fill_matrix_with_random_number(arr1, 3, 3);
    print_matrix(arr1, 3, 3);

    cout << "\nMatrix 2:\n";
    fill_matrix_with_random_number(arr2, 3, 3);
    print_matrix(arr2, 3, 3);

    cout << "\nResult of Multiplication:\n";
    multiply_matrices(arr1, arr2, result, 3, 3);
    print_matrix(result, 3, 3);

    return 0;
}
