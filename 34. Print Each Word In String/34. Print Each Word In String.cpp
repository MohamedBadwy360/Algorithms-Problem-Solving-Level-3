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

void print_each_word_in_string(string sentence)
{
    string delim = " ";
    string word;

    short pos = 0;

    while ((pos = sentence.find(delim)) != std::string::npos)
    {
        word = sentence.substr(0, pos);

        if(word != "")
            cout << word << endl;

        sentence.erase(0, pos + delim.length());
    }

    if (sentence != "")
        cout << sentence << endl;
}

int main()
{
    print_each_word_in_string(read_string());
}
