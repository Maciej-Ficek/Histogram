#include <stdio.h>
//#include <mpi.h>
#include <time.h>
#include <stdlib.h>
#include "program3.h"
#include <omp.h>

int main(){
    int number = 0;
    int* B = generate_B();
    FILE* file = fopen("in.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }
    FILE* result = fopen("result.txt", "w+");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }
    double start_time = omp_get_wtime();
    #pragma omp parallel
    {
    while(fscanf(file, "%d", &number) == 1){
      B[number] +=1;
    }
    }
    fclose(file);
    #pragma omp parallel for
    for (int i = 0; i < 101; i++){
        fprintf(result, "%d\n", B[i]);
        printf("%d: %d\n", i, B[i]);
    }
    fclose(result);
    double end_time = omp_get_wtime();
    printf("Time: %f\n", end_time - start_time);
    return 0;
}
