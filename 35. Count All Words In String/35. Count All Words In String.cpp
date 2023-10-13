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

short count_words_in_string(string sentence)
{
    string delim = " ";
    string word;

    short counter = 0;  // because of last word
    short pos = 0;

    while ((pos = sentence.find(delim)) != std::string::npos)
    {
        word = sentence.substr(0, pos);

        if (word != "")
            counter++;

        sentence.erase(0, pos + delim.length());
    }

    if (sentence != "")
        counter++;

    return counter;
}

int main()
{
    cout << "Number of word in string: \n" << count_words_in_string(read_string()) << endl;
}
