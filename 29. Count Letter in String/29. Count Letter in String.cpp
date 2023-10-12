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

short count_letter_in_string(string sentence, char character)
{
    int counter = 0;
    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] == character)
            counter++;
    }

    return counter;
}

int main()
{
    string sentence = read_string();
    char character = read_character();

    cout << "Count of " << character << " in string is: " << count_letter_in_string(sentence, character) << endl;
}

