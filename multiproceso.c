#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <wait.h>
#include <unistd.h>


#define N 10000000000

int main() {
    pid_t idProceso;
    int estadoHijo;
    idProceso = fork();

    if (idProceso == -1) {
        perror ("No se puede crear proceso");
        exit (-1);
    }

   if (idProceso == 0) {
	clock_t start = clock();

    	long long suma = 0;
    	for(long long i = 0; i < N; i++) {
        	suma += i;
   	 }

    	clock_t end = clock();
    	double tiempo = (double)(end - start) / CLOCKS_PER_SEC;

	printf("Hijo: Suma total: %lld\n", suma);
	printf("Hijo: Tiempo mono: %.2f segundos\n", tiempo);

	return 0;
   }

   if (idProceso > 0) {
	clock_t start = clock();

        long long suma = 0;
        for(long long i = 0; i < N; i++) {
                suma += i;
         }

        clock_t end = clock();
        double tiempo = (double)(end - start) / CLOCKS_PER_SEC;

        printf("Padre: Suma total: %lld\n", suma);
        printf("Padre: Tiempo mono: %.2f segundos\n", tiempo);
	
	wait(&estadoHijo);

        return 0;
   }
}
