#include <stdlib.h>
#include "program3.h"

int* generate_B(){
    int* B = malloc(101 * sizeof(int));
    for (int i = 0; i < 101; i++){
      B[i]=0;
    }
    return B;
}