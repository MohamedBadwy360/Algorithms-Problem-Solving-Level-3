#include <string>
#include <iostream>

using namespace std;

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
    cout << "Please Enter Account Data: \n";

    st_client_data client_data;
    cout << "Enter Account Number: ";
    getline(cin, client_data.account_number);

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

int main()
{
    cout << "Client Record For Saving: \n" << convert_record_to_line(read_client_data()) << endl;
}
