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

void print_each_row_sum(int arr[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        int sum = 0;
        cout << "Row " << i + 1 << " sum = ";

        for (short j = 0; j < cols; j++)
        {
            sum += arr[i][j];
        }

        cout << sum << endl;
    }
}

int main()
{
    srand(unsigned(time(NULL)));

    int arr[3][3];

    fill_matrix_with_random_number(arr, 3, 3);

    cout << "The following is the matrix:\n";
    print_matrix(arr, 3, 3);

    cout << "\nThe following are sum of all rows in the matrix: \n";
    print_each_row_sum(arr, 3, 3);

    return 0;
}
