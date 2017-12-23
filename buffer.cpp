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
    delete charToDestroy;
  }
}

void addChar(character** string, char data){

  //If the user actually pass a valid string
  if(string != NULL){

    //Create a new character
    character* newChar = new character[1];

    //If the user actually pass a valid character
    if(newChar != NULL){

      //Check if the last character was not set yet
      if((*string)->last == NULL){

        //Check if the string is not a sub-string
        if((*string)->prev == NULL){

          //Iterate through string until the its end
          character* iterator = (*string);
          while(iterator->next != NULL){
            iterator = iterator->next;
          }

          //Save the address of the last character
          (*string)->last = iterator;
        }
      }

      //Insert the new character at the string
      newChar->data = data;
      newChar->next = NULL;
      //Save the adress of the old last character
      newChar->prev = (*string)->last;
      //Update the new last character
      (*string)->last = newChar;
    }
  }
}

/*
* @return: The first character of the BufferFile.
*/
character* createBufferFile(const char* filePath){

  //The first character of a Buffer File
  character* bufferFile = createChar('@');
  bufferFile->next = NULL;
  bufferFile->prev = NULL;
  bufferFile->last = NULL;
  bufferFile->isNumber = -1;

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

    //Skip the first character
    iterator = iterator->next;

    //While there is characters on the Buffer File
    while(iterator != NULL){

      //Print its text
      cout << iterator->data;

      //Go to the next character on the Buffer File
      iterator = iterator->next;
    }
  }
}
