#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
  FALSE = 0,
  TRUE = 1
} bool_t;

bool_t username_exists(char* username);

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
        // ----- eddig működik rendesen -----

        FILE *fp = fopen("database.txt", "a");
        if (fp == NULL) {
            printf("Failed to open the file.\n");
            return 0;
        }
        //Regisztrálás, illetve ha foglalt a név.
        char buffer[50];
        while (!feof(fp)) {
            fgets(buffer, 50, fp);

            char *username_from_file = strtok(buffer, " ");

            while (strcmp(username_from_file, username) == 0){
                printf("The username already exists, try again.\n");
                scanf("%s", username);
            }
            if (strcmp(username_from_file, username) != 0){
                fprintf(fp,"\n%s",username);
            }
        }
    }
    return 0;
}
