#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const string file_name = "clients.txt";

enum en_main_menu 
{
    show_client_data = 1, add_new_client = 2, delete_client = 3,
    update_client = 4, find_client = 5, transactions = 6, exit_program = 7
};

enum en_transactions {deposit = 1, withdraw = 2, total_balances = 3, main_menu = 4};

struct st_client_data
{
    string account_number;
    string pin_code;
    string name;
    string phone;
    double account_balance = 0;
    bool mark_for_delete = false;
};


void show_main_menu();
st_client_data convert_line_data_to_record(string line, string delim);
void show_transactions_screen();


string read_string(string message)
{
    string sentence;
    cout << message << endl;
    getline(cin >> ws, sentence);

    return sentence;
}

bool is_client_exist(string account_number, string file_name)
{
    string line;
    st_client_data client_data;

    fstream file;
    file.open(file_name, ios::in);

    while (getline(file, line))
    {
        client_data = convert_line_data_to_record(line, "#//#");
        if (client_data.account_number == account_number)
        {
            file.close();
            return true;
        }     
    }

    file.close();

    return false;
}

st_client_data read_client_data()
{
    cout << "Please Enter Client Data: \n";

    st_client_data client_data;
    cout << "Enter Account Number: ";
    getline(cin >> ws, client_data.account_number); // will extract all white spaces

    while (is_client_exist(client_data.account_number, file_name))
    {
        cout << "Client with account number (" << client_data.account_number << ") is found. Enter another account number: ";
        getline(cin >> ws, client_data.account_number);
    }

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
    cout << "\nThe following is the extracted client data: \n\n";
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

void add_clients()
{
    st_client_data client;
    char add_more = 'Y';

    do
    {
        cout << "Adding New Client: \n\n";

        client = read_client_data();
        add_data_line_to_file(file_name, convert_record_to_line(client));

        cout << "\nClient Add Successfully. Do you want to add more clients [Y/N] ?\n";
        cin >> add_more;
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (add_more == 'Y' || add_more == 'y');
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

void show_clients_data()
{
    vector<st_client_data> clients_data = read_clients_data_from_file(file_name);

    print_header(clients_data);

    for (st_client_data& client_data : clients_data)
    {
        print_record(client_data);
    }
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

bool delete_client_by_account_numebr(string account_number, vector<st_client_data>& v_clients_data)
{
    st_client_data client;
    char answer = 'n';

    if (find_client_by_account_number(account_number, v_clients_data, client))
    {
        print_client_data(client);

        cout << "Do you want to delete this client? ";
        cin >> answer;

        if (tolower(answer) != 'n')
        {
            mark_client_for_delete_by_account_number(account_number, v_clients_data);
            save_client_data_to_file(file_name, v_clients_data);

            v_clients_data = read_clients_data_from_file(file_name);
            cout << "Client is deleted successfully.\n";
            return true;
        }
    }
    else
    {
        cout << "Client with account number (" << account_number << ") is not found.\n";
        return false;
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

short read_menu_option()
{
    short option = 0;
    cout << "Choose what you want to do: ";
    cin >> option;

    return option;
}

void go_back_to_main_menu()
{
    cout << "\n\nPress any key to go back to main menu...";
    system("pause>0");
    show_main_menu();
}

void go_back_to_transaction_menu()
{
    cout << "\n\nPress any key to go back to main menu...";
    system("pause>0");
    show_transactions_screen();
}

void show_add_new_client_screen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tAdd new client\n";
    cout << "-----------------------------------\n";

    add_clients();
}

void show_delete_client_screean()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDelete client data\n";
    cout << "-----------------------------------\n";

    string account_number = read_string("Enter Account Number: ");
    vector <st_client_data> v_clients_data = read_clients_data_from_file(file_name);

    delete_client_by_account_numebr(account_number, v_clients_data);
}

void show_update_client_screen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate client data\n";
    cout << "-----------------------------------\n";

    string account_number = read_string("Enter Account Number: ");
    vector <st_client_data> v_clients_data = read_clients_data_from_file(file_name);

    Update_client_data(account_number, v_clients_data);
}

void show_find_client_screen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tFind client\n";
    cout << "-----------------------------------\n";

    string account_number = read_string("Enter Account Number: ");
    vector <st_client_data> v_clients_data = read_clients_data_from_file(file_name);
    st_client_data client;

    if (find_client_by_account_number(account_number, v_clients_data, client))
        print_client_data(client);
    else
        cout << "\nClient with (" << account_number << ") is not found.\n";
}

void show_exit_screen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tExit Program\n";
    cout << "-----------------------------------\n";
}

void deposit_money(string account_number, vector <st_client_data>& v_clients_data)
{
    double amount = 0;

    for (st_client_data& c : v_clients_data)
    {
        if (c.account_number == account_number)
        {
            print_client_data(c);
            cout << "\nPlease Enter Deposit Amount: ";
            cin >> amount;

            c.account_balance += amount;
            break;
        }
    }
    save_client_data_to_file(file_name, v_clients_data);
    cout << "\nAmount is Deposited Successfully.\n";
}

void show_deposit_screen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen\n";
    cout << "-----------------------------------\n";

    string account_number = read_string("Enter Account Number: ");
    st_client_data client;
    vector <st_client_data> v_clients_data = read_clients_data_from_file(file_name);

    while (!find_client_by_account_number(account_number, v_clients_data, client))
    {
        cout << "Client with account number (" << account_number << ") is not found.\n";
        account_number = read_string("\nEnter Account Number: ");
    }

    deposit_money(account_number, v_clients_data);
}

