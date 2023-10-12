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

string lower_all_letters_of_word(string sentence)
{
    for (short i = 0; i < sentence.length(); i++)
    {
        sentence[i] = tolower(sentence[i]);
    }

    return sentence;
}

string upper_all_letters_of_word(string sentence)
{
    for (short i = 0; i < sentence.length(); i++)
    {
        sentence[i] = toupper(sentence[i]);
    }

    return sentence;
}

int main()
{
    string sentence = read_string();

    cout << "Lower Sentence:" << endl << lower_all_letters_of_word(sentence) << endl;
    cout << "Upper Sentence:" << endl << upper_all_letters_of_word(sentence) << endl;
}
