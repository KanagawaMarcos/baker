#include "producao.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "buffer.h"
using namespace std;

producao* createProducao(long docenteId,long id, char* issn, char* type, char* title, char* local, int year){
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

    newProducao->right = NULL;
    newProducao->left = NULL;

  }

  return newProducao;
}

void destroyProducao(producao* producaoToDestroy){
  //If the user actually pass a valid producao
  if(producaoToDestroy != NULL){
    delete[] producaoToDestroy;
  }
}

void addProducao(producao** list, long docenteId,long id, char* issn, char* type, char* title, char* local, int year){

  //If the user actually pass a empty list
  if(*list != NULL){

    //Create a new producao
    producao* newProducao = createProducao(docenteId, id,  issn,  type,  title,  local, year);

    //Check if the new producao was allocated
    if(newProducao != NULL){

      //Check if the last producao was not set yet
      if((*list)->last == NULL){

        //Iterate through list until the its end
        producao* iterator = (*list);
        while(iterator->next != NULL){
          iterator = iterator->next;
        }

        //Check if the list is not a sub-list
        if((*list)->prev == NULL){

          //Save the address of the last producao
          (*list)->last = iterator;
        }else{
          //Save the address of the last producao
          producao* lastproducaoAddress = iterator;

          //Go back until the given producao as parameter
          iterator = (*list);

          //Iterate through list until the its head
          while(iterator->prev != NULL){
            iterator = iterator->prev;
          }

          //Save the address of the last producao
          iterator->last = lastproducaoAddress;
        }
      }

      //Insert the new producao at the list
      newProducao->next = NULL;
      //Save the adress of the old last producao
      newProducao->prev = (*list)->last;
      //Make the old last producao point to the new one
      (*list)->last->next = newProducao;
      //Update the new last producao
      (*list)->last = newProducao;
    }
  }else{
    producao* newList = createProducao(docenteId, id,  issn,  type,  title,  local, year);
    newList->last = newList;
    *list = newList;
  }
}

void insertProducao(producao** producaoTree, long docenteId,long id, char* issn, char* type, char* title, char* local, int year){

  //If the tree is empty, return a new tree
  if((*producaoTree) == NULL){
    (*producaoTree) = createProducao(docenteId, id,  issn,  type,  title,  local,  year);
  }

  //If Im at the correct docente ID node at the BST
  if((*producaoTree)->docenteId == docenteId){
    addProducao(producaoTree ,docenteId, id, issn,  type,  title,  local, year);
  }else{

    //If the given producao belongs to a docente with a ID lesser the the current
    if((*producaoTree)->docenteId < docenteId){

      insertProducao(&((*producaoTree)->left), docenteId, id, issn,  type,  title,  local, year);

    //If the given producao belongs to a docente with a ID greater the the current
    }else if((*producaoTree)->docenteId > docenteId){

      insertProducao(&((*producaoTree)->right), docenteId, id, issn,  type,  title,  local, year);
    }
  }


}
