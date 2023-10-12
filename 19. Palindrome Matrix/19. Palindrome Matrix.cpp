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

bool is_palindrome_matrix(int arr[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols / 2; j++)
        {
            if (arr[i][j] != arr[i][cols - 1 - j])
                return false;
        }
    }

    return true;
}

int main()
{
    srand(unsigned(time(NULL)));

    int arr[3][3];
    //int arr2[3][3] = { {1, 2, 1}, {3, 4, 3}, {5, 7, 5} };

    fill_matrix_with_random_number(arr, 3, 3);
    print_matrix(arr, 3, 3);

    if (is_palindrome_matrix(arr, 3, 3))
        cout << "Yes. It is palindrome.\n";
    else
        cout << "No. It is not palindrome.\n";

    return 0;
}