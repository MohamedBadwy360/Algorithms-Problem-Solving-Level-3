#include <string>
#include <iostream>
#include <iomanip>
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

void print_header(vector<st_client_data> clients_data)
{
    cout << "\n\n\t\t\t\t\tClient List (" << clients_data.size() << ") Clients\n\n";
    cout << "_________________________________________________________________________________________________\n\n";
    cout << "|" << setw(15) << "Account Number" << "|" << setw(10) << "PinCode" << "|" <<
        setw(40) << "Client Name" << "|" << setw(15) << "Phone" << "|" << setw(10) << "Balance" << "|" << endl;
    cout << "_________________________________________________________________________________________________\n";
}

void print_record(st_client_data client_data)
{
    cout << "|" << setw(15) << client_data.account_number << "|" << setw(10) 
        << client_data.pin_code << "|" << setw(40) << client_data.name 
        << "|" << setw(15) << client_data.phone << "|" << setw(10) 
        << client_data.account_balance << "|" << endl;
}

void show_clients_data(vector<st_client_data> clients_data)
{
    print_header(clients_data);

    for (st_client_data& client_data : clients_data)
    {
        print_record(client_data);
    }
}

int main()
{
    cout << left;

    show_clients_data(read_clients_data_from_file(file_name));
}
