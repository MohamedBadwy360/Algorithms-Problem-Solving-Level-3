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

int sum_col(int arr[3][3], short rows, short col_number)
{
    int sum = 0;
    for (short i = 0; i < rows; i++)
    {
        sum += arr[i][col_number];
    }

    return sum;
}

void put_each_col_sum_in_array(int arr[3][3], int sum_arr[3], short rows, short cols)
{
    for (short j = 0; j < cols; j++)
    {
        sum_arr[j] = sum_col(arr, rows, j);
    }
}

void print_sum_array(int sum_arr[3], short length)
{
    cout << "\nThe following is the some of the matrix: \n";

    for (int i = 0; i < length; i++)
    {
        cout << "Col " << i + 1 << " sum = " << sum_arr[i] << endl;
    }
}

int main()
{
    srand(unsigned(time(NULL)));

    int arr[3][3], sum_arr[3];

    fill_matrix_with_random_number(arr, 3, 3);
    print_matrix(arr, 3, 3);

    put_each_col_sum_in_array(arr, sum_arr, 3, 3);
    print_sum_array(sum_arr, 3);

    return 0;
}
