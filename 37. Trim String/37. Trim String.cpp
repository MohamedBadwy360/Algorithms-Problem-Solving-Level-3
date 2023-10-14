#include <iostream>
#include <string>

using namespace std;

string trim_left(string sentence)
{
    for (short i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] != ' ')
            return sentence.substr(i, sentence.length() - i);
    }

    return "";
}

string trim_right(string sentence)
{
    for (short i = sentence.length() - 1; i >= 0; i--)
    {
        if (sentence[i] != ' ')
            return sentence.substr(0, i + 1);
    }

    return "";
}

string trim(string sentence)
{
    return trim_left(trim_right(sentence));
}

int main()
{
    string sentence = "     Mohamed Badwy     ";
    cout << "Trim left: " << trim_left(sentence) << endl;
    cout << "trim right: " << trim_right(sentence) << endl;
    cout << "trim: " << trim(sentence) << endl;
}