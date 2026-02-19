#include <stdio.h>
#include <time.h>

#define N 10000000000

int main() {
    clock_t start = clock();

    long long suma = 0;
    for(long long i = 0; i < N; i++) {
        suma += i;
    }

    clock_t end = clock();
    double tiempo = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Suma total: %lld\n", suma);
    printf("Tiempo mono: %.2f segundos\n", tiempo);

    return 0;
}
