#include "periodico.h"
#include "buffer.h"
#include <iostream>

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

int* loadAllRules(int amountOfRules){
  if(amountOfRules <= 25){
    int* regras = NULL;
    character* regrasTXT = createBufferFile("csv/regras/regraComp");
    //Create an array of rules values
    regras = new int[amountOfRules];

    if(regras != NULL){

      //Look in each rule whitin the file
      for(int i=1; i<amountOfRules;i++){
        if(i < 10){

          //Create the rule name
          char* qualis = new char[3];
          qualis[0] = '0' + i;
          qualis[1] = ':';
          qualis[2] = '\0';

          //Save its value
          regras[i] = getRuleValue(regrasTXT,qualis);
          delete[] qualis;
        }
        if(i >= 10){

          //Create the rule name
          char* qualis = new char[4];
          qualis[0] = '1';
          qualis[1] = '0' + (i-10);
          qualis[2] = ':';
          qualis[3] = '\0';

          //Save its value
          regras[i] = getRuleValue(regrasTXT,qualis);
          delete[] qualis;
        }
      }
      destroyBufferFile(&regrasTXT);
    }
  }
}
