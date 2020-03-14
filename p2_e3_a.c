/**
* @file p2_e3_a.c
* @author Gonzalo Arcas & Ciro Alonso
* @date 10 March 2020
* @brief quinto ejercicio practica 2
*
* @details Programa principal para comprobar la funcionalidad de la funcion reversoWords usando el nuevo TAD Stack creado
*
* @see
*/

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Status reverseWords(char *strout, const char *strin){
    Stack *aux = NULL;
    Element *ele = NULL;
    int i=0, t, length=0;
    Status st = OK;
    char *ty = NULL;


    if (!strin || !strout) return ERROR;
    ele = element_init();
    if(!ele) return ERROR;
    aux = stack_init();
    if (!aux){
        element_free(ele);
        return ERROR;
    }

    t = 0;
    length = strlen(strin);

    while(i<=length){
    if(strin[i] == '\0'){
        strout[t] = '\0';
        i++;
    }
    if(strin[i] == ' '){
        strout[t] = ' ';
        t++;
        i++;
    }
    while(i<length && strin[i]!=' ' && strin[i] !='\0'){
        element_setInfo(ele,(char *) &strin[i]);
        st = stack_push(aux, ele);
        i++;
    }
    while(stack_isEmpty(aux) == FALSE){
        element_free(ele);
        ele = stack_pop(aux);
        ty = (char *)element_getInfo(ele);
        strout[t] = *ty;
        t++;
    }    
}
    element_free(ele);
    stack_free(aux);

    if (st == OK) return OK;

    return ERROR;
}

int main(int argc, char *argv[]){
    char *salida = NULL;
    char *entrada = NULL;

    if (argc < 2){
        printf("Falta la cadena de caracteres.\n");
        return -1;
    }

    entrada = (char *) argv[1];
    salida = (char *)calloc (200, sizeof(char));
    if (!salida) return -1;

    printf("Input : %s\n", entrada);

    reverseWords(salida, entrada);

    printf("Output: %s\n", salida);

    free(salida);
    return 0;
}
