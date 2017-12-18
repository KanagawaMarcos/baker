#ifndef LISTA_H

  #define LISTA_H

  typedef struct _lista_ {
      int dado;
      struct _lista_ *prox;
  }lista;

  lista *criar(int dado);
  int inserirInicio(lista **cab, int dado);

  void imprimir(lista *cab);

  void desalocar(lista **cab);

  int remover(lista **cab, int dado);

#endif 
