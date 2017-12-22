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
  if(string != NULL){
    character* newChar = new character[1];
    if(newChar != NULL){
      //Va até o final a string
      character* iterator = (*string);
      while(iterator->next != NULL){
        iterator = iterator->next;
      }
      //adicione o novo character
      newChar->data = data;
      newChar->next = NULL;
      newChar->prev = iterator;
      iterator->next = newChar;
    }
  }
}

/*
* @return: The first character of the BufferFile.
*/
character* createBufferFile(const char* filePath){

  //The first character of a Buffer File
  character* bufferFile = createChar('@');

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

    /*
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
    */

  }
}

/*
* @return: 1 for sucess or a error code
*/
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
