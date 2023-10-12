#include <iostream>

using namespace std;

void fibonacci_sreies_using_recursion(short number, int num1, int num2)
{

    int next_number = 0;

    if (number > 0)
    {
        next_number = num1 + num2;
        num2 = num1;
        num1 = next_number;

        cout << next_number << " ";

        fibonacci_sreies_using_recursion(number - 1, num1, num2);
    }

    cout << endl;

}

int main()
{
    fibonacci_sreies_using_recursion(10, 0, 1);
}
