#include "periodico.h"
#include "buffer.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

periodico* createPeriodico(char* issn, char* name, char*area, char* qualis){
  periodico* newPeriodico = NULL;
  newPeriodico = new periodico[1];

  if(newPeriodico != NULL){
    newPeriodico->issn = issn;
    newPeriodico->name = name;
    newPeriodico->area = area;
    newPeriodico->qualis = qualis;

    newPeriodico->value = 0;//qualisValue(qualis);
    newPeriodico->left = NULL;
    newPeriodico->right = NULL;
  }

  return newPeriodico;
}

int* loadAllRules(const char* filePath,int rulesNum){
  if(rulesNum <= 25){
    int amountOfRules = rulesNum + 1;
    int* rulesTemporary = NULL;
    int* rules = NULL;
    character* rulesTemporaryTXT = createBufferFile(filePath);

    //Create an array of rules values + 1
    rulesTemporary = new int[amountOfRules];

    //Create an array of the rules to return starting from 0
    rules = new int[rulesNum];

    if(rulesTemporary != NULL){

      //Look in each rule whitin the file(start at rule num 1)
      for(int i=1; i<amountOfRules;i++){

        character* iteratorChar = intToBufferString(i);
        character* colon = createChar(':');
        character* qualisBufferString = concatenate(&iteratorChar,&colon);
        char* qualis = bufferStringToString(qualisBufferString);

        //Save its value
        rulesTemporary[i] = getRuleValue(rulesTemporaryTXT,qualis);
        delete[] qualis;
      }
      destroyBufferFile(&rulesTemporaryTXT);

      //Copy and past the values to return
      for(int i=0; i<rulesNum;i++){
        rules[i] = rulesTemporary[i+1];
      }
      delete[] rulesTemporary;
      return rules;
    }
  }
}
