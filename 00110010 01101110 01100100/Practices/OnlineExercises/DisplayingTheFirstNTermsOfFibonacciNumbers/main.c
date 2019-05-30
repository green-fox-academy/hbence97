#include <stdio.h>

int main() {

    int previous = 1;
    int previous_min_1 = 0;
    int current;
    int n;
    printf("Tell me how many Fibonacci numbers do you want me to display.\n");
    scanf("%d",&n);
    printf("Here is the Fibonacci numbers up to %d terms:\n",n);
    printf("%d  %d  ", previous_min_1,previous);

    for (int i = 3; i <= n; ++i) {
        current = previous + previous_min_1;
        printf(" %d ", current);
        previous_min_1 = previous;
        previous = current;
    }
    return 0;
}