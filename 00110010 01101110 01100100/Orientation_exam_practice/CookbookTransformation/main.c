#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name_of_ingredient[100];
    char name_of_measuring_unit[100];
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
    //ingredient1.amount_needed = 3;

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
    FILE *fp2;
    fp2 = fopen("vegan_curry.txt", "r");
    if (fp2 == NULL){
        printf("Failed to open the file.\n");
    }
    char buffer[50];
    char* ingredient_name = 0;
    char* measuring_unit = 0;
    char* amount = 0;
    while (!feof(fp2)){
        fgets(buffer, 50, fp2);
        ingredient_name = strtok(buffer," ");
        measuring_unit = strtok(NULL," ");
        amount = strtok(NULL," ");

        strcpy(ingredient.name_of_ingredient,ingredient_name);
        strcpy(ingredient.name_of_measuring_unit,measuring_unit);
        ingredient.amount_needed = (atoi(amount) * number_of_people) / 2;

        fprintf(fp, "%s %s %d\n",ingredient.name_of_ingredient,ingredient.name_of_measuring_unit,ingredient.amount_needed);
    }
    fclose(fp);
    fclose(fp2);
}