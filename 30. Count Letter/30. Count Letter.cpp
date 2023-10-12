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

char read_character()
{
    char character;
    cout << "Enter a character: \n";
    cin >> character;

    return character;
}

short count_letter(string sentence, char character, bool match_case = true)
{
    int counter = 0;

    if (match_case)
    {
        for (int i = 0; i < sentence.length(); i++)
        {
            if (sentence[i] == character)
                counter++;
        }
    }
    else
    {
        for (int i = 0; i < sentence.length(); i++)
        {
            if (tolower(sentence[i]) == tolower(character))
                counter++;
        }
    }

    return counter;
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
    string sentence = read_string();
    char character = read_character();

    cout << "Count of '" << character << "' is: " << count_letter(sentence, character) << endl;
    cout << "Count of " << "'" << character << "'" << " and '" << invert_character_case(character) << "' is: ";
    cout << count_letter(sentence, character, false) << endl;
}
