#include <iostream>
#include <string>

using namespace std;

string read_string()
{
    string sentence;
    cout << "Enter a string: \n";
    getline(cin, sentence);

    return sentence;
}

string remove_punctuations(string sentence)
{
    string new_sentence = "";
    for (short i = 0; i < sentence.length(); i++)
    {
        if (! ispunct(sentence[i]))
            new_sentence += sentence[i];
    }

    return new_sentence;
}

int main()
{
    cout << remove_punctuations(read_string()) << endl;
}
