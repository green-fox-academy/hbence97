#include <stdio.h>

int main() {

    int l;
    int j;
    int half;
    int count;

    printf("Enter how big of an X do you want to see!(We will double it)\n");
    scanf("%d", &half);

    count = 2 * half - 1;

    for (l = 1; l <= count ; ++l) {
        for (j = 1; j <= count ; ++j) {
            if (l == j || (j == count - l + 1)){
                printf("LLJ");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}