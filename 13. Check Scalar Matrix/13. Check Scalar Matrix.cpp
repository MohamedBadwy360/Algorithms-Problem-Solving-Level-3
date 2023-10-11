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

bool is_matrix_scalar(int arr[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (i == j)
            {
                if (arr[i][j] != arr[0][0])
                    return false;
            }
            else
            {
                if (arr[i][j] != 0)
                    return false;
            }
        }
    }

    return true;
}

int main()
{
    //int arr[3][3] = { {5, 0, 0}, {0, 5, 0}, {0, 0, 5} };
    int arr[3][3] = { {10, 0, 0}, {0, 5, 0}, {0, 0, 5} };

    print_matrix(arr, 3, 3);

    cout << "==========\n";

    if (is_matrix_scalar(arr, 3, 3))
        cout << "Yes. Matrix is scalar.\n";
    else
        cout << "No. Matrix is not scalar.\n";

    return 0;
}

