#ifndef BUFFER_H
  #define BUFFER_H

  typedef struct doubleLinkedList{
    char text;
    struct doubleLinkedList* next;
    struct doubleLinkedList* previous;
  }character;

  character* createChar(char text);

  int addChar(character** string);

  int removeChar(character** string, char text);

  int removeCharAll(character** string, char text);

  int destroyString(character** string);

#endif
