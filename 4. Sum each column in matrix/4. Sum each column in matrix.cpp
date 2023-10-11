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
    cout << "Matrix: \n";

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << setw(3) << arr[i][j] << " ";
        }

        cout << endl;
    }
}

int sum_col(int arr[3][3], short rows, short col_number)
{
    int sum = 0;
    for (short i = 0; i < rows; i++)
    {
        sum += arr[i][col_number];
    }

    return sum;
}

void print_col_sum(int arr[3][3], short rows, short cols)
{
    cout << "\nThis is the sum of columns: \n";

    for (short j = 0; j < cols; j++)
    {
        cout << "Col " << j + 1 << " sum = " << sum_col(arr, rows, j) << endl;;
    }
}

int main()
{
    srand(unsigned(time(NULL)));

    int arr[3][3];

    fill_matrix_with_random_number(arr, 3, 3);
    print_matrix(arr, 3, 3);

    print_col_sum(arr, 3, 3);

    return 0;
}
