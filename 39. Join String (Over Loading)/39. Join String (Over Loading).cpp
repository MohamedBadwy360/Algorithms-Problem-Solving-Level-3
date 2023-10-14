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

string join_string(string arr[], short length, string delim = " ")
{
    string sentence = "";

    for (short i = 0; i < length; i++)
    {
        sentence += arr[i] + delim;
    }

    return (sentence.substr(0, sentence.length() - delim.length()));
}

int main()
{
    vector <string> words{ "Mohamed", "Badwy", "Elsaid", "Badwy" };

    cout << "After Join Vector: \n";
    cout << join_string(words);

    string arr[] = { "Hanem", "Shawky", "Soliman" };
    cout << "\n============\n";
    cout << "After Join Array: \n";
    cout << join_string(arr, 3);

    system("pause>0");
}
