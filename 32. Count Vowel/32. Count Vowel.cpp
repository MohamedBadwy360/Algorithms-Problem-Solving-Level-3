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

short count_vowel(string sentence)
{
    short counter = 0;

    for (short i = 0; i < sentence.length(); i++)
    {
        if (is_vowel(sentence[i]))
            counter++;
    }

    return counter;
}

int main()
{
    cout << "Number of vowel characters in string is: " << count_vowel(read_string()) << endl;
}
