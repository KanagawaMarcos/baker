#include "buffer.h"
#include <iostream>
#include <string.h>

using namespace std;

character* createChar(char data){
  character* newCharacter = NULL;

  newCharacter = new character[1];

  if(newCharacter != NULL){
    newCharacter->data = data;
    newCharacter->isNumber = -1; //Default for "I dont know"
    newCharacter->next = NULL;
    newCharacter->prev = NULL;
  }

  return newCharacter;
}

void addChar(character** string, char data){
  if(string != NULL){
    character* newChar = new character[1];
    if(newChar != NULL){
      //Va até o final a string
      character* iterator = (*string);
      while(iterator->next != NULL){
        iterator = iterator->next;
      }
      //adicione o novo character
      newChar->data = data;
      newChar->next = NULL;
      newChar->prev = iterator;
      iterator->next = newChar;
    }
  }
}

/*
* Se o char para destruir for o primeiro de um string:
* @return: a string sem ele
* Se o char estiver sozinho:
* @return: null
* Se o char estiver no meio de uma string ou no fim:
* @return null


character* destroyChar(character** charToDestroy){
  character* charAfterToDestroy = NULL;
  if(charToDestroy != NULL){
    character* tmp = NULL;
    //Caso ele esteja no meio ou fim de uma string
    tmp = charToDestroy->prev;
    if(tmp != NULL){
      previous->next = charToDestroy->next;
    }
    //Caso ele esteja no inicio
    tmp = charToDestroy->next;
    if(){

    }
  }
  return charAfterToDestroy;
}
*/
