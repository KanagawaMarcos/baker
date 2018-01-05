#ifndef PRODUCAO_H
  #define PRODUCAO_H

  typedef struct _producao{
    //Basic info extracted from the .csv file
    long docenteId;
    long id;
    char* issn;
    char* type;
    char* title;
    char* local;
    int year;

    //Atribute to baker know if this production was already used
    int isUsedAlready;

    //Character next to cur
    struct _producao* next;
    //Character previous to cur
    struct _producao* prev;
    //Last character of this buffer
    struct _producao* last;

    //BST atributes
    struct _producao* left;
    struct _producao* right;

  }producao;

  producao* getAllProducoesFromThatDocente(producao** producoes, long docenteId);

  producao* loadAllProducoes (const char* filePath);
  void postorderProducao(producao* producaoNode);
  void printProducoes(producao* producaoNode);

  void destroyAllProducoes(producao** producoes);
  void destroyProducao(producao** producao);

  producao* createProducao(
        long docenteId,
        long id,
        char* issn,
        char* type,
        char* title,
        char* local,
        int year
  );
  //void destroyProducao(producao* producaoToDestroy);
  void addProducao(producao** producaoList, long docenteId,
        long id,
        char* issn,
        char* type,
        char* title,
        char* local,
        int year
  );
  void insertProducao(producao** producaoTree, long docenteId,long id, char* issn, char* type, char* title, char* local, int year);


#endif
