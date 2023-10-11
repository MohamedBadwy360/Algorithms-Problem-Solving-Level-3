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

void transpose_matrix(int arr[3][3], int transpose_arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose_arr[i][j] = arr[j][i];
        }
    }
}

int main()
{
    int arr[3][3], transpose_arr[3][3];

    cout << "Matrix:\n";
    fill_matrix_with_ordered_numbers(arr, 3, 3);
    print_matrix(arr, 3, 3);

    cout << "====================\n";

    cout << "Transpose:\n";
    transpose_matrix(arr, transpose_arr, 3, 3);
    print_matrix(transpose_arr, 3, 3);
    
    return 0;
}

