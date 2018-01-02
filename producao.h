#ifndef PRODUCAO_H
  #define PRODUCAO_H

  typedef struct _producao{
    //Basic info extracted from the .csv file
    long docenteId;
    long id;
    long issn;
    char* type;
    char* title;
    char* local;
    int year;

    //Character next to cur
    struct _producao* next;
    //Character previous to cur
    struct _producao* prev;
    //Last character of this buffer
    struct _producao* last;

  }producao;

  producao* createProducao(long docenteId,
        long id,
        long issn,
        char* type,
        char* title,
        char* local,
        int year
  );
  void destroyProducao(producao* producaoToDestroy);
  void addProducao(producao** producaoList, long docenteId,
        long id,
        long issn,
        char* type,
        char* title,
        char* local,
        int year
  );

#endif
