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

void print_first_letter_of_each_word(string sentence)
{
    cout << "\n===========================\n";
    cout << "First Letters Of Each Word:\n";

    bool is_first_letter = true;

    for (short i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] != ' ' && is_first_letter)
        {
            cout << sentence[i] << endl;
        }

        is_first_letter = (sentence[i] == ' ') ? true : false;
    }
}

int main()
{
    print_first_letter_of_each_word(read_string());
}
