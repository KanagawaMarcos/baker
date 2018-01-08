#include "docente.h"
#include "buffer.h"
#include <iostream>
#include <string.h>

using namespace std;

// Function to do merge sort
docente* orderDocentes(docente* docentes){
    if (!docentes || !docentes->next)
        return docentes;
    docente* second = split(docentes);

    // Recur for left and right halves
    docentes = orderDocentes(docentes);
    second = orderDocentes(second);

    // Merge the two sorted halves
    return merge(docentes,second);
}

docente* split(docente* docentes){
    docente*fast = docentes,*slow = docentes;
    while (fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    docente*temp = slow->next;
    slow->next = NULL;
    return temp;
}

// Function to merge two linked lists
docente* merge(docente*first, docente*second){
    // If first linked list is empty
    if (!first)
        return second;

    // If second linked list is empty
    if (!second)
        return first;

    // Pick the smaller value
    if (first->totalPoints > second->totalPoints)    {
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }else{
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}


/*
docente* orderDocentes(docente* docentes){
  docente* ordedDocentes = NULL;
  if(docentes != NULL){
    docente* i = docentes;
    while(i->next != NULL){

      i = i->next;
    }
  }
  return orderDocentes;
}
*/

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
    newDocente->points = new int[22];
    for(int i=0;i<22;i++)
      newDocente->points[i] = 0;
    newDocente->next = NULL;
    newDocente->last = NULL;
    newDocente->prev = NULL;

  }

  return newDocente;
}

void destroyDocente(docente* docenteToDestroy){
  //If the user actually pass a valid "docente"
  if(docenteToDestroy != NULL){
    delete[]docenteToDestroy->points;
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
