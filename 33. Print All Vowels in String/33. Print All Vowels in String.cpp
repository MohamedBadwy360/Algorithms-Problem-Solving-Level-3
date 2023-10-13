#include <string>
#include <iostream>

using namespace std;

string read_string()
{
    string sentence;
    cout << "Enter a string: \n";
    getline(cin, sentence);

    return sentence;
}

bool is_vowel(char character)
{
    character = tolower(character);

    return (character == 'a' || character == 'e' || character == 'i' || character == 'u' || character == 'o');
}

void print_vowels(string sentence)
{
    cout << "Vowel Characters: \n";

    for (short i = 0; i < sentence.length(); i++)
    {
        if (is_vowel(sentence[i]))
            cout << sentence[i] << "  ";
    }

    cout << endl;
}

int main()
{
    print_vowels(read_string());
}
