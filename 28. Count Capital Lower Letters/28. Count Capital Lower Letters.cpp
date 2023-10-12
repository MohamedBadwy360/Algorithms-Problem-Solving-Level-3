#include <string>
#include <iostream>

using namespace std;

string read_string()
{
    string sentence;
    cout << "Enter you string: \n";
    getline(cin, sentence);

    return sentence;
}

short count_upper_letters(string sentence)
{
    short counter = 0;

    for (short i = 0; i < sentence.length(); i++)
    {
        if (isupper(sentence[i]))
            counter++;
    }

    return counter;
}

short count_lower_letters(string sentence)
{
    short counter = 0;

    for (short i = 0; i < sentence.length(); i++)
    {
        if (islower(sentence[i]))
            counter++;
    }

    return counter;
}

int main()
{
    string sentence = read_string();

    cout << "String length: " << sentence.length() << endl;
    cout << "String upper letter count: " << count_upper_letters(sentence) << endl;
    cout << "String lower letter count: " << count_lower_letters(sentence) << endl;

    return 0;
}

