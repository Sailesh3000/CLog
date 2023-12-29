# CLog
"CLog" is a C-based login system using SQLite. Users input credentials to authenticate against a SQLite database. It verifies entries and grants access upon matching stored username and password. This project demonstrates basic user authentication in C with SQLite.

# Requirements
-> C Compiler
-> SQLite library (sqlite3.h)

# Functionality
Database Structure: The program assumes a table named users in the login.db database with columns username and password.
Login Process: It retrieves the username and password from the user input and compares them to the stored values in the database. If a match is found, the login is successful; otherwise, it prompts for re-entry.

# Compilation
gcc -o output_file.exe your_file.c sqlite3.c

# Note
This is a simplistic example intended for demonstration purposes. In real-world scenarios, handling passwords and user authentication involves encryption, secure storage, and additional security measures, which are not covered in this basic implementation.
