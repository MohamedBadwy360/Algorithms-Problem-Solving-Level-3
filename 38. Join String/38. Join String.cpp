#include <iostream>
#include <string>
#include <vector>

using namespace std;

string join_string(vector <string>& words, string delim = " ")
{
    string sentence = "";

    for (string& word : words)
    {
        sentence += word + delim;
    }

    return (sentence.substr(0, sentence.length() - delim.length()));
}

int main()
{
    vector <string> words{ "Mohamed", "Badwy", "Elsaid", "Badwy" };

    cout << "After Join: \n";
    cout << join_string(words);
  
    system("pause>0");
}
