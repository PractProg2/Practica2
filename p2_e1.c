#include "stack_fp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Status reverseWords(char *strout, const char *strin){
    Stack *aux = NULL;
    int i=0, j, t;
    Status st = OK;
    char c;
    char *ty = NULL;
    int length=0;

    if (!strin || !strout) return ERROR;

    aux = stack_init(char_free, char_copy, char_print);
    if (!aux) return ERROR;

    t = 0;
    j = 0;
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
        printf("_%c_\n", strin[i]);
        st = stack_push(aux, &strin[i]);
        i++;
    }
    while(stack_isEmpty(aux) == FALSE){
        ty= (char *)stack_pop(aux);
        strout[t] = *ty;
        t++;
        free(ty);
    }    
}

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