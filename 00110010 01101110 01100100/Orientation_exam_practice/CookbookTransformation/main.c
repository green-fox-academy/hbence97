#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char* name_of_ingredient;
    char* name_of_measuring_unit;
    int amount_needed;
}ingredient_t;

typedef struct {
    FILE* vegan_curry;
    ingredient_t ingredients;
    int number_of_ingredients;
}recipe_t;

recipe_t read_recipe(const char *file_name);
void scale_recipe(ingredient_t ingredient, unsigned char number_of_people);

int main() {
    ingredient_t ingredient1;
    ingredient1.amount_needed = 3;

    read_recipe("vegan_curry.txt");
    scale_recipe(ingredient1,4);

    return 0;
}

recipe_t read_recipe(const char *file_name)
{
    FILE *fp;
    fp = fopen(file_name, "r");
    if (fp == NULL){
        printf("Failed to open the file.\n");
    }
    char buffer[150];

    while (!feof(fp)){
        fgets(buffer, 150, fp);
        puts(buffer);
    }
    fclose(fp);
}

void scale_recipe(ingredient_t ingredient, unsigned char number_of_people)
{
    FILE *fp;
    fp = fopen("vegan_curry_for_x.txt", "w");
    if (fp == NULL){
        printf("Failed to open the file.\n");
    }
    //number_of_people = (unsigned char)malloc(number_of_people * sizeof(unsigned char));
    printf("How many do you want to order?\n");
    scanf("%s",&number_of_people);
    char buffer[50];
    while (!feof(fp)){
        fgets(buffer,50,fp);

        char* ingredient_name = strtok(buffer," ");
        char* measuring_unit = strtok(NULL," ");
        char* amount = strtok(NULL,"\n");

        strcpy(ingredient.name_of_ingredient,ingredient_name);
        strcpy(ingredient.name_of_measuring_unit,measuring_unit);
        strcpy(ingredient.amount_needed,atoi(amount) * number_of_people);

        fprintf(fp, "%s %s",ingredient_name,measuring_unit);
    }
    fclose(fp);
}