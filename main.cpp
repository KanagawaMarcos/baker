#include <iostream>
#include <fstream>
#include "docente.h"
#include "periodico.h"
#include "buffer.h"
#include "producao.h"

using namespace std;

int main (int argv, char* argc[]){

    //Create a double linked list of all "docentes"
    docente* docentes = loadAllDocentes("csv/docentes.csv");

    //Create an array with all capes values
    int* rules = loadAllRules("csv/regras/regraComp",22);

    //=========================================================================
    //Create a binary search tree of all "periodicos"
    //periodico* periodicos = loadAllPeriodicos("csv/qualis_capes_periodicos.csv");
    //=========================================================================

    //Load qualis_capes_periodicos.csv into memory
    character* producaoCSV = createBufferFile("csv/producao_V2.csv");
    character* currentLine = NULL;

    //Remove the file header
    currentLine = removeFirstBufferLine(&producaoCSV);

    int maxNodeNum = 20;

    producao* producaoBST = NULL;
    //Remove line by line from qualis_capes_periodicos.csv
    while(currentLine = removeFirstBufferLine(&producaoCSV)){

      //Get docente's ID
      long docenteId = stringToLong(getNthColumnData(currentLine, 1));

      //Get producao ID
      long id = stringToLong(getNthColumnData(currentLine, 2));

      //Get producao type
      char* type = getNthColumnData(currentLine, 3);

      //Get producao issn
      char* issn = getNthColumnData(currentLine, 4);

      //Get producao title
      char* title = getNthColumnData(currentLine, 5);

      //Get producao local
      char* local = getNthColumnData(currentLine, 6);

      //Get producao year
      int year = stringToInt(getNthColumnData(currentLine, 7));
      
      //Destroy the removed line (Only the text inside of it)
      destroyBufferFile(&currentLine);

      //Insert it in the BST
      insertProducao(&producaoBST,docenteId, id,  issn,  type,  title,  local,  year);
    }

    destroyBufferFile(&producaoCSV);
    destroyAllDocentes(&docentes);
    //destroyAllPeriodicos(&periodicos);



    return 0;

}
