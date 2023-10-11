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

void print_middle_row(int arr[3][3], short rows, short cols)
{
    int middle_row = rows / 2;

    cout << "\nMiddle row:\n";

    for (int i = 0; i < cols; i++)
    {
        printf("%0*d ", 2, arr[middle_row][i]);
    }
    
    cout << endl;
}

void print_middle_col(int arr[3][3], short rows, short cols)
{
    int middle_col = cols / 2;

    cout << "\nMiddle col:\n";

    for (int i = 0; i < rows; i++)
    {
        printf("%0*d ", 2, arr[i][middle_col]);
    }

    cout << endl;
}

int main()
{
    srand(unsigned(time(NULL)));

    int arr[3][3];

    fill_matrix_with_random_number(arr, 3, 3);
    cout << "Matrix:\n";
    print_matrix(arr, 3, 3);

    print_middle_row(arr, 3, 3);

    print_middle_col(arr, 3, 3);

    return 0;
}
