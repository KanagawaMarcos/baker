//Everything behind this comma until another is the wanted data
if(numberOfCommas == position){

  //Count how many valid characters there's (Quotes are not valid)
  character* commaPosition = iterator;
  int numberOfChars = 0;

  //Go backwards one char, to ignore read the comma
  iterator = iterator->prev;
  while(iterator->prev != NULL){

    //everything before this quotes, belongs to other data
    if(iterator->data == ','){

      break;
    }

    //if the character is diferent of a quote
    if(iterator->data != '\"'){
      numberOfChars++;
    }
    iterator = iterator->prev;
  }
  //Alocate the string to receive each character
  nthText = new char[numberOfChars+1];
  //The extra char is for \0
  nthText[numberOfChars] = '\0';
  //The last valid character
  int i = (numberOfChars-1);

  //If the text was successfully allocated
  if(nthText != NULL){
    iterator = commaPosition->prev;
    while(iterator->prev != NULL){

      //Everything before this quotes, belongs to other data
      if(iterator->data == ','){
        break;
      }
      //if the character is diferent of a quote
      if(iterator->data != '"'){
        nthText[i] = iterator->data;
        i--;
      }
      iterator = iterator->prev;
    }

  }else{
    cerr << "Error: Function: getNthCommaData. Desc: error while allocating nthText." << endl;
  }

  //Make the iterator go back to the position where it was
  iterator = commaPosition;
  //End the function
  break;
}
