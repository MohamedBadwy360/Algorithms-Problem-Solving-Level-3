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

int read_number_from_to(int from, int to)
{
    int number = 0;
    do
    {
        cout << "Enter a number between " << from << " to " << to << ": " << endl;
        cin >> number;
    } while (number < from || number > to);

    return number;
}

bool is_number_exist(int arr[3][3], short rows, short cols, int number)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (arr[i][j] == number)
                return true;
        }
    }
    
    return false;
}

int main()
{
    srand(unsigned(time(NULL)));

    int arr[3][3];

    fill_matrix_with_random_number(arr, 3, 3);
    print_matrix(arr, 3, 3);

    cout << "\n=============\n\n";
    if (is_number_exist(arr, 3, 3, read_number_from_to(1, 100)))
        cout << "Yes. Number is exist.\n";
    else
        cout << "No. Number is not exist.\n";

    return 0;
}
