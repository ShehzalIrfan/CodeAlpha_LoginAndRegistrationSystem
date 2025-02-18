#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <windows.h>

using namespace std;

// Function to set color
void SetColor(int foreground, int background)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD)((background << 4) | foreground));
}

// Function to check if a username already exists
bool isUsernameExists(const string& username)
{
    ifstream file("users.txt");
    string line;
    while (getline(file, line)) 
    {
        size_t pos = line.find(',');
        string storedUsername = line.substr(0, pos);
        if (storedUsername == username) 
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// Function to validate password
bool isValidPassword(const string& password) 
{
    // Password must be at least 6 characters long
    return password.length() >= 6;
}

// Function to register a new user
void registerUser() 
{
    string username, password;

    // Input: Username
    while (true) 
    {
        cout << "Enter a username: ";
        getline(cin, username);
        if (isUsernameExists(username)) 
        {
            cout << "Username already exists! Please choose a different username." << endl;
        }
        else
        {
            break;
        }
    }

    // Input: Password
    while (true) 
    {
        cout << "Enter a password (at least 6 characters): ";
        getline(cin, password);
        if (isValidPassword(password))
        {
            break;
        }
        else 
        {
            cout << "Invalid password! Password must be at least 6 characters long." << endl;
        }
    }

    // Save user credentials to file
    ofstream file("users.txt", ios::app);
    if (file.is_open())
    {
        file << username << "," << password << endl;
        file.close();
        cout << endl << "Registration successful!" << endl;
    }
    else 
    {
        cout << "Error. Unable to save data." << endl;
    }
}

// Function to log in a user
void loginUser() 
{
    string username, password;

    // Input: Username
    cout << "Enter your username: ";
    getline(cin, username);

    // Input: Password
    cout << "Enter your password: ";
    getline(cin, password);

    // Check if credentials match
    ifstream file("users.txt");
    string line;
    bool loggedIn = false;
    while (getline(file, line))
    {
        size_t pos = line.find(',');
        string storedUsername = line.substr(0, pos);
        string storedPassword = line.substr(pos + 1);
        if (storedUsername == username && storedPassword == password)
        {
            loggedIn = true;
            break;
        }
    }
    file.close();

    if (loggedIn) 
    {
        cout << endl << "Login successful! Welcome, " << username << "!" << endl;
    }
    else 
    {
        cout << "Invalid username or password. Please try again." << endl;
    }
}

int main() 
{
    cout << "Let's start" << endl;
    system("pause");
    system("cls");
    SetColor(5, 0);
    cout << " _    _    __  _  _  _     _      ___  ___  __  _  __  ___  ___   _  ___  _   _   _  _      __ __ __ __  ___  ___  _   _ " << endl;
    cout << "| |  / \\  / _|| || \\| |   (o)    | o \\| __|/ _|| |/ _||_ _|| o \\ / \\|_ _|| | / \\ | \\| |    / _|\\ V // _||_ _|| __|| \\_/ |" << endl;
    cout << "| |_( o )( |_n| || \\\\ |   /oV7   |   /| _|( |_n| |\\_ \\ | | |   /| o || | | |( o )| \\\\ |    \\_ \\ \\ / \\_ \\ | | | _| | \\_/ |" << endl;
    cout << "|___|\\_/  \\__/|_||_|\\_|   \\_n\\   |_|\\\\|___|\\__/|_||__/ |_| |_|\\\\|_n_||_| |_| \\_/ |_|\\_|    |__/ |_| |__/ |_| |___||_| |_|" << endl;
    int choice;
    while (true) 
    {
        SetColor(7, 0);
        cout << endl;
        SetColor(13, 7);
        cout << "MENU:" << endl;
        SetColor(7, 0);
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        SetColor(13, 7); 
        cout << "Enter your choice:";
        SetColor(7, 0);
        cout << " "; 
        cin >> choice;

        // Clear the input buffer
        cin.clear();
        cin.ignore(10000, '\n');

        switch (choice) 
        {
        case 1:
            registerUser();
            system("pause");
            system("cls");
            break;
        case 2:
            loginUser();
            system("pause");
            system("cls");
            break;
        case 3:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    }

    return 0;
}