#ifndef BUFFER_H
  #define BUFFER_H

  #include "producao.h"
  #include "docente.h"

  typedef struct _character{
    //The actual text whitin
    char data;
    //Flag to tell if the char is int
    int isNumber;

    //Character next to cur
    struct _character* next;
    //Character previous to cur
    struct _character* prev;
    //Last character of this buffer
    struct _character* last;
  }character;

  //A dictionary to see faster if a issn already happened
  typedef struct _dictionary{
    char* word; //it's issn
    int value;  //Value for its qualis

    //next node
    struct _dictionary* next;
    //previous node
    struct _dictionary* prev;
    struct _dictionary* last;

  }dictionary;

  int baker(docente** docentes, producao** producoes, int* rules, character* orientacoes, character* congressos, character* periodicos, char* curso);
  int qualisCodePeriodicosToInt(char* qualisCode ,int* rules);
  int qualisCodeCongressosToInt(char* qualisCode ,int* rules);

  dictionary* memoization(dictionary* dictionaryToSearch, char* word);
  void addDictionaryWord(dictionary** dictionaryToAdd, char* word, int value);
  dictionary* createDictionary(char* word,  int value);
  void destroyDictionary(dictionary** dictionary);
  void purgeDictionary(dictionary* dictionary);

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
  character* removeFirstBufferLine(character** bufferFile);
  character* find(character* bufferFile, char* string);
  character* findNth(character* bufferFile, char* string, int nth);
  character* concatenate(character** destination, character** stringToConcatenate);
  int numberOfLinesBufferFile(character* congressosCSV);

  char* bufferStringToString(character* string);
  character* intToBufferString(int integer);

  //Function to use whith .csv files
  char* getNthColumnData(character* bufferFile, int position);
  char* getNthColumnDataFromCur(character* bufferFile, int position);
  char* getNthColumnDataCongresso(character* bufferFile, int position);

  char* loadAreaAvaliacao(const char* filePath);
  int*  loadAllRules(const char* filePath,int rulesNum);



  //Function to use with the "rules files"
  int getRuleValue(character* bufferFile,char* qualis);
  void convertToUpperCase(char** string);
  long stringToLong(char* numberToConvert);
  int stringToInt(char* numberToConvert);
  char* convertToUpper(char* str);
  char* clean(char* string);
  char* clean2(char* string);
#endif
