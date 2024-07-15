# Password Manager

A simple password manager application that securely stores and retrieves passwords using AES-256-CBC encryption. This project helps users manage their passwords securely and efficiently, using an SQLite database to store encrypted passwords.

## Features

- Add, remove, and retrieve passwords
- Encrypts passwords using AES-256-CBC encryption
- Stores encrypted passwords in an SQLite database

## Prerequisites

Before building and running the Password Manager, ensure you have the following installed:

- **CMake** (version 3.10 or later)
- **A C++ compiler** (GCC, Clang, etc.)
- **OpenSSL** (for encryption)
- **SQLite3** (for database management)

## Building the Project

Follow these steps to build the Password Manager from source:

1. **Clone the Repository**

   ```sh
   git clone https://github.com/yourusername/password_manager.git
   ```
2. ** Build the Project**

   ```sh
   cd password_manager
   mkdir build
   cd build
   cmake ..
   make
   ```
3. **Run the Application**

   ```sh
    ./password_manager
    ```
## Usage

The Password Manager application provides a simple command-line interface for managing passwords. Here are the available commands:

- **add** - Add a new password
- **generate** - Generate a random password
- **remove** - Remove an existing password
- **get** - Retrieve a password
- **list** - List all stored passwords
- **exit** - Exit the application

## Configuration

The application uses an SQLite database to store encrypted passwords. The database file will be created in the same directory as the executable. Make sure the application has the necessary permissions to read from and write to this file.

## File Structure

The project is structured as follows:

```
password_manager/
├── src/
│   ├── main.cpp
│   ├── password_manager.cpp
│   ├── database.cpp
│   └── encryption.cpp
├── include/
│   ├── password_manager
│   │   ├── password_manager.hpp
│   │   ├── database.hpp
│   │   └── encryption.hpp
├── tests/
│   └── encryption.cpp
├── CMakeLists.txt
└── README.md
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contribution

Contributions are welcome! Feel free to open an issue or submit a pull request if you have any improvements to suggest.
