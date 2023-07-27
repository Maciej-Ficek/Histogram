#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	FILE* file = fopen("in.txt", "r+");
	srand(time(NULL));
    for (int i = 0; i < 50000; i++) {
        fprintf(file, "%d\n", rand() % 101);   // Generate random number between 1 and 100
    }
    fclose(file);
	return 0;
}