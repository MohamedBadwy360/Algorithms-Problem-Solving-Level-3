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

bool is_matrix_identity(int arr[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (i == j)
            {
                if (arr[i][j] != 1)
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
    srand(unsigned(time(NULL)));

    int arr[3][3];
    fill_matrix_with_random_number(arr, 3, 3);
    print_matrix(arr, 3, 3);

    is_matrix_identity(arr, 3, 3);

    cout << "================\n";
    cout << "For Random Matrix: \n";
    
    if (is_matrix_identity(arr, 3, 3))
        cout << "Yes, it is idenetity.\n";
    else
        cout << "No, it is not identity.\n";

    int I[3][3] = 
    {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    cout << "================\n";
    cout << "For Idenetity Matrix: \n";

    if (is_matrix_identity(I, 3, 3))
        cout << "Yes, it is idenetity.\n";
    else
        cout << "No, it is not identity.\n";

}
