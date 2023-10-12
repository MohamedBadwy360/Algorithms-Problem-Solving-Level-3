#include <iostream>

using namespace std;

short read_number_from_to(short from, short to)
{
    short number = 0;
    do
    {
        cout << "Enter a number between " << from << " to " << to << ": " << endl;
        cin >> number;
    } while (number < from || number > to);

    return number;
}

void fibonacci_sreies(short number)
{
    int num1 = 1;
    int num2 = 1;
    int next_number = 0;

    cout << num1 << " " << num2 << " ";

    for (int i = 1; i <= number - 2; i++)
    {
        next_number = num1 + num2;
        num1 = num2;
        num2 = next_number;

        cout << next_number << " ";
    }

    cout << endl;

}

int main()
{
    fibonacci_sreies(read_number_from_to(1, 10));

    return 0;
}

