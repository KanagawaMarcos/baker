#include "lista.h"
#include <iostream>

using namespace std;

lista *criar(int dado) {
    lista *novo=NULL;
    novo = new lista[1];
    if (novo != NULL) {
        novo->dado = dado;
        novo->prox = NULL;
    }
    return novo;
}

int inserirInicio(lista **cab, int dado) {
    //Cria um novo nó na lista
    lista *novo = criar(dado);
    //Se o nó não foi alocado
    if(novo == NULL){
       return 0;
    }

    //Se o nó foi alocado, faça o novo
    // aponte pra antiga cabeça
    novo->prox = *cab;

    //Faz o ponteiro da  cabeça apontar pro novo nó
    *cab = novo;
    return 1;
}

void imprimir(lista *cab) {
    lista *temp = cab;

    while (temp !=NULL) {
        cout << ": " << temp->dado;
        temp= temp->prox;
    }
    cout << "\n";
}
void desalocar(lista **cab) {
    lista *aux;

    while (*cab != NULL) {
        aux = *cab;
        *cab = (*cab)->prox;
        delete []aux;
    }
    *cab = NULL;
}

int remover(lista **cab, int dado);
