#include <string>
#include <iostream>
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

int main()
{
    vector <string> words;

    words = split_string(read_string());

    cout << "==============\n";
    cout << "Tokens: " << words.size() << endl;
    
    for (string& word : words)
    {
        cout << word << endl;
    }

    return 0;
}

