#include <iostream>
#include <cstdlib>

using namespace std;

enum en_equality {not_equal, equal};

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

en_equality check_matrices_equality(int arr1[3][3], int arr2[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (arr1[i][j] != arr2[i][j])
                return en_equality::not_equal;
        }
    }

    return en_equality::equal;
}

void is_matrices_equality(int arr1[3][3], int arr2[3][3], short rows, short cols)
{
    switch (check_matrices_equality(arr1, arr2, rows, cols))
    {
        case en_equality::equal:
            cout << "Metrices are equal.\n";
            break;
        case en_equality::not_equal:
            cout << "Metrices aren't equal.\n";
            break;
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

int main()
{
    srand(unsigned(time(NULL)));

    int arr1[3][3], arr2[3][3];

    cout << "Matrix 1:\n";
    fill_matrix_with_random_number(arr1, 3, 3);
    print_matrix(arr1, 3, 3);

    cout << "\nMatrix 2:\n";
    fill_matrix_with_random_number(arr2, 3, 3);
    print_matrix(arr2, 3, 3);

    is_matrices_equality(arr1, arr1, 3, 3);
    is_matrices_equality(arr1, arr2, 3, 3);

    return 0;
}

