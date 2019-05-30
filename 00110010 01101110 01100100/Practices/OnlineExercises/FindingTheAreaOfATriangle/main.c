#include <stdio.h>

int main() {
    int height = 0;
    int base = 0;
    printf("Tell me the height of the triangle.\n");
    scanf("%d", &height);
    printf("Tell me the base of the triangle.\n");
    scanf("%d", &base);
    int area = (base * height) / 2;
    printf("The area of you triangle is: %d\n", area);
    return 0;
}