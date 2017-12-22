#ifndef BUFFER_H
  #define BUFFER_H

  typedef struct _character{
    char data;
    int isNumber;
    struct _character* next;
    struct _character* prev;
  }character;

  character* createChar(char data);
  void destroyChar(character* charToDestroy);
  void addChar(character** string, char data);

  /*
  * A file buffer is a entire file loaded on
  * memory using the structure "character"
  * witch is a double linked list of char.
  */
  character* createBufferFile(const char* fileName);
  void destroyBufferFile(character** bufferFile);
  void printBufferFile(character* bufferFile);
#endif
