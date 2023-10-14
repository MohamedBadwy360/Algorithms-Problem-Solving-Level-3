#include <iostream>
#include <string>

using namespace std;

string replace_words(string sentence, string replaced_word, string replacing_word)
{
    short pos = sentence.find(replaced_word);

    while (pos != std::string::npos)
    {
        sentence.replace(pos, replaced_word.length(), replacing_word);
        
        pos = sentence.find(replaced_word);
    }

    return sentence;
}

int main()
{
    string sentence = "Egypt is beautiful country. I love Egypt.";

    cout << "Original Sentence: \n" << sentence << endl;

    cout << "Replaced Sentence: \n" << replace_words(sentence, "Egypt", "USA") << endl;
}
