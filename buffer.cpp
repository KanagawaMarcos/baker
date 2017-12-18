#include "buffer.h"
#include <iostream>
#include <string.h>

using namespace std;

//Create optimized character, witch is a Double Linked Node
character* createChar(char text){
  //Create a new character
  character* newCharacter = NULL;

  //Allocate a new character
  newCharacter = new character[1];

  //Fill the new character with the right data
  if(newCharacter != NULL){
    newCharacter->next = NULL;
    newCharacter->previous = NULL;
    newCharacter->text = text;
  }

  //Return the newCharacter or NULL if it was not allocated
  return newCharacter;
}

int destroyString(character** string){
  int errorCode = 0;
  return errorCode;
}
