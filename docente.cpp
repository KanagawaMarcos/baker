#include "docente.h"
#include <iostream>
#include <string.h>

using namespace std;

docente* createDocente(long id, char* nome){
  docente* newDocente = NULL;
  newDocente = new docente[1];

  if(newDocente != NULL){
    newDocente->id = id;
    strcpy((newDocente->nome),nome); //??? strcpy = ponteiros?
    newDocente->proximo = NULL;
    newDocente->anterior = NULL;
  }

  return newDocente;
}