void withdraw_money(string account_number, vector <st_client_data>& v_clients_data)
{
    double amount;

    for (st_client_data& c : v_clients_data)
    {
        if (c.account_number == account_number)
        {
            print_client_data(c);
            cout << "\nPlease Enter Withdraw Amount: ";
            cin >> amount;

            if (c.account_balance > amount)
            {
                c.account_balance -= amount;
                cout << "\nAmount is Withdrawed Successfully.\n";
                break;
            }
            else
            {
                while (amount > c.account_balance)
                {
                    cout << "There isn't enough money in the account. The amount is " << c.account_balance << endl;
                    cout << "\nPlease Enter Withdraw Amount: ";
                    cin >> amount;
                }

                c.account_balance -= amount;
                cout << "\nAmount is Withdrawed Successfully.\n";
                break;
            }
        }
    }

    save_client_data_to_file(file_name, v_clients_data);
}

void show_withdraw_screen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tWithdraw Screen\n";
    cout << "-----------------------------------\n";

    string account_number = read_string("Enter Account Number: ");
    st_client_data client;
    vector <st_client_data> v_clients_data = read_clients_data_from_file(file_name);

    while (!find_client_by_account_number(account_number, v_clients_data, client))
    {
        cout << "Client with account number (" << account_number << ") is not found.\n";
        account_number = read_string("\nEnter Account Number: ");
    }

    withdraw_money(account_number, v_clients_data);
}

void show_total_balance()
{
    vector<st_client_data> clients_data = read_clients_data_from_file(file_name);

    print_header(clients_data);

    double balance = 0;

    for (st_client_data& client_data : clients_data)
    {
        print_record(client_data);
        balance += client_data.account_balance;
    }

    cout << "\n\n\t\t\t\tTotal Balance = " << balance << endl << endl;
}

en_transactions read_transaction_option()
{
    short option;
    cout << "Enter Transaction: ";
    cin >> option;

    return en_transactions(option);
}

void perform_transactions_options(en_transactions transaction)
{
    switch (transaction)
    {
        case en_transactions::deposit:
            system("cls");
            show_deposit_screen();
            go_back_to_transaction_menu();
            break;
        case en_transactions::withdraw:
            system("cls");
            show_withdraw_screen();
            go_back_to_transaction_menu();
            break;
        case en_transactions::total_balances:
            system("cls");
            show_total_balance();
            go_back_to_transaction_menu();
            break;
        case en_transactions::main_menu:
            system("cls");
            show_main_menu();
            break;
    }
}

void show_transactions_screen()
{
    system("cls");

    cout << "======================================\n";
    cout << "\tTransactions Menu Screen\n";
    cout << "======================================\n";
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Withdraw.\n";
    cout << "\t[3] Total Balances.\n";
    cout << "\t[4] Main Menu.\n";
    cout << "======================================\n";

    perform_transactions_options(read_transaction_option());
}

void perform_menu_option(en_main_menu option)
{
    switch (option)
    {
        case en_main_menu::show_client_data:
            system("cls");
            show_clients_data();
            go_back_to_main_menu();
            break;
        case en_main_menu::add_new_client:
            system("cls");
            show_add_new_client_screen();
            go_back_to_main_menu();
            break;
        case en_main_menu::delete_client:
            system("cls");
            show_delete_client_screean();
            go_back_to_main_menu();
            break;
        case en_main_menu::update_client:
            system("cls");
            show_update_client_screen();
            go_back_to_main_menu();
            break;
        case en_main_menu::find_client:
            system("cls");
            show_find_client_screen();
            go_back_to_main_menu();
            break;
        case en_main_menu::transactions:
            system("cls");
            show_transactions_screen();
            break;
        case en_main_menu::exit_program:
            system("cls");
            show_exit_screen();
            break;
    }
}

void show_main_menu()
{
    system("cls");

    cout << "======================================\n";
    cout << "\tMain Menu Screen\n";
    cout << "======================================\n";
    cout << "\t[1] Show Client Data.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transactions.\n";
    cout << "\t[7] Exit.\n";
    cout << "======================================\n";

    perform_menu_option((en_main_menu)read_menu_option());
}

int main()
{
    cout << left;

    show_main_menu();
    system("pause>0");

    return 0;
}

