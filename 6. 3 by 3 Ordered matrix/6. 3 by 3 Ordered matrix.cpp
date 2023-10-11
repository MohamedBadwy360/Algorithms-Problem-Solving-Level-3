#include <iostream>
#include <iomanip>

using namespace std;

void fill_matrix_with_ordered_numbers(int arr[3][3], short rows, short cols)
{
    short num = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            arr[i][j] = ++num;
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


int main()
{
    int arr[3][3];

    fill_matrix_with_ordered_numbers(arr, 3, 3);
    print_matrix(arr, 3, 3);
}

