#include <iostream>
#include <fstream>
#include "docente.h"
#include "periodico.h"
#include "buffer.h"

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
    character* periodicosCSV = createBufferFile("csv/qualis_capes_periodicos.csv");


    destroyBufferFile(&periodicosCSV);
    destroyAllDocentes(&docentes);
    //destroyAllPeriodicos(&periodicos);



    return 0;

}
