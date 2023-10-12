#include <iostream>
#include <string>

using namespace std;

string read_string()
{
    string sentence;
    cout << "Enter you string: \n";
    getline(cin, sentence);

    return sentence;
}

char invert_character_case(char character)
{
    if (isupper(character))
        return tolower(character);
    else
        return toupper(character);
}

string invert_all_string_characters_case(string sentence)
{
    for (int i = 0; i < sentence.length(); i++)
    {
        sentence[i] = invert_character_case(sentence[i]);
    }
    
    return sentence;
}

int main()
{
    cout << "\nInverted string is: \n" << invert_all_string_characters_case(read_string()) << endl;
}
