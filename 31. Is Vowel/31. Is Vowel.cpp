#include <string>
#include <iostream>

using namespace std;

char read_character()
{
    char character;
    cout << "Enter a character: \n";
    cin >> character;

    return character;
}

bool is_vowel(char character)
{
    character = tolower(character);

    return (character == 'a' || character == 'e' || character == 'i' || character == 'u' || character == 'o');
}

int main()
{
    char character = read_character();

    if (is_vowel(character))
        cout << "Yes. It is vowel.\n";
    else
        cout << "No. It is not vowel.\n";
}
