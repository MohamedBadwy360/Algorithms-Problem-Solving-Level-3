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

void lower_first_letter_of_each_word(string sentence)
{
    bool is_first_letter = true;

    for (short i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] != ' ' && is_first_letter)
        {
            sentence[i] = tolower(sentence[i]);
        }

        is_first_letter = (sentence[i] == ' ') ? true : false;
    }

    cout << sentence << endl;
}

int main()
{
    lower_first_letter_of_each_word(read_string());
}
