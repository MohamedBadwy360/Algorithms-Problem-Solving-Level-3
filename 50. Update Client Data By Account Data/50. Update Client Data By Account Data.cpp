#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string file_name = "clients.txt";

struct st_client_data
{
    string account_number;
    string pin_code;
    string name;
    string phone;
    double account_balance;
    bool mark_for_delete = false;
};

string read_string(string message)
{
    string sentence;
    cout << message << endl;
    getline(cin, sentence);

    return sentence;
}

string convert_record_to_line(st_client_data client_data, string delim = "#//#")
{
    return (client_data.account_number + delim + client_data.pin_code + delim + client_data.name
        + delim + client_data.phone + delim + to_string(client_data.account_balance));
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

void print_client_data(st_client_data client_data)
{
    cout << "The following is the extracted client data: \n\n";
    cout << "Account Number : " << client_data.account_number << endl;
    cout << "Pincode        : " << client_data.pin_code << endl;
    cout << "Name           : " << client_data.name << endl;
    cout << "Phone          : " << client_data.phone << endl;
    cout << "Account Balance: " << client_data.account_balance << endl;
}

void add_data_line_to_file(string file_name, string line_data)
{
    fstream file;
    file.open(file_name, ios::out | ios::app);

    while (file.is_open())
    {
        file << line_data << endl;

        file.close();
    }
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

bool find_client_by_account_number(string account_number, vector<st_client_data> v_clients_data, st_client_data& client)
{
    for (st_client_data& c : v_clients_data)
    {
        if (c.account_number == account_number)
        {
            client = c;
            return true;
        }
    }

    return false;
}

bool mark_client_for_delete_by_account_number(string account_number, vector<st_client_data>& v_clients_data)
{
    for (st_client_data& client : v_clients_data)
    {
        if (client.account_number == account_number)
        {
            client.mark_for_delete = true;
            return true;
        }

    }
    return false;
}

void save_client_data_to_file(string file_name, vector<st_client_data> v_clients_data)
{
    fstream file;
    string line_data;

    file.open(file_name, ios::out);

    if (file.is_open())
    {
        for (st_client_data client : v_clients_data)
        {
            if (client.mark_for_delete == false)
            {
                line_data = convert_record_to_line(client);
                file << line_data << endl;
            }
        }

        file.close();
    }
}

st_client_data change_client_record(string account_number)
{
    cout << "\nPlease Enter Updated Client Data: \n";

    st_client_data client_data;

    client_data.account_number = account_number;

    cout << "Enter PinCode: ";
    getline(cin >> ws, client_data.pin_code);

    cout << "Enter Name: ";
    getline(cin, client_data.name);

    cout << "Enter Phone: ";
    getline(cin, client_data.phone);

    cout << "Enter Account Balance: ";
    cin >> client_data.account_balance;

    return client_data;
}

bool Update_client_data(string account_number, vector<st_client_data>& v_clients_data)
{
    st_client_data client;
    char answer = 'n';

    if (find_client_by_account_number(account_number, v_clients_data, client))
    {
        print_client_data(client);

        cout << "Do you want to update this client data [Y/N]? ";
        cin >> answer;

        if (tolower(answer) == 'y')
        {
            for (st_client_data& c : v_clients_data)
            {
                if (c.account_number == account_number)
                {
                    c = change_client_record(account_number);
                    break;
                }
            }

            save_client_data_to_file(file_name, v_clients_data);

            cout << "\nClient Updated Successfully.\n";
            return true;
        }
    }
    else
    {
        cout << "Client with account number (" << account_number << ") is not found.\n";
        return false;
    }
}

int main()
{
    string account_number = read_string("Enter Account Number: ");

    vector <st_client_data> v_clients_data = read_clients_data_from_file(file_name);

    Update_client_data(account_number, v_clients_data);
}
