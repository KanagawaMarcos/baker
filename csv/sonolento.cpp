#include <iostream>
#include <string.h>

#define BUFFER_SIZE 257

using namespace std;


//======================Double Linked List===================
typedef struct _dlNode{
  struct _dlNode* next;
  struct _dlNode* previous;
  void* data;
}dlNode;

typedef struct _doubleLinkedList{
  dlNode* first;
}doubleLinkedList;

doubleLinkedList* dllCreate(){
  doubleLinkedList* newList = new doubleLinkedList[1];
  if(newList != NULL){
    newList->first = NULL;
  }
  return newList;
}

int dllEmptyDestroy(doubleLinkedList* list){
  int errorCode = 1;
  if(list == NULL){
    errorCode = -2;
  }else{
    if(list->first == NULL){
      errorCode = -3;
    }else{
      delete list;
    }
  }
  return errorCode;
}

void* dllRemoveLast(doubleLinkedList* list){
  void* lastDataCopy = NULL;
  if(list != NULL){
      if(list->first != NULL){
        //Create a iterator that start from begining of the list
        dlNode* iterator = list->first;

        //Go to the end of the list
        while(iterator->next != NULL){
          iterator = iterator->next;
        }

        //Make a copy from data of the last element
        lastDataCopy = iterator->data;

        //Fall back one element
        iterator = iterator->previous;

        //Delete de last element
        delete iterator->next;

        //Clean the next pointer of the last element
        iterator->next = NULL;
      }
  }
  return lastDataCopy;
}

int dllRemove(){

}

void dllAdd(doubleLinkedList* list, void* data){
  dlNode* newElement = NULL;
  if(list != NULL){
    if(list->first != NULL){
      //Create a iterator that start from begining of the list
      dlNode* iterator = list->first;

      //Go to the end of the list
      while(iterator->next != NULL){
        iterator = iterator->next;
      }

      newElement = new dlNode[1];
      if(newElement != NULL){
        newElement->previous = iterator;
        iterator->next = newElement;
        newElement->next = NULL;
        newElement->data = data;
      }
    }else{
      newElement = new dlNode[1];
      if(newElement != NULL){
        newElement->previous = NULL;
        list->first = newElement;
        newElement->next = NULL;
        newElement->data = data;
      }
    }
  }
}

int dllContains(){

}


//-----------------------------------------------------------


//=======================Structs CSV=========================

//<string.h>
typedef struct _docente{
  long id;
  char* name;
}docente;

docente* docenteNew (long id, char* name){
  //Create the new "docente"
  docente* createdDocente = NULL;
  if(id > 0 && name != NULL){
    //Alocate it
    createdDocente = new docente[1];

    if(createdDocente != NULL){
      //Fill it with the given data
      createdDocente->id = id;
      createdDocente->name = name;
    }
  }
  return createdDocente;
}

int docenteDestroy(docente* docenteToDestroy){
  int errorCode = 1;
  if(docenteToDestroy == NULL){
    errorCode = -2;
  }else{
    delete docenteToDestroy;
  }
  return errorCode;
}

//-----------------------------------------------------------


int main (int argv, char* argc[]){
  doubleLinkedList* dll_Docentes = NULL;
  dll_Docentes = dllCreate();

  long id;
  cout << "id:";
  cin >> id;

  char name[BUFFER_SIZE];
  cout << "nome: ";
  cin >> name;

  docente* geraldo = docenteNew(id, name);

  dllAdd(dll_Docentes, (void*)geraldo);

  docente* tmp = (docente*)dllRemoveLast(dll_Docentes);
  cout << "ID: " << tmp->id << endl;
  cout << "Nome: " << tmp->name << endl;



  return 0;
}
