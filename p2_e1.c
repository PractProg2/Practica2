#include "stack_fp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Status reverseWords(char *strout, const char *strin){
    Stack *aux = NULL;
    int i, j, t;
    Status st = OK;
    char c;
    char *ty;
    int length=0;

    if (!strin || !strout) return ERROR;

    aux = stack_init(char_free, char_copy, char_print);
    if (!aux) return ERROR;

    t = 0;
    j = 0;
    length = strlen(strin);

    for (i=0; i <length+1; i++){
        if (strin[i] == ' ' || strin[i] =='\0'){
            c = ' ';
            st = stack_push(aux, &c);
            while (j<i && st == OK){
                if (strin[j]!= ' '){
                    st = stack_push(aux, &strin[j]);
                    j++;
                }else{
                    j++;
                }
            }
            
        }
        
        while (stack_isEmpty(aux) == FALSE && st==OK){
            ty =  (char *)stack_pop(aux);
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
    salida = (char *)malloc (200* sizeof(char));
    if (!salida) return -1;


    printf("Input : %s\n", entrada);

    reverseWords(salida, entrada);

    printf("Output: %s\n", salida);

    free(salida);
    return 0;
}