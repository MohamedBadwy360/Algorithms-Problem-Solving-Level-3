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

short count_number_in_matrix(int arr[3][3], short rows, short cols, int number)
{
    short counter = 0;

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (arr[i][j] == number)
                counter++;
        }
    }

    return counter;
}

int main()
{
    srand(unsigned(time(NULL)));

    int arr[3][3]; 

    fill_matrix_with_random_number(arr, 3, 3);
    print_matrix(arr, 3, 3);

    cout << "==========\n\n";
    cout << "Count is: " << count_number_in_matrix(arr, 3, 3, read_number_from_to(1, 10)) << endl;

    return 0;
}
