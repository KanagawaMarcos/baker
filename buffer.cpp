#include "buffer.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

character* createChar(char data){
  character* newCharacter = NULL;

  newCharacter = new character[1];

  if(newCharacter != NULL){
    newCharacter->data = data;
    newCharacter->isNumber = -1; //Default for "I dont know"
    newCharacter->next = NULL;
    newCharacter->prev = NULL;
    newCharacter->last = NULL;
  }

  return newCharacter;
}

void destroyChar(character* charToDestroy){

  //If the user actually pass a valid character
  if(charToDestroy != NULL){
    delete[] charToDestroy;
  }
}

void addChar(character** string, char data){

  //If the user actually pass a valid string
  if(string != NULL){

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
  }
}

/*
* @return: The first character of the BufferFile.
*/
character* createBufferFile(const char* filePath){

  //Create file a variable to read data from files
  ifstream file;

  //Trys to open the given file
  file.open(filePath);

  //Check if the file was open
  if(!file.is_open()){

    cerr << "Error while trying to open the file \"" << filePath << "\".";

  }else{

    //Create a temporary char to receive a file char by char
    char currentChar;

    //Get the first character in the file
    file >> noskipws >> currentChar;

    //The first character of a Buffer File
    character* bufferFile = createChar(currentChar);

    //Iterate through file, char by char, without skip whitespaces
    while(file >> noskipws >> currentChar){

      //Add each char to buffer file
      addChar(&bufferFile, currentChar);
    }

    return bufferFile;
  }
}

void destroyBufferFile(character** bufferFile){

  //If the user actually pass a valid buffer file
  if(bufferFile != NULL){

    //Get the address of the first character
    character* iterator = *bufferFile;

    //Go to the end of the buffer file
    while(iterator->next != NULL){
        iterator = iterator->next;
    }

    //Go to the start of the buffer
    while(iterator->prev != NULL){

      //Go backwards one character
      iterator = iterator->prev;

      //Desalocate the character that is after the current
      destroyChar(iterator->next);
    }

    //Destroy the first character (the only one remaing)
    destroyChar(iterator);
  }
}

void printBufferFile(character* bufferFile){
  if(bufferFile != NULL){
    //Get the reference to the first character
    character* iterator = bufferFile;

    //While there is characters on the Buffer File
    while(iterator != NULL){
      //Print its text
      cout << iterator->data;

      //Go to the next character on the Buffer File
      iterator = iterator->next;
    }
  }
}

character* removeFirstBufferLine(character** bufferFile){
  //If the user actually pass a valid buffer file
  if(bufferFile != NULL){

    //Get the address of the first character
    character* iterator = *bufferFile;

    //Go until the first ocurrence of '\n'
    while(iterator->data != '\n'){
        iterator = iterator->next;
    }

    //Save the address of the character after the last '\n'
    character* newBufferFile = iterator->next;

    //Remove the reference to new buffer file
    iterator->next = NULL;

    //Destroy the line
    destroyBufferFile(bufferFile);

    *bufferFile = newBufferFile;

    return newBufferFile;
  }
}

character* removeCurBufferLine(character** bufferFile){
  character* lineToRemove = NULL;

  //Check if the buffer actually exist
  if(*bufferFile != NULL){

    //Check if it's the end of a line
    if(bufferFile->next == NULL){

      //Check if is a single character
      if(bufferFile->prev == NULL){
        lineToRemove = *bufferFile;
        *bufferFile = NULL;
        return lineToRemove;
      }

      /*
      //If there is some '\n' character before the current character
      if(findNthPrevious((*bufferFile)->prev, '\n',1) != NULL){

        //Go back until the first character after the last '\n' and save it
        lineToRemove = findNthPrevious((*bufferFile)->prev, '\n',1)->next;

        findNthPrevious((*bufferFile)->prev, '\n',1)->next = NULL;
        lineToRemove->prev = NULL;

        //Check if it's a single line
      }else{

        //
        lineToRemove =
      }
      */

    }
  }
  return lineToRemove;
}

/*
//If the user actually pass a valid buffer file
if(bufferFile != NULL){

  //Check if there is a valid character after the current character
  if((*bufferFile)->next != NULL){

    //Find the first past occurrence of '\n', save the character after it
    lineToRemove = findNthPrevious((*bufferFile)->prev, '\n',1)->next;

    //Change the previous character of the character after bufferFile to the character before lineToRemove
    (*bufferFile)->next->prev = lineToRemove->prev;

    //Make line a standalone line
    lineToRemove->prev = NULL;

    //Concatenate the text filling the removed line
    (*bufferFile)->next->prev->next = findNthNext(lineToRemove, '\n',1)->next;

    //Remove the end of the line for the rest of the text
    findNthNext(lineToRemove, '\n', 1)->next = NULL;
  }else{

    //Check if buffer file is the end of a string
    if((*bufferFile)->prev != NULL){

      //Find the first past occurrence of '\n', save the character after it
      lineToRemove = findNthPrevious((*bufferFile)->prev, '\n',1)->next;

      //Remove the line from the text
      findNthPrevious((*bufferFile)->prev, '\n', 1)->next = NULL;

      //Make line a standalone line
      lineToRemove->prev = NULL;
    }else{

      //If the user pass a single character
      lineToRemove = (*bufferFile);
      (*bufferFile) = NULL;
    }
  }

  //FAZ ELE VERIFICAR PRIMEIRO SE É UM CHARACTER UNICO E SÓ DEPOIS SE É \N
  //Check if the buffer is already at the end of the string
  if((*bufferFile)->data != '\n'){
    (*bufferFile) = findNthNext((*bufferFile), '\n', 1);
  }else{

  }
}
*/
