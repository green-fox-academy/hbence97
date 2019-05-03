#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int username_exists(char* username);
void register_user(char* username, char* password);


int main() {

    char command[50];

    printf("Greetings, what do you want to do?\n");
    scanf("%s", command);

    while (strcmp(command,"register") != 0 && strcmp(command,"login") != 0){
        puts("This command is not valid. Try again.\n");
        scanf("%s",command);
    }
    //hogyha register-t ir be a user
    if(strcmp(command,"register") == 0) {
        char username[50];
        printf("Cool, choose a username.\n");
        scanf("%s", username);
        while (username_exists(username) == 1){
            printf("The username is already taken.\n");
            scanf("%s", username);
        }
        if (username_exists(username) == 0) {
            printf("Now give me the password.\n");
            char password[50];
            scanf("%s", password);

            register_user(username,password);
            printf("The registration was succesful.\n");
        }
    }
    return 0;
}


int username_exists(char *username_check)
{
    char* username_from_file;

    FILE *fp = fopen("database.txt", "r");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 0;
    }
    char buffer[50];
    while (!feof(fp)) {
        fgets(buffer, 50, fp);

        username_from_file = strtok(buffer, " ");
        if (strcmp(username_from_file, username_check) == 0) {
            return 1;
        }
    }
    return 0;
}

void register_user(char* username, char* password)
{
    FILE *fp;
    fp = fopen("database.txt","a");
    if (fp == NULL){
        printf("There was a problem opening the file,\n");
    }
     fprintf(fp,"\n%s %s",username,password);
}