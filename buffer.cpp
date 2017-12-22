#include "buffer.h"
#include <iostream>
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
* @parameters: The path, extension and name of the file.
* @return: The first character of the BufferFile.
*/
character* createBufferFile(const char* fileName){

  //The first character of a Buffer File
  character* bufferFile = createChar('@');

  //Create file a variable to read data from files
  ifstream file;

  //Trys to open the given file
  file.open(fileName);

  //Check if the file was open
  if(!file.is_open()){

    cerr << "Error while trying to open the file \"" << fileName << "\".";

  }else{

    //Create a temporary char to receive a file char by char
    char currentChar;

    //Iterate through file, char by char, without skip whitespaces
    while(file >> noskipws >> currentChar){
      addChar(&bufferFile, currentChar);
    }

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
* Se o char para destruir for o primeiro de um string:
* @return: a string sem ele
* Se o char estiver sozinho:
* @return: null
* Se o char estiver no meio de uma string ou no fim:
* @return null


character* destroyChar(character** charToDestroy){
  character* charAfterToDestroy = NULL;
  if(charToDestroy != NULL){
    character* tmp = NULL;
    //Caso ele esteja no meio ou fim de uma string
    tmp = charToDestroy->prev;
    if(tmp != NULL){
      previous->next = charToDestroy->next;
    }
    //Caso ele esteja no inicio
    tmp = charToDestroy->next;
    if(){

    }
  }
  return charAfterToDestroy;
}
*/
