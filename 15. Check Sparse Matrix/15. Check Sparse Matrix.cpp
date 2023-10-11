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
            cout << setw(3) << arr[i][j] << " ";
        }

        cout << endl;
    }
}

bool is_sparse_matrix(int arr[3][3], short rows, short cols)
{
    short zero_counter = 0;
    short numbers_counter = 0;

    for(short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (arr[i][j] == 0)
                zero_counter++;
            else
                numbers_counter++;
        }
    }

    return (zero_counter > numbers_counter);
}

int main()
{
    srand(unsigned(time(NULL)));

    int arr[3][3];
    fill_matrix_with_random_number(arr, 3, 3);
    print_matrix(arr, 3, 3);

    //int arr2[3][3] = { {0, 0, 1}, {0, 0, 2}, {0, 0, 3} };

    cout << "================\n";

    if (is_sparse_matrix(arr, 3, 3))
        cout << "Yes, it is sparse.\n";
    else
        cout << "No, it is not sparse.\n";

    return 0;
}

