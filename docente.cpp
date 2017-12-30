#include "docente.h"
#include "buffer.h"
#include <iostream>
#include <string.h>

using namespace std;

docente* loadAllDocentes(const char* filePath){

  //A double linked list of type "docente"
  docente* docentes = NULL;

  if(filePath != NULL){
    //Load the docente.csv file into a Buffer File
    character* docenteCSV = createBufferFile(filePath);

    //Remove the first line of the text (it is useless)
    character* currentLine = removeFirstBufferLine(&docenteCSV);
    destroyBufferFile(&currentLine);

    //Create each "docente" based on the Buffer File
    while(currentLine = removeFirstBufferLine(&docenteCSV)){

      //Get docente's ID
      long id = stringToLong(getNthColumnData(currentLine, 1));
      //Get docente's name
      char* name = getNthColumnData(currentLine, 2);

      //Destroy the removed line (Only the text inside of it)
      destroyBufferFile(&currentLine);

      //Create a docente with the given data and add it to a list
      addDocente(&docentes, id, name);
    }
  }
  return docentes;
}

docente* createDocente(long id, char* name){
  docente* newDocente = NULL;
  newDocente = new docente[1];

  if(newDocente != NULL){
    newDocente->id = id;
    newDocente->name = name;
    newDocente->next = NULL;
    newDocente->prev = NULL;
    newDocente->last = NULL;
  }

  return newDocente;
}

void destroyDocente(docente* docenteToDestroy){
  //If the user actually pass a valid "docente"
  if(docenteToDestroy != NULL){
    delete[] docenteToDestroy;
  }
}

void addDocente(docente** docenteList, long id, char* name){

  //If the user actually pass a empty docenteList
  if(*docenteList != NULL){

    //Create a new docente
    docente* newDocente = createDocente(id, name);

    //Check if the new docente was allocated
    if(newDocente != NULL){

      //Check if the last docente was not set yet
      if((*docenteList)->last == NULL){

        //Iterate through docenteList until the its end
        docente* iterator = (*docenteList);
        while(iterator->next != NULL){
          iterator = iterator->next;
        }

        //Check if the docenteList is not at the middle of the list
        if((*docenteList)->prev == NULL){

          //Save the address of the last docente
          (*docenteList)->last = iterator;
        }else{
          //Save the address of the last docente
          docente* lastDocenteAddress = iterator;

          //Go back until the given docente as parameter
          iterator = (*docenteList);

          //Iterate through docenteList until the its head
          while(iterator->prev != NULL){
            iterator = iterator->prev;
          }

          //Save the address of the last docente
          iterator->last = lastDocenteAddress;
        }
      }

      //Insert the new docente at the docenteList
      newDocente->id = id;
      newDocente->name = name;
      newDocente->next = NULL;
      //Save the adress of the old last docente
      newDocente->prev = (*docenteList)->last;
      //Make the old last docente point to the new one
      (*docenteList)->last->next = newDocente;
      //Update the new last docente
      (*docenteList)->last = newDocente;
    }
  }else{
    docente* newDocente = createDocente(id,name);
    newDocente->last = newDocente;
    *docenteList = newDocente;
  }
}

void destroyAllDocentes(docente** docentes){

  //If the user actually pass a valid double linked list of docente
  if(docentes != NULL){

    //Get the address of the first docente
    docente* iterator = *docentes;

    //Go to the end of the double linked list of docente
    while(iterator->next != NULL){
        iterator = iterator->next;
    }

    //Go to the start of the double linked list of docente
    while(iterator->prev != NULL){

      //Go backwards one docente
      iterator = iterator->prev;

      //Desalocate the docente that is after the current
      destroyDocente(iterator->next);
    }

    //Destroy the first docente (the only one remaing)
    destroyDocente(iterator);
    *docentes = NULL;
  }
}
