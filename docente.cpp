#include "docente.h"
#include <iostream>
#include <string.h>

using namespace std;

docente* createDocente(long id, char* name){
  docente* newDocente = NULL;
  newDocente = new docente[1];

  if(newDocente != NULL){
    newDocente->id = id;
    strcpy((newDocente->name),name); //??? strcpy = ponteiros?
    newDocente->next = NULL;
    newDocente->prev = NULL;
  }

  return newDocente;
}
