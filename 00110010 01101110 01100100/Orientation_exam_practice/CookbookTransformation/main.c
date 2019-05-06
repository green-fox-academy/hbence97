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
void scale_recipe(recipe_t recipe, unsigned char number_of_people);

int main() {

    read_recipe("vegan_curry.txt");

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
}

void scale_recipe(recipe_t recipe, unsigned char number_of_people)
{
    
}