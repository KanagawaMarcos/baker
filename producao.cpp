#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "buffer.h"

using namespace std;

producao* createProducao(long docenteId,long id, long issn, char* type, char* title, char* local, int year){
  producao* newProducao = NULL;

  newProducao = new producao[1];

  if(newProducao != NULL){

    //Actual data
    newProducao->docenteId = docenteId;
    newProducao->id = id;
    newProducao->issn = issn;
    newProducao->type = type;
    newProducao->title = title;
    newProducao->local = local;
    newProducao->year = year;

    //Structure atributes
    newProducao->next = NULL;
    newProducao->prev = NULL;
    newProducao->last = NULL;
  }

  return newProducao;
}

void destroyProducao(producao* producaoToDestroy){
  //If the user actually pass a valid producao
  if(producaoToDestroy != NULL){
    delete[] producaoToDestroy;
  }
}

void addProducao(producao** producaoList, long docenteId,long id, long issn, char* type, char* title, char* local, int year){

  //If the user actually pass a empty string
  if(*string != NULL){

    //Create a new character
    character* newChar = new character[1];

    //Check if the new character was allocated
    if(newChar != NULL){

      //Check if the last character was not set yet
      if((*string)->last == NULL){

        //Iterate through string until the its end
        character* iterator = (*string);
        while(iterator->next != NULL){
          iterator = iterator->next;
        }

        //Check if the string is not a sub-string
        if((*string)->prev == NULL){

          //Save the address of the last character
          (*string)->last = iterator;
        }else{
          //Save the address of the last character
          character* lastCharacterAddress = iterator;

          //Go back until the given character as parameter
          iterator = (*string);

          //Iterate through string until the its head
          while(iterator->prev != NULL){
            iterator = iterator->prev;
          }

          //Save the address of the last character
          iterator->last = lastCharacterAddress;
        }
      }

      //Insert the new character at the string
      newChar->data = data;
      newChar->next = NULL;
      //Save the adress of the old last character
      newChar->prev = (*string)->last;
      //Make the old last character point to the new one
      (*string)->last->next = newChar;
      //Update the new last character
      (*string)->last = newChar;
    }
  }else{
    character* newString = createChar(data);
    newString->last = newString;
    *string = newString;
  }
}
