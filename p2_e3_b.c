/**
* @file p2_e3_b.c
* @author Gonzalo Arcas & Ciro Alonso
* @date 10 March 2020
* @brief sexto ejercicio practica 2
*
* @details Programa principal para comprobar la funcionalidad de el ejercicio 0b usando el nuevo TAD Stack creado
*
* @see
*/

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ARRAY 3

int main(){
    int i;
    Stack *ps = NULL;
    Element *ele = NULL;
    char array[MAX_ARRAY] = {'a','b', 'c'};
    char *aux = NULL;

    ele = element_init();
    if(!ele) return -1;
    ps = stack_init();
    if (!ps){
        element_free(ele);
        return -1;
    }

    for (i=0; i<MAX_ARRAY; i++){
        element_setInfo(ele,(char *) &array[i]);
        stack_push(ps, ele);
    }
    stack_print(stdout, ps);
    printf("Stack size: %d\n", stack_size(ps));
    
    while (stack_isEmpty(ps) == FALSE){
        element_free(ele);
        ele = stack_pop(ps);
        printf("Elemento extraido: ");
        element_print(stdout, ele);
    }

    printf("Stack size: %d\n", stack_size(ps));

    element_free(ele);
    stack_free(ps);
    return 0;
}
