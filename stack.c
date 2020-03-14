/**
* @file stack.c
* @author Gonzalo Arcas & Ciro Alonso
* @date 14 March 2020
* @brief ADT Stack
*
* @details definicion de las funciones stack.h
*
* @see
*/


#include "stack.h"
#include <errno.h>

extern int errno;
#define MAXSTACK 1024

struct _Stack{
    int top;
    Element *item[MAXSTACK];
};

Stack * stack_init (){
    Stack *aux = NULL;

    aux = (Stack *) malloc (sizeof(Stack));
    if (!aux ) return NULL;

    for (int i=0; i<MAXSTACK; i++){
        aux->item[i] = NULL;
    }
    aux->top = -1;

    return aux;
}

void stack_free(Stack *s){
    if (!s) return ;

    for (int i=0; i<MAXSTACK; i++){
        element_free(s->item[i]);
    }

    free(s);
}

Status stack_push(Stack *s,const Element *ele){
    Element *aux = NULL;

    if (!s || !ele || stack_isFull(s)==TRUE) return ERROR;

    aux = element_copy(ele);
    if (!aux) return ERROR;

    s->top++;
    s->item[s->top] = aux;
    
    return OK;
}

Element * stack_pop(Stack *s){
    Element *aux = NULL;

    if (!s || stack_isEmpty(s)==TRUE) return NULL;

    aux = s->item[s->top];
    s->item[s->top] = NULL;
    s->top--;

    return aux;   
}

Element * stack_top(const Stack *s){
    if (!s || stack_isEmpty(s)==TRUE) return NULL;

    return s->item[s->top];
}

Bool stack_isEmpty(const Stack *s){
    if (s->top == -1) return TRUE;

    return FALSE;
}

Bool stack_isFull(const Stack *s){
    if (s->top == MAXSTACK-1) return TRUE;

    return FALSE;
}

int stack_print(FILE *pf,const Stack *s){
    int cont = 0;
    if (!pf || !s){
        fprintf(stderr, "%s", strerror(errno));
        return -1;
    }

    for (int i=s->top; i>=0; i--){
        cont = element_print(pf, s->item[i]);
    }
    return cont;
}

int stack_size(Stack *s){
    if (!s) return -1;

    return s->top+1;
}
