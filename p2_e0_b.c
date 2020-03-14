/**
* @file p2_e0_b.c
* @author Gonzalo Arcas & Ciro Alonso
* @date 7 March 2020
* @brief segundo ejercicio practica 2
*
* @details Comprobacion de las funciones de la libreria de Stack y TAD Node
*
* @see
*/

#include "stack_fp.h"
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "types.h"

int main(){
    Stack *pNodes = NULL;
    Stack *pStrings = NULL;
    Node *pn = NULL;
    char *aux = NULL;

    //inicializamos los TAD's
    pn = node_init();
    if (!pn) return -1;

    pNodes = stack_init(node_free, node_copy, node_print);
    if (!pNodes){
        node_free(pn);
        return -1;
    }

    pStrings = stack_init(string_free, string_copy, string_print);
    if (!pStrings){
        node_free(pn);
        stack_free(pNodes);
        return -1;
    }

    //asignamos valores al primer nodo
    node_setName(pn, "first");
    node_setId(pn, 111);
    node_setLabel(pn, WHITE);

    // insertamos el nodo en la pila de nodos, y su nombre en la pila de strings
    stack_push(pNodes, pn);
    stack_push(pStrings, node_getName(pn));

    //asignamos valores al segundo nodo
    node_setName(pn, "second");
    node_setId(pn, 222);
    node_setLabel(pn, WHITE);

    // insertamos el nodo en la pila de nodos, y su nombre en la pila de strings
    stack_push(pNodes, pn);
    stack_push(pStrings, node_getName(pn));

    //imprimimos pilas
    printf("Print Stack nodes:\n");
    stack_print(stdout, pNodes);

    printf("Print Stack string:\n");
    stack_print(stdout, pStrings);

    // liberamos el nodo
    node_free(pn);

    //imprimimos los nodos que sacamos de la pila
    printf("Poping nodes: ...\n");
    while ( stack_isEmpty(pNodes) == FALSE){
        pn = stack_pop(pNodes);
        node_print(stdout, pn);
        node_free(pn);
    }

    //imprimimos los strings que sacamos de la pila
    printf("\nPoping node-names: ...\n");
    while (stack_isEmpty(pStrings) == FALSE){
        aux = stack_pop(pStrings);
        printf("%s ", aux);
        free(aux);
    }
    printf("\n");
    node_free(pn);
    stack_free(pNodes);
    stack_free(pStrings);
    return 0;
}
