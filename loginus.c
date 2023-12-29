#include <stdio.h>
#include <string.h>
#include "sqlite3.h"

int main() {
    char ch;
    char pass[20];
    char user_name[20];

    sqlite3 *db;
    int rc = sqlite3_open("login.db", &db); // Open or create a SQLite database named login.db

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db)); // Error handling if the database fails to open
        return 0;
    }

user:
    printf("Enter Username: \n");
    scanf("%s", user_name);

    // Prepare the SQL statement to select the username and password for the given username
    sqlite3_stmt *stmt;
    char sql[100];
    sprintf(sql, "SELECT username, password FROM users WHERE username='%s'", user_name);

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0); // Prepare the SQL statement

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement\n"); // Error handling for SQL preparation failure
        sqlite3_close(db);
        return 0;
    }

    // Execute the SQL statement
    rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) {
        const unsigned char *saved_user = sqlite3_column_text(stmt, 0);
        const unsigned char *saved_pass = sqlite3_column_text(stmt, 1);
        
        int compare_user = strcmp(user_name, (const char *)saved_user);
        if (compare_user == 0) {
            start:
            printf("Enter your Password: ");

            int i = 0;
            while (1) {
                ch = getch();
                if (ch == 13) { // ASCII Code for Enter
                    pass[i] = '\0';
                    break;
                } else if (ch == 8) { // ASCII FOR BACKSPACE
                    if (i > 0) {
                        i--;
                        printf("\b \b");
                    }
                } else if (ch == 9 || ch == 32) {
                    continue;
                } else {
                    pass[i++] = ch;
                    printf("*");
                }
            }

            int compare_pass = strcmp(pass, (const char *)saved_pass);
            if (compare_pass == 0) {
                printf("\n\n******LOGIN SUCCESSFUL******\n\n\n");
            } else {
                printf("\n\n******INCORRECT PASSWORD******\nPlease Try again...\n\n");
                goto start;
            }
        } else {
            printf("User not found\n");
            goto user;
        }
    } else {
        printf("User not found\n");
        goto user;
    }

    sqlite3_finalize(stmt); // Finalize the SQL statement
    sqlite3_close(db); // Close the database connection

    return 0;
}
