#include <iostream>
#include <string>

using namespace std;

char read_character()
{
    char character;
    cout << "Enter a character: \n";
    cin >> character;

    return character;
}

char invert_character_case(char character)
{
    if (isupper(character))
        return tolower(character);
    else
        return toupper(character);
}

int main()
{
    cout << "\nInverted Character is: \n" << invert_character_case(read_character()) << endl;
}
