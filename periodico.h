#ifndef PERIODICO_H
  #define PERIODICO_H

  typedef struct _periodico{
    //Basic info given on the file
    char* issn;
    char* name;
    char* area;
    char* qualis;

    //Binary search tree struct atributes
    int value;
    struct _periodico* left;
    struct _periodico* right;
  }periodico;

  periodico* createPeriodico(long id, char* nome);
  void destroyPeriodico(periodico* periodicoToDestroy);

  void addPeriodico(periodico** tree, periodico* periodicoToAdd);
  void destroyAllPeriodicos(periodico** tree);

  docente* loadAllPeriodicos(const char* filePath);
#endif
