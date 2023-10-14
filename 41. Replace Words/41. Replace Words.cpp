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

vector<string> replace_words_in_vectors(vector<string> words, string word, string replacing_word)
{
    for (string& token : words)
    {
        if (token == word)
            token = replacing_word;
    }

    return words;
}

string join_string(vector <string>& words, string delim = " ")
{
    string sentence = "";

    for (string& word : words)
    {
        sentence += word + delim;
    }

    return (sentence.substr(0, sentence.length() - delim.length()));
}

string replace_words(string sentence, string replaced_word, string replacing_word)
{
    vector<string> words;
    vector<string> replaced_words;

    words = split_string(sentence);
    replaced_words = replace_words_in_vectors(words, replaced_word, replacing_word);

    return join_string(replaced_words);
}

int main()
{

    string sentence = "Egypt is beautiful Country . I love Egypt .";



    cout << replace_words(sentence, "Egypt", "Jordan") << endl;
}
