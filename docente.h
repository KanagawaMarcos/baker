#ifndef DOCENTE_H
  #define DOCENTE_H

  typedef struct _docente{
    long id;
    char* nome;
    struct _docente* proximo;
    struct _docente* anterior;
  }docente;

  docente* createDocente(long id, char* nome);

#endif
