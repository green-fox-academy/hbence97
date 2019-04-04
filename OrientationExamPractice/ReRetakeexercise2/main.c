#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    FALSE = 0,
    TRUE = 1
} bool_t;

const char *filename = "../../database.txt";

bool_t username_exists (const char *username);
bool_t password_matches (const char *username, const char *password);
void register_user(const char *username, const char *password);

int main() {
    printf("Hello, what do you want to do?\n");
    char command[100] = "";
    scanf("%s",command);

    while (strcmp(command, "login") != 0 && strcmp(command, "register") != 0){
        printf("The command you entered is invalid, please try again\n");
        scanf("%s",command);
    }

    if(strcmp(command, "register") == 0) {
        printf("Please choose a username!\n");
        char username [100];
        scanf("%s", username);

        if(username_exists(username) == TRUE) {
            printf("The username is already taken! Try a new one!\n");
        } else {
            printf("Please choose a password:\n");
            char password [100];
            scanf("%s", password);

            register_user(username, password);
            printf("The registration was succesful! Welcome aboard!\n");
        }
    } else if (strcmp(command, "login") == 0) {
        printf("Username:\n");
        char username[100];
        scanf("%s", username);

        if(username_exists(username) == TRUE) {
            printf("Password:\n");
            char password[100];
            scanf("%s", password);

            if(password_matches(username, password) == TRUE){
                printf("Login was succesful\n");
            } else {
                printf("Incorrect password, failed to login\n");
            }
        } else {
            printf("Username does not exist!\n");
        }
    }
    return 0;
}

bool_t username_exists (const char *username)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file \"%s\"", filename);
        return FALSE;
    }

    char buffer[100];
    while (!feof(file)){
        fgets(buffer, 100, file);
        char *username_from_file = strtok(buffer, " ");

        if (strcmp(username, username_from_file) == 0){
            return TRUE;
        }
    }
    return FALSE;
}

bool_t password_matches (const char *username, const char *password)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file \"%s\"", filename);
        return FALSE;
    }
    char buffer[100];
    while(!feof(file)) {
        fgets(buffer, 100, file);
        char *username_from_file = strtok(buffer, " ");

        if(strcmp(username, username_from_file) == 0){
            char *password_from_file = strtok(NULL, " \n");
            if(strcmp(password, password_from_file) == 0) {
                return TRUE;
            } else {
                return FALSE;
            }
        }
    }
    return FALSE;
}

void register_user(const char *username, const char *password)
{
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Failed to open file \"%s\"", filename);
        return;
    }
    fprintf(file, "\n%s %s", username, password);
}