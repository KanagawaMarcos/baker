#include <iostream>
#include "regra.h"

using namespace std;

regra* createRegra(char* qualis, int value){
  regra* newRegra = NULL;
  newRegra = new regra[1];

  if(newRegra != NULL){
    newRegra->qualis = qualis;
    newRegra->value = value;
    newRegra->next = NULL;
    newRegra->prev = NULL;
    newRegra->last = NULL;
  }

  return newRegra;
}

void destroyRegra(regra* regraToDestroy){
  //If the user actually pass a valid "regra"
  if(regraToDestroy != NULL){
    delete[] regraToDestroy;
  }
}
