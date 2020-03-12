#include "stack_fp.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY 3

int p2_e0_a(){
    int i;
    Stack *ps = NULL;
    char array[MAX_ARRAY] = {'a','b', 'c'};
    char *aux = NULL;

    ps = stack_init(char_free, char_copy, char_print);
    if (!ps) return -1;

    for (i=0; i<MAX_ARRAY; i++){
        if (stack_push(ps, &array[i]) == ERROR){
            stack_free(ps);
            return -1;
        }
    }
    stack_print(stdout, ps);
    printf("Stack size: %zu\n", stack_size(ps));

    while (stack_isEmpty(ps) == FALSE){
        aux = (char *)stack_pop(ps);
        printf("Elemento extraido: %c\n", *aux);
        free(aux);
    }

    printf("Stack size: %zu\n", stack_size(ps));

    stack_free(ps);
    return 0;
}