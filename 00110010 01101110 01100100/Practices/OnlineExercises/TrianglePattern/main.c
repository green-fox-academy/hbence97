#include <stdio.h>

int main() {

    int a;

    printf("Tell me how big of a triangle you want to make!\n");
    scanf("%d", &a);

    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}