#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string file_name = "clients.txt";

string read_string(string message)
{
    string sentence;
    cout << message << endl;
    getline(cin, sentence);

    return sentence;
}

struct st_client_data
{
    string account_number;
    string pin_code;
    string name;
    string phone;
    double account_balance;
};

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

st_client_data convert_line_data_to_record(string line, string delim = "#//#")
{
    vector <string> line_data = split_string(line, delim);
    st_client_data client_data;

    client_data.account_number = line_data.at(0);
    client_data.pin_code = line_data.at(1);
    client_data.name = line_data.at(2);
    client_data.phone = line_data.at(3);
    client_data.account_balance = stod(line_data.at(4));

    return client_data;
}

vector<st_client_data> read_clients_data_from_file(string file_name)
{
    vector<st_client_data> v_clients_data;
    string line;
    st_client_data client_data;

    fstream file;
    file.open(file_name, ios::in);

    while (getline(file, line))
    {
        client_data = convert_line_data_to_record(line);
        v_clients_data.push_back(client_data);
    }

    file.close();

    return v_clients_data;
}

void print_client_data(st_client_data client_data)
{
    cout << "The following is the extracted client data: \n\n";
    cout << "Account Number : " << client_data.account_number << endl;
    cout << "Pincode        : " << client_data.pin_code << endl;
    cout << "Name           : " << client_data.name << endl;
    cout << "Phone          : " << client_data.phone << endl;
    cout << "Account Balance: " << client_data.account_balance << endl;
}

void find_client_by_account_number(string account_number, string file_name)
{
    vector<st_client_data> clients_data = read_clients_data_from_file(file_name);

    for (st_client_data& client_data : clients_data)
    {
        if (client_data.account_number == account_number)
        {
            print_client_data(client_data);
            return;
        }    
    }

    cout << "Client with the account number (" << account_number << ") is not found.\n";
}


int main()
{
    string account_number = read_string("Please Enter Account Number: ");
    find_client_by_account_number(account_number, file_name);
}
