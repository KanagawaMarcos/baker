#ifndef BUFFER_H
  #define BUFFER_H

  typedef struct _character{
    char data;
    int isNumber;
    struct _character* next;
    struct _character* prev;
  }character;

  character* createChar(char data);
  void addChar(character** string, char data);
  //int destroyChar(character* charToDestroy);
#endif
