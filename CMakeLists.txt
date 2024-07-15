cmake_minimum_required(VERSION 3.10)

project(password_manager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(password_manager
    src/main.cpp
    src/password_manager.cpp
    src/encryption.cpp
    src/database.cpp  # Add your database.cpp file
)

find_package(OpenSSL REQUIRED)
target_link_libraries(password_manager PRIVATE OpenSSL::SSL OpenSSL::Crypto)

find_package(SQLite3 REQUIRED)
target_include_directories(password_manager PRIVATE ${SQLite3_INCLUDE_DIRS})
target_link_libraries(password_manager PRIVATE SQLite::SQLite3)
