#include <iostream>
#include <string>
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

st_client_data read_client_data()
{
    cout << "Please Enter Client Data: \n";

    st_client_data client_data;
    cout << "Enter Account Number: ";
    getline(cin >> ws, client_data.account_number); // will extract all white spaces

    cout << "Enter PinCode: ";
    getline(cin, client_data.pin_code);

    cout << "Enter Name: ";
    getline(cin, client_data.name);

    cout << "Enter Phone: ";
    getline(cin, client_data.phone);

    cout << "Enter Account Balance: ";
    cin >> client_data.account_balance;

    return client_data;
}

string convert_record_to_line(st_client_data client_data, string delim = "#//#")
{
    return (client_data.account_number + delim + client_data.pin_code + delim + client_data.name
        + delim + client_data.phone + delim + to_string(client_data.account_balance));
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

void add_new_client(string file_name)
{
    add_data_line_to_file(file_name, convert_record_to_line(read_client_data()));
}

void add_clients(string file_name)
{
    char add_more = 'Y';
    do
    {
        system("cls");

        add_new_client(file_name);

        cout << "\nClient Add Successfully. Do you want to add more clients [Y/N] ?\n";
        cin >> add_more;
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (add_more == 'Y' || add_more == 'y');
}

int main()
{
    add_clients(file_name);
}
