/**
* @file p2_e2.c
* @author Gonzalo Arcas & Ciro Alonso
* @date 10 March 2020
* @brief cuarto  ejercicio practica 2
*
* @details Programa principal para comprobar la funcionalidad de la funcion infix2postfix
*
* @see
*/


#include "stack_fp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OPERATOR {'+','-','*','/','%','^'}

Bool isOperator(char c){
    if(c == '\0') return FALSE;

    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^' ) return TRUE;

    return FALSE;
}
int prec(char c){
    if (c == '\0') return -1;

    if(c == '+' || c == '-') return 1;

    if(c == '*' || c == '/') return 2;

    if(c == '%' || c == '^') return 3;

    return -1;
}

Status infix2postfix(char *suf, const char* in){
    Stack *s = NULL;
    int i = 0, j = 0;
    char *ele = NULL;

    if (!suf || !in) return ERROR;
    
    s = stack_init(char_free, char_copy, char_print);
    if (!s) return ERROR;

    while (in[i] != '\0'){
        if (isOperator(in[i]) == TRUE){
            while (stack_isEmpty(s) == FALSE && prec (*(char *)(stack_top(s))) >= prec(in[i])){
                ele = (char *)stack_pop(s);
                suf[j] = *ele;
                j++;
                free(ele);
            }
            stack_push(s, &in[i]);

        }else if (in[i] == '('){
            stack_push(s, &in[i]);

        }else if (in[i] == ')'){
            while (stack_isEmpty(s) == FALSE && *(char *)stack_top(s) != '('){
                ele = (char *)stack_pop(s);
                suf[j] = *ele;
                j++;
                free(ele);
            }
            ele = stack_pop(s);
            free(ele);

        }else{
            suf[j] = in[i];
            j++;

        }
        i++;
        
    }

    while (stack_isEmpty(s) == FALSE){
        ele = (char *)stack_pop(s);
        suf[j] = *ele;
        j++;
        free(ele);
    }
    
    stack_free(s);
    return OK;
}

int main(int argc, char *argv[]){
    char *salida = NULL;
    char *entrada = NULL;

    if (argc < 2){
        printf("Falta la operacion.\n");
        return -1;
    }

    entrada = (char *) argv[1];
    salida = (char *)calloc (200, sizeof(char));
    if (!salida) return -1;

    printf("Input : %s\n", entrada);

    infix2postfix(salida, entrada);

    printf("Output: %s\n", salida);

    free(salida);
    return 0;
}




























