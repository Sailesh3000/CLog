#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
    char ch;
    char pass[20];
    char saved_pass[20];
start:
    printf("Enter your Password: ");
    int i = 0;
    while (1)
    {
        ch = getch();
        if (ch == 13)
        { // ASCII Code for Enter
            pass[i] = '\0';
            break;
        }
        else
        {
            pass[i++] = ch;
            printf("*");
        }
    }

    printf("\nYou Entered : %s\n", pass);

    FILE *ptr;
    ptr = fopen("password.txt", "r");

    if (ptr == NULL) {
        printf("Error opening the file.");
        return 1;
    }

    fscanf(ptr, "%s", saved_pass);

    fclose(ptr);

    printf("Password : %s ", saved_pass);

    int l = strcmp(pass, saved_pass);
    if (l == 0)
    {
        printf("\n\n******LOGIN SUCCESSFUL******\n\n\n");
    }
    else
    {
        printf("\n\n******INCORRECT PASSWORD******\nPlease Try again...\n\n");
        goto start;
    }
    return 0;
}