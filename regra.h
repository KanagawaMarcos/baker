#ifndef REGRA_H
  #define REGRA_H

  typedef struct _regra{
    //Basic info given on the file
    char* qualis;
    int value;

    //Double linked list struct atributes
    struct _regra* next;
    struct _regra* prev;
    struct _regra* last;
  }regra;

  regra* createRegra(char* qualis, int value);
  void destroyRegra(regra* regraToDestroy);

  void addRegra(regra** regraList, char* qualis, int value);
  void destroyAllRegra(regra** regras);

  regra* loadAllRegras(const char* filePath);
#endif
