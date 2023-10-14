#include <iostream>
#include <string>
#include <vector>

using namespace std;

string read_string()
{
    string sentence;
    cout << "Enter a string: \n";
    getline(cin, sentence);

    return sentence;
}

vector<string> split_string(string sentence, string delim = " ")
{
    vector <string> words;
    short pos = 0;
    string word;

    while ((pos = sentence.find(delim)) != std::string::npos)
    {
        word = sentence.substr(0, pos);

        if (word != "")
            words.push_back(word);

        sentence.erase(0, pos + delim.length());
    }

    if (sentence != "")
        words.push_back(sentence);

    return words;
}

string join_reverse_string(vector <string>& words, string delim = " ")
{
    string sentence = "";

    vector<string>::iterator iter = words.end();

    while (iter != words.begin())
    {
        iter--;
        sentence += *iter + delim;
    }

    return (sentence.substr(0, sentence.length() - delim.length()));
}

string reverse_string_words(string sentence)
{
    vector<string> splitted_string;
    splitted_string = split_string(sentence);

    return join_reverse_string(splitted_string);
}

int main()
{
    cout << "Reversed String: \n" << reverse_string_words(read_string());

    system("pause>0");
}
