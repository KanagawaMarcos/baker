#include "producao.h"
#include "buffer.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;
producao* removeProducao(producao** allProducao){
  producao* lastProducao = NULL;

  if((*allProducao) != NULL){
    if((*allProducao)->last != NULL){

      //Make the last producao one producao before the current
      (*allProducao)->last = (*allProducao)->last->prev;
      //Save the old last address
      lastProducao = (*allProducao)->last->next;
      //Make the old last producao a unique node
      (*allProducao)->last->next->prev = NULL;
    }
  }

  return lastProducao;
}
producao* getAllProducoesFromThatDocente(producao** producoes, long docenteId){

    if((*producoes) != NULL){
      if(docenteId > -1){
        cout << docenteId << "==" << (*producoes)->docenteId << endl;
        if(docenteId == (*producoes)->docenteId){
          return (*producoes);
        }
        if(docenteId < (*producoes)->docenteId){
          return getAllProducoesFromThatDocente(&((*producoes)->left), docenteId);
        }
        if(docenteId > (*producoes)->docenteId){
          return getAllProducoesFromThatDocente(&((*producoes)->right), docenteId);
        }
      }
    }
    return NULL;
}

void printProducoes(producao* producaoNode){
  if(producaoNode != NULL){
    producao* iterator = producaoNode;
    while(iterator->next != NULL){
      cout << "\t" << iterator->title << endl;
      iterator = iterator->next;
    }
    cout << "\t" << iterator->title << endl;
  }
}

void postorderProducao(producao* producaoNode){
     if (producaoNode != NULL){

       // first recur on left subtree
       postorderProducao(producaoNode->left);

       // then recur on right subtree
       postorderProducao(producaoNode->right);

       // now print the current node title
       cout << producaoNode->docenteId << endl;
       printProducoes(producaoNode);
     }
}

void destroyAllProducoes(producao** producoes){
  //If the user actually pass a valid double linked list of docente
  if(*producoes != NULL){

    //Get the address of the first docente
    producao* iterator = *producoes;

    //Go to the end of the double linked list of docente
    while(iterator->next != NULL){
        iterator = iterator->next;
    }

    //Go to the start of the double linked list of docente
    while(iterator->prev != NULL){

      //Go backwards one docente
      iterator = iterator->prev;

      //Desalocate the docente that is after the current
      destroyProducao(&iterator->next);
    }

    //Destroy the first docente (the only one remaing)
    destroyProducao(&iterator);
    *producoes = NULL;
  }
}

void destroyProducao(producao** producao){
  if(*producao != NULL){
    if((*producao)->left == NULL){
      if((*producao)->right == NULL){
        if((*producao)->next == NULL){

          delete[] *producao;
        }
      }
    }
  }
  *producao = NULL;
}

producao* loadAllProducoes (const char* filePath){

  //Load qualis_capes_periodicos.csv into memory
  character* producaoCSV = createBufferFile(filePath);
  character* currentLine = NULL;

  //Remove the file header, it's useless
  currentLine = removeFirstBufferLine(&producaoCSV);
  destroyBufferFile(&currentLine);
  int maxNodeNum = 20;

  //A binary search tree for all producao data type (it use docenteId as key)
  producao* producaoBST = NULL;

  //Remove line by line from qualis_capes_periodicos.csv
  while(currentLine = removeFirstBufferLine(&producaoCSV)){
    //printBufferFile(currentLine);

    //Get docente's ID
    long docenteId = stringToLong(getNthColumnData(currentLine, 1));

    //Get producao ID
    long id = stringToLong(getNthColumnData(currentLine, 2));

    //Get producao type
    char* type = getNthColumnData(currentLine, 3);

    //Get producao issn
    char* issn = getNthColumnData(currentLine, 4);

    //Get producao title
    char* title = getNthColumnData(currentLine, 5);

    //Get producao local
    char* local = getNthColumnData(currentLine, 6);

    //Get producao year
    int year = stringToInt(getNthColumnData(currentLine, 7));

    //Destroy the removed line (Only the text inside of it)
    destroyBufferFile(&currentLine);

    //Insert it in the BST
    insertProducao(&producaoBST,docenteId, id,  issn,  type,  title,  local,  year);

  }
  return producaoBST;
}


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

    //Double linked list atributes
    newProducao->next = NULL;
    newProducao->prev = NULL;
    newProducao->last = NULL;

    //Binary Search Tree atributes
    newProducao->right = NULL;
    newProducao->left = NULL;

    //Baker atributes
    newProducao->isUsedAlready = 0;

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
