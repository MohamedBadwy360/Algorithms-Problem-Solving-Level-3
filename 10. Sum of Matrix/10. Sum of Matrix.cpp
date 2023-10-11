#include <iostream>
#include <cstdlib>

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

int sum_matrix(int arr[3][3], short rows, short cols)
{
    int sum = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            sum += arr[i][j];
        }
    }

    return sum;
}


int main()
{
    srand(unsigned(time(NULL)));

    int arr[3][3];

    fill_matrix_with_random_number(arr, 3, 3);
    print_matrix(arr, 3, 3);

    cout << "\nSum of matrix = " << sum_matrix(arr, 3, 3) << endl;

    return 0;
}

