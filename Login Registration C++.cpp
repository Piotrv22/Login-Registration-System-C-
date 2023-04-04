#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Function prototypes
void registerUser();
void login();

// Global variable to store all registered users
unordered_map<string, string> users;

int main()
{
    int choice;

    while (true)
    {
        cout << "1. Register\n2. Login\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                registerUser();
                break;
            case 2:
                login();
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice\n";
                break;
        }
    }

    return 0;
}

// Function to register a new user
void registerUser()
{
    string username, password;

    cout << "Enter a username: ";
    cin >> username;

    // Check if the username is already taken
    if (users.count(username) > 0)
    {
        cout << "Username already exists\n";
        return;
    }

    cout << "Enter a password: ";
    cin >> password;

    // Add the user to the global map
    users[username] = password;
    cout << "User registered successfully\n";
}

// Function to login as a registered user
void login()
{
    string username, password;

    cout << "Enter your username: ";
    cin >> username;

    // Check if the username exists
    if (users.count(username) == 0)
    {
        cout << "Username not found\n";
        return;
    }

    cout << "Enter your password: ";
    cin >> password;

    // Check if the password is correct
    if (users[username] != password)
    {
        cout << "Incorrect password\n";
        return;
    }

    cout << "Welcome back, " << username << "!\n";
}