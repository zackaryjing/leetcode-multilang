#include <stdio.h>

float f(int x) {
    return (float) (x != 0) / (float) (x + (x == 0));
}

int main() {
    printf("%f\n", f(10));
    printf("%f\n", f(0));
    printf("%f\n", f(-10));
}
