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

int min_number_in_matrix(int arr[3][3], short rows, short cols)
{
    int min_number = arr[0][0];

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (min_number > arr[i][j])
                min_number = arr[i][j];
        }
    }

    return min_number;
}

int max_number_in_matrix(int arr[3][3], short rows, short cols)
{
    int max_number = arr[0][0];

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (max_number < arr[i][j])
                max_number = arr[i][j];
        }
    }

    return max_number;
}

int main()
{
    srand(unsigned(time(NULL)));

    int arr[3][3];

    fill_matrix_with_random_number(arr, 3, 3);
    print_matrix(arr, 3, 3);

    cout << "\n=============\n";
    cout << "Min Number: " << min_number_in_matrix(arr, 3, 3) << endl;
    cout << "Max Number: " << max_number_in_matrix(arr, 3, 3) << endl;

    return 0;
}
