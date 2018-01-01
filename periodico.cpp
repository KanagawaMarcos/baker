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
        if(i < 10){

          //Create the rule name
          char* qualis = new char[3];
          qualis[0] = ('0' + i);
          qualis[1] = ':';
          qualis[2] = '\0';

          //Save its value
          rulesTemporary[i] = getRuleValue(rulesTemporaryTXT,qualis);
          delete[] qualis;
        }
        if(i >= 10  && i < 20){

          //Create the rule name
          char* qualis = new char[4];
          qualis[0] = '1';
          qualis[1] = ('0' + (i-10));
          qualis[2] = ':';
          qualis[3] = '\0';

          //Save its value
          rulesTemporary[i] = getRuleValue(rulesTemporaryTXT,qualis);
          delete[] qualis;
        }
        if(i >= 20){

          //Create the rule name
          char* qualis = new char[4];
          qualis[0] = '2';
          qualis[1] = ('0' + (i-20));
          qualis[2] = ':';
          qualis[3] = '\0';

          //Save its value
          rulesTemporary[i] = getRuleValue(rulesTemporaryTXT,qualis);
          delete[] qualis;
        }
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
