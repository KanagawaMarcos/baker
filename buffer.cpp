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

  //If the user actually pass a empty string
  if(*string != NULL){

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
  }else{
    character* newString = createChar(data);
    newString->last = newString;
    *string = newString;
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
    *bufferFile = NULL;
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
  character* iterator = NULL;
  //If the user actually pass a valid buffer file
  if(*bufferFile != NULL){

    //Get the address of the current character
    iterator = *bufferFile;

    //Go until the head of the file (for safety)
    while(iterator->prev != NULL){
      iterator = iterator->prev;
    }

    //Go until the first ocurrence of '\n'
    while(iterator->next != NULL && iterator->data != '\n'){
        iterator = iterator->next;
    }

    //Save the address of the character after the last '\n' if exist
    if(iterator->next != NULL){
      *bufferFile = iterator->next;
    }else{
      *bufferFile = NULL;
    }

    //Remove the reference to new buffer file
    iterator->next = NULL;

    //If the line is not the last one
    if(*bufferFile != NULL){
      //Separete the buffer file from the old line
      (*bufferFile)->prev = NULL;
    }

    //Go back to the head of the line
    while(iterator->prev != NULL){
      iterator = iterator->prev;
    }
  }
  return iterator;
}



//Didn't make yet
//void removeQuotes(){};

character* getNthCommaData(character* bufferFile, int position){
  //A buffer line with a copy of the N position data
  character* nthText = NULL;

  if(bufferFile != NULL){
    if(position > 0){

      //The first character of the right data
      character* startPoint = NULL;
      //The last character of the right data
      character* finishPoint = NULL;

      int numberOfCommas = 0;

      //Go to the head of the bufferfile
      character* iterator = bufferFile;
      while(iterator->prev != NULL){
        iterator = iterator->prev;
      }

      //Make a backup of the first character address
      character* firstCharAddress = iterator;

      //Count the number of commas int the text
      while(iterator->next != NULL){
        if((iterator->data == ',') || (iterator->data == ';')){
          numberOfCommas++;
        }
        iterator = iterator->next;
      }
      cout << "number of commas: " << numberOfCommas << "\n";
      //If the number of open commas is equals to the closed
      if((numberOfCommas%2) == 0 ){

        iterator = firstCharAddress;
        int currrentCommaPos = 0;

        //Iterate through the text
        while(iterator->next != NULL){

          //Count, if the current char is a comma
          if((iterator->data == ',') || (iterator->data == ';')){
            currrentCommaPos++;
          }

          //If the current char is the first comma that we're looking for
          if(currrentCommaPos == ((position/2)-1)){
            startPoint = iterator->next;
          }

          //If the current char is the second comma that we're looking for
          if(currrentCommaPos == ((position/2))){
            finishPoint = iterator->prev;

            //The data is already marked, It's no longer need to iterate
            break;
          }
          iterator = iterator->next;
        }

        //Copy the data to return
        iterator = startPoint;
        while(iterator->next != NULL && iterator != finishPoint){
          addChar(&nthText, iterator->data);
          iterator = iterator->next;
        }

      }
    }
  }
  return nthText;
}
