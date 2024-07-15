#include <password_manager/password_manager.hpp>

int main() {
    PasswordManager pm("passwords.db", "my_master_password");

    while (true)
    {
        cout << "1. Add password" << endl;
        cout << "2. Generate password" << endl;
        cout << "3. Remove password" << endl;
        cout << "4. Get password" << endl;
        cout << "5. Print passwords" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string website, password;
            cout << "Enter website: ";
            cin >> website;
            cout << "Enter password: ";
            cin >> password;
            pm.addPassword(website, password);
            break;
        }
        case 2:
        {
            string website;
            size_t length;
            cout << "Enter website: ";
            cin >> website;
            cout << "Enter length: ";
            cin >> length;
            pm.generatePassword(length, website);
            break;
        }
        case 3:
        {
            string website;
            cout << "Enter website: ";
            cin >> website;
            pm.removePassword(website);
            break;
        }
        case 4:
        {
            string website;
            cout << "Enter website: ";
            cin >> website;
            cout << "Password: " << pm.getPassword(website) << endl;
            break;
        }
        case 5:
            pm.printPasswords();
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}
