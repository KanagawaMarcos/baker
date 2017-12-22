#include <iostream>
#include <fstream>
#include <string.h>
#include "docente.h"
#include "buffer.h"

#define FLOW_SIZE 257

using namespace std;

int main (int argv, char* argc[]){
    ifstream docentesCSV;
    const char* arquivoNome = "csv/docentes.csv";
    docentesCSV.open(arquivoNome);

    if(docentesCSV.is_open()){

      char flowOfChar[FLOW_SIZE];
      character* string = createChar('-');

      //Itera pelas outras linhas
      while(docentesCSV >> flowOfChar){
        for(int i=0; i < strlen(flowOfChar); i++){
          addChar(&string, flowOfChar[i]);
        }
      }

      character* iterator = string;
      while(iterator != NULL){
        cout << iterator->data;
        iterator = iterator->next;
      }

    }else{
      cout << "falha ao abrir o arquivo \""
      << arquivoNome << "\""<< endl;
    }

    docentesCSV.close();
    return 0;
}
